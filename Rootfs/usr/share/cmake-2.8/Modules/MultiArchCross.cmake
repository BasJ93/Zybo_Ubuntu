#NB! the meaning of DEB_BUILD and DEB_HOST is same as in dpkg-architecture & autoconf, i.e.:
# BUILD - the system type where compilation is executed
# HOST  - the system type where results of the compilation will be executed
#
# We can reliably determine all variables with dpkg-architecture (take into account env overrides)
# however it will not be the indication that this was actually explicitely requested
#execute_process(dpkg-architecture -qDEB_BUILD_GNU_TYPE OUTPUT_VARIABLE CMAKE_DEB_BUILD_GNU_TYPE)
#execute_process(dpkg-architecture -qDEB_HOST_GNU_TYPE OUTPUT_VARIABLE CMAKE_DEB_HOST_GNU_TYPE)
#execute_process(dpkg-architecture -qDEB_HOST_MULTIARCH OUTPUT_VARIABLE CMAKE_DEB_HOST_MULTIARCH)
#execute_process(dpkg-architecture -qDEB_HOST_ARCH_OS  OUTPUT_VARIABLE CMAKE_DEB_HOST_ARCH_OS)

if(DEFINED ENV{DEB_BUILD_GNU_TYPE} AND DEFINED ENV{DEB_HOST_GNU_TYPE} AND DEFINED ENV{DEB_HOST_MULTIARCH} AND DEFINED ENV{DEB_BUILD_MULTIARCH} AND DEFINED ENV{DEB_HOST_ARCH_OS})
  set(CMAKE_DEB_BUILD_MULTIARCH $ENV{DEB_BUILD_MULTIARCH})
  set(CMAKE_DEB_HOST_MULTIARCH $ENV{DEB_HOST_MULTIARCH})
  set(CMAKE_DEB_BUILD_GNU_TYPE $ENV{DEB_BUILD_GNU_TYPE})
  set(CMAKE_DEB_HOST_GNU_TYPE  $ENV{DEB_HOST_GNU_TYPE})
  set(CMAKE_DEB_HOST_ARCH_OS $ENV{DEB_HOST_ARCH_OS})

  # NB! ${CMAKE_DEB_HOST_MULTIARCH}-gcc exists on the native system to
  # do native compilation (just a symlink to gcc)

  # TODO probably also needs to honor e.g. $ENV{CC}=gcc-4.6 and prefix
  # that with ${CMAKE_DEB_HOST_MULTIARCH}
  if(NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED ENV{CC})
    find_program(CMAKE_C_COMPILER ${CMAKE_DEB_HOST_GNU_TYPE}-gcc)
  endif()
  if(NOT DEFINED CMAKE_CXX_COMPILER AND NOT DEFINED ENV{CXX})
    find_program(CMAKE_CXX_COMPILER ${CMAKE_DEB_HOST_GNU_TYPE}-g++)
  endif()
  if(NOT DEFINED CMAKE_Fortran_COMPILER AND NOT DEFINED ENV{FC})
    find_program(CMAKE_Fortran_COMPILER ${CMAKE_DEB_HOST_GNU_TYPE}-gfortran)
  endif()

  if(NOT DEFINED CMAKE_LIBRARY_ARCHITECTURE)
    SET(CMAKE_LIBRARY_ARCHITECTURE ${CMAKE_DEB_HOST_MULTIARCH})
  endif()

  if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    SET(CMAKE_INSTALL_LIBDIR "lib/${CMAKE_LIBRARY_ARCHITECTURE}")
  endif()

  if(NOT DEFINED CMAKE_SYSTEM_NAME)
    if(CMAKE_DEB_HOST_ARCH_OS STREQUAL "linux-gnu")
      SET(CMAKE_SYSTEM_NAME Linux)
    endif()

    if(CMAKE_DEB_HOST_ARCH_OS STREQUAL "kfreebsd")
      SET(CMAKE_SYSTEM_NAME GNU/kFreeBSD)
    endif()
  endif()

  if(CMAKE_DEB_HOST_GNU_TYPE AND CMAKE_DEB_BUILD_GNU_TYPE)
    if(NOT ${CMAKE_DEB_HOST_GNU_TYPE} STREQUAL ${CMAKE_DEB_BUILD_GNU_TYPE})
      SET(CMAKE_CROSSCOMPILING TRUE)
      SET(PKG_CONFIG_EXECUTABLE ${CMAKE_DEB_HOST_GNU_TYPE}-pkg-config)
      if(NOT CMAKE_SCRIPT_MODE_FILE)
        # These really do not belong here, qtchooser should be able to pick the right qt (3rdparty, system, or cross)
        if (NOT TARGET Qt5::qmake)
          add_executable(Qt5::qmake IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qmake")
          set_target_properties(Qt5::qmake PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qmake")
        endif()
        if (NOT TARGET Qt5::moc)
          add_executable(Qt5::moc IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/moc")
          set_target_properties(Qt5::moc PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/moc")
        endif()
        if (NOT TARGET Qt5::rcc)
          add_executable(Qt5::rcc IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/rcc")
          set_target_properties(Qt5::rcc PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/rcc")
        endif()
        if (NOT TARGET Qt5::uic)
          add_executable(Qt5::uic IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/uic")
          set_target_properties(Qt5::uic PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/uic")
        endif()
        if (NOT TARGET Qt5::qdbuscpp2xml)
          add_executable(Qt5::qdbuscpp2xml IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qdbuscpp2xml")
          set_target_properties(Qt5::qdbuscpp2xml PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qdbuscpp2xml")
        endif()
        if (NOT TARGET Qt5::qdbusxml2cpp)
          add_executable(Qt5::qdbusxml2cpp IMPORTED AND COMMAND "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qdbusxml2cpp")
          set_target_properties(Qt5::qdbusxml2cpp PROPERTIES IMPORTED_LOCATION "/usr/lib/$ENV{DEB_BUILD_MULTIARCH}/qt5/bin/qdbusxml2cpp")
        endif()
      endif()
    endif()
  endif()
endif()
