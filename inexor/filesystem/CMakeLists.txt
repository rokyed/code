
add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
declare_module(filesystem .)
add_lib(filesystem)

config_sdl(module_filesystem NOLINK)

function(config_filesystem targ)
  message(STATUS "Configuring ${targ} with filesystem")
  if (";${ARGN};" MATCHES ";NOLINK;")
    set(NOLINK "NOLINK")
  endif()
  add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
  target_link_libs(${targ} module_filesystem ${NOLINK})

  config_sdl(${targ} ${NOLINK})
endfunction()
