cmake_minimum_required (VERSION 2.6)
project(lambda)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

add_library(lambda INTERFACE)
target_include_directories(lambda INTERFACE lambda/)

add_executable(example examples/example.cpp)

target_link_libraries(example lambda)

install(TARGETS lambda LIBRARY DESTINATION lib)
install(FILES lambda/lambda/lambda.hpp DESTINATION include/lambda)

install(FILES lambda-config.cmake DESTINATION lib/cmake/lambda)

