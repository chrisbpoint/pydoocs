cmake_minimum_required(VERSION 3.7)
project(pydoocs)

set(CMAKE_CXX_STANDARD 11)

set(INCLUDE ${VERSION}/include)
set(SRC ${VERSION}/src)

include_directories(${INCLUDE})
include_directories(clientlib)
include_directories(${PYTHON_INCLUDE_DIR})
include_directories(${NUMPY_INCLUDE_DIR})

link_directories(doocslibs)

add_library(pydoocs SHARED
        ${INCLUDE}/AbstractBaseBuilder.h ${SRC}/AbstractBaseBuilder.cc ${SRC}/AbstractBaseBuilder.tcc
        ${INCLUDE}/AbstractBaseException.h ${SRC}/AbstractBaseException.cc
        ${INCLUDE}/BooleanBuilder.h ${SRC}/BooleanBuilder.cc
        ${INCLUDE}/build_util.h ${SRC}/build_util.cc
        ${INCLUDE}/ByteArrayBuilder.h ${SRC}/ByteArrayBuilder.cc
        ${INCLUDE}/DoocsException.h ${SRC}/DoocsException.cc
        ${INCLUDE}/DoubleArrayBuilder.h ${SRC}/DoubleArrayBuilder.cc
        ${INCLUDE}/DoubleBuilder.h ${SRC}/DoubleBuilder.cc
        ${INCLUDE}/FloatArrayBuilder.h ${SRC}/FloatArrayBuilder.cc
        ${INCLUDE}/FloatBuilder.h ${SRC}/FloatBuilder.cc
        ${INCLUDE}/GspectrumBuilder.h ${SRC}/GspectrumBuilder.cc
        ${INCLUDE}/IfffBuilder.h ${SRC}/IfffBuilder.cc
        ${INCLUDE}/IiiiBuilder.h ${SRC}/IiiiBuilder.cc
        ${INCLUDE}/ImageBuilder.h ${SRC}/ImageBuilder.cc
        ${INCLUDE}/IntegerArrayBuilder.h ${SRC}/IntegerArrayBuilder.cc
        ${INCLUDE}/IntegerBuilder.h ${SRC}/IntegerBuilder.cc
        ${INCLUDE}/LongArrayBuilder.h ${SRC}/LongArrayBuilder.cc
        ${INCLUDE}/LongBuilder.h ${SRC}/LongBuilder.cc
        ${INCLUDE}/NamesBuilder.h ${SRC}/NamesBuilder.cc
        ${INCLUDE}/parse_util.h ${SRC}/parse_util.cc
        ${INCLUDE}/py_object_builder.h ${SRC}/py_object_builder.cc
        ${INCLUDE}/pydoocs.h ${SRC}/pydoocs.cc
        ${INCLUDE}/pydoocs_names.h ${SRC}/pydoocs_names.cc
        ${INCLUDE}/pydoocs_read.h ${SRC}/pydoocs_read.cc
        ${INCLUDE}/pydoocs_write.h ${SRC}/pydoocs_write.cc
        ${INCLUDE}/PyDoocsException.h ${SRC}/PyDoocsException.cc
        ${INCLUDE}/SpectrumBuilder.h ${SRC}/SpectrumBuilder.cc
        ${INCLUDE}/StringBuilder.h ${SRC}/StringBuilder.cc
        ${INCLUDE}/sync_util.h ${SRC}/sync_util.cc
        ${INCLUDE}/TdsArrayBuilder.h ${SRC}/TdsArrayBuilder.cc
        ${INCLUDE}/TextBuilder.h ${SRC}/TextBuilder.cc
        ${INCLUDE}/TsFloatArrayBuilder.h ${SRC}/TsFloatArrayBuilder.cc
        ${INCLUDE}/TsDoubleArrayBuilder.h ${SRC}/TsDoubleArrayBuilder.cc
        ${INCLUDE}/UstrArrayBuilder.h ${SRC}/UstrArrayBuilder.cc
        ${INCLUDE}/XyArrayBuilder.h ${SRC}/XyArrayBuilder.cc
        ${INCLUDE}/XyzsArrayBuilder.h ${SRC}/XyzsArrayBuilder.cc)

file(STRINGS VERSION VERSION)
add_definitions(-DVERSION="${VERSION}")
target_link_libraries(pydoocs libDOOCSapi.a libgul.a pthread ldap lber)
set_target_properties(pydoocs PROPERTIES PREFIX "" OUTPUT_NAME "pydoocs" LINKER_LANGUAGE C)
