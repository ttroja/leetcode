cmake_minimum_required(VERSION 3.6)
project (test) 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "CMAKE_BUILD_TYPE not set, use RelWithDebInfo")
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
elseif (CMAKE_BUILD_TYPE MATCHES "Release")  
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(CMAKE_INSTALL_PREFIX "../install")

add_compile_options(-static-libstdc++)
add_compile_options(-fvisibility=hidden)

include_directories(include)

file(GLOB CPP_FILES ./src/*.cpp)

foreach(TEST_SOURCE ${CPP_FILES})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" TEST_NAME ${TEST_SOURCE})
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  install(TARGETS ${TEST_NAME} DESTINATION test)
endforeach(TEST_SOURCE ${CPP_FILES})