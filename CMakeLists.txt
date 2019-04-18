cmake_minimum_required(VERSION 3.7)
project(pydoocs)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)
#include_directories(clientlib)
include_directories(${PYTHON_INCLUDE_DIR})
include_directories(${NUMPY_INCLUDE_DIR})

#link_directories(doocslibs)


add_library(pydoocs SHARED
        ${VERSION}/include/hello.h
        ${VERSION}/src/hello.cpp)

target_link_libraries(pydoocs )#libDOOCSapi.a libgul.a pthread ldap lber )

set_target_properties(
        pydoocs
        PROPERTIES
        PREFIX ""
        OUTPUT_NAME "pydoocs"
        LINKER_LANGUAGE C)

