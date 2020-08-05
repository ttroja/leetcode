cmake_minimum_required(VERSION 3.6)
project (test) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

#set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")
#set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install")
set(CMAKE_INSTALL_PREFIX "../install")

add_compile_options(-static-libstdc++)
add_compile_options(-fvisibility=hidden)

include_directories(include)

file(GLOB CPP_FILES ./src/*.cpp)

foreach(TEST_SOURCE ${CPP_FILES})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" TEST_NAME ${TEST_SOURCE})
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_link_libraries(${TEST_NAME} -pthread)
  install(TARGETS ${TEST_NAME} DESTINATION test)
endforeach(TEST_SOURCE ${CPP_FILES})