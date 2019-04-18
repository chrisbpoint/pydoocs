cmake_minimum_required(VERSION 3.10)
project(pydoocs)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(src)
include_directories(clientlib)

link_directories(doocslibs)

add_library(pydoocs SHARED
        include/hello.h
        src/hello.cpp)

# dynamic linking
#target_link_libraries(pydoocs DOOCSapi)

# static linking
target_link_libraries(pydoocs libDOOCSapi.a pthread ldap lber libgul.a)

set_target_properties(
        pydoocs
        PROPERTIES
        PREFIX ""
        OUTPUT_NAME "pydoocs"
        LINKER_LANGUAGE C)
