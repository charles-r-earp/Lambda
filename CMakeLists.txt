cmake_minimum_required (VERSION 2.6)

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  if(NOT CMAKE_TOOLCHAIN_FILE)
    # it _must_ go before project() in order to work
    if(WIN32)
      set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
    else()
      set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Installation Directory")
    endif()
  else(NOT CMAKE_TOOLCHAIN_FILE)
    #Android: set output folder to ${CMAKE_BINARY_DIR}
    set( LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_BINARY_DIR} CACHE PATH "root for library output, set this to change where android libs are compiled to" )
    # any crosscompiling
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
  endif(NOT CMAKE_TOOLCHAIN_FILE)
endif()

project(lambda)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

include_directories(include)

add_subdirectory(examples)

#add_library(lambda include/lambda examples/example.cpp)

install(FILES include/lambda include/lambda_internal DESTINATION include/lambda)
install(FILES lambda-config.cmake DESTINATION lib/cmake/lambda)
