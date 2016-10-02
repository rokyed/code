# Generate Tree API Glue code

# Before building Inexor we generate our serialization glue.
# Therefore we use Doxygen to output the AST in .xml files and parse those, looking for Shared Declarations.

# Run Doxygen
# add a target to generate API documentation with Doxygen
find_package(Doxygen)

if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to genarete our glue code.")
endif()
if (NOT DEFINED GLUEGEN_EXE)
  find_program(GLUEGEN_EXE gluecodegenerator)
endif()


# Add a gluecode generation run for the specified target.
# Also adds the gluecode intermediates to the source file list of the target.
#
# @param TARG specifies the postfix for the ...-{target}.gen.proto and ...-{target}.gen.hpp output.
# @param BUILDFLAGS specifies any additional build flags we want to specify for that target:
#        The argument of the tag is a list of macros of the form: name or name=definition (no spaces).
#        If the definition and the "=" are omitted, "=1" is assumed.
# @param TEMPLATES_DIR specifies the directory where the template files are which get used to generate the target specific gluecode.
# @param OUT_DIR specifies the dir where the .gen.proto and .gen.hpp files get spit out.
function(require_run_gluegen TARG BUILDFLAGS TEMPLATES_DIR OUT_DIR)
    set(doxyfile_in ${TEMPLATES_DIR}/doxygen-parser.conf.in) # TODO move this
    set(doxyfile ${OUT_DIR}/doxygen-parser.conf)

    set(DOXYGEN_XML_DIR ${OUT_DIR}/doxygen_gluegen_output)

    configure_file(${doxyfile_in} ${doxyfile}) # Generate doxygen config

    set(gluegen_out_cpp ${OUT_DIR}/RPCBindingandContext.gen.cpp)
    set(gluegen_out_proto ${OUT_DIR}/RPCTreeData.gen.proto)

    set(gluegen_template_cpp ${TEMPLATES_DIR}/RPCBindingandContext.gen.template.cpp)
    set(gluegen_template_proto ${TEMPLATES_DIR}/RPCTreeData.gen.template.proto)

    message(STATUS "Gluegen (for target ${TARG}) runs with command: "
                  " --template-proto " "${gluegen_template_proto}"
                  " --template-cpp " "${gluegen_template_cpp}"
                  " --out-proto " "${gluegen_out_proto}"
                  " --out-cpp " "${gluegen_out_cpp}"
                  " --namespace " "inexor::tree"
                  " --XML-AST-folder " "${DOXYGEN_XML_DIR}")

    set(GENERATED_FILES ${gluegen_out_cpp} ${gluegen_out_proto})

    # Generate RPC PROTOCOL API Headers/Sources

    # Before building Inexor we generate our serialization headers from
    # language independent .proto files

    set(RPC_FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

    set(protoc_in ${gluegen_out_proto})

    set(protoc_out_cc ${OUT_DIR}/RPCTreeData.gen.pb.cc ${OUT_DIR}/RPCTreeData.gen.grpc.pb.cc)
    set(protoc_out_h ${OUT_DIR}/RPCTreeData.gen.pb.h ${OUT_DIR}/RPCTreeData.gen.grpc.pb.h)


    set(GENERATED_FILES ${GENERATED_FILES} ${protoc_out_cc} ${protoc_out_h})
    # Tell CMake not to complain about missing files since they get generated:
    set_source_files_properties(${GENERATED_FILES} PROPERTIES GENERATED TRUE)
    target_sources(${targ} PUBLIC ${GENERATED_FILES}) # Add to targets source list.


    add_custom_command(
      COMMENT "Parsing code base for Shared Declarations and generate gluecode doing the networking."
      OUTPUT ${GENERATED_FILES}
      # clear folder containing intermediate files (the AST xml files) before, since we take the complete folder as input to the next stage.
      COMMAND ${CMAKE_COMMAND} -P ${MAINDIR}/cmake/clean_files_folders.cmake -DPATHS_TO_REMOVE="${DOXYGEN_XML_DIR}" "${doxyfile}" "${GENERATED_FILES}"

      # Parse the codebase using doxygen and output the AST (Abstract syntax tree) to xml files.
      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}

      # Run our in-house gluecode generator taking doxygens AST as input and generating .gen.proto and .gen.hpp for ${TARG}.
      COMMAND ${GLUEGEN_EXE}
      "--template-proto" "${gluegen_template_proto}"
      "--template-cpp" "${gluegen_template_cpp}"
      "--out-proto" "${gluegen_out_proto}"
      "--out-cpp" "${gluegen_out_cpp}"
      "--namespace" "inexor::tree"
      "--XML-AST-folder" "${DOXYGEN_XML_DIR}"

      # Invoke protoc compiler to generate the .gen.pb.h .gen.pb.cpp files from the .proto definition
      COMMAND ${PROTOC_EXE}
          --proto_path=${MAINDIR}
          --cpp_out=${MAINDIR}
          ${protoc_in}

      # same but for the GRPC additions (which does now generate the RPC logic in .gen.grpc.pb.cc)
      COMMAND ${PROTOC_EXE}
          --plugin=protoc-gen-grpc=${GRPC_EXE}
          --proto_path=${MAINDIR}
          --grpc_out=${MAINDIR}
          ${protoc_in}

       WORKING_DIRECTORY ${MAINDIR})

    add_custom_target(regenerate_gluecode_${TARG}
      COMMENT "Just removes the generated files to trigger a new generation of these on the next build of ${TARG}"
      COMMAND ${CMAKE_COMMAND} -P ${MAINDIR}/cmake/clean_files_folders.cmake -DPATHS_TO_REMOVE="${GENERATED_FILES}"
    )
    message(STATUS "gluegen will generate the following files: ${GENERATED_FILES}")
endfunction()

# Other:
# Hashing?
    # file(MD5 ${protoc_in} protofile_hash)
    # if(NOT(${protofile_hash_old} EQUAL ${protofile_hash}))
    # ..
    # set(protofile_hash_old ${protofile_hash} CACHE INTERNAL "")
    # endif()
# Make everything DEPENDS targetfile .. DEPENDS targetfile2.. (commands instead of targets)
