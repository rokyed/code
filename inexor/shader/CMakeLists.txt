message(STATUS "Detecting Protobuf...")


declare_module(shader .)
add_lib(shader)

config_boost_wave(module_shader NOLINK)
config_SDL(module_shader NOLINK)

function(config_shader targ)
  message(STATUS "Configuring ${targ} with shader")
  if (";${ARGN};" MATCHES ";NOLINK;")
    set(NOLINK "NOLINK")
  endif()
  target_link_libs(${targ} module_shader ${NOLINK})

  config_boost_wave(${targ} ${NOLINK})
  config_SDL(${targ} ${NOLINK})

endfunction()

