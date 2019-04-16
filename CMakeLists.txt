cmake_minimum_required(VERSION 3.10)
project(pydoocs)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/cbehrens/anaconda3/envs/python36/include/python3.6m/)
include_directories(/home/cbehrens/anaconda3/envs/python36/lib/python3.6/site-packages/numpy/core/include)

include_directories(clientlib)
include_directories(include)
include_directories(src)

link_directories(doocslibs)

add_library(pydoocs SHARED
        include/AbstractBaseBuilder.h
        include/AbstractBaseException.h
        include/BooleanBuilder.h
        include/build_util.h
        include/ByteArrayBuilder.h
        include/DoocsException.h
        include/DoubleArrayBuilder.h
        include/DoubleBuilder.h
        include/FloatArrayBuilder.h
        include/FloatBuilder.h
        include/GspectrumBuilder.h
        include/IfffBuilder.h
        include/IiiiBuilder.h
        include/ImageBuilder.h
        include/IntegerArrayBuilder.h
        include/IntegerBuilder.h
        include/LongArrayBuilder.h
        include/LongBuilder.h
        include/NamesBuilder.h
        include/parse_util.h
        include/py_object_builder.h
        include/pydoocs.h
        include/pydoocs_names.h
        include/pydoocs_read.h
        include/pydoocs_write.h
        include/PyDoocsException.h
        include/SpectrumBuilder.h
        include/StringBuilder.h
        include/sync_util.h
        include/TdsArrayBuilder.h
        include/TextBuilder.h
        include/TsFloatArrayBuilder.h
        include/TsDoubleArrayBuilder.h
        include/UstrArrayBuilder.h
        include/XyArrayBuilder.h
        include/XyzsArrayBuilder.h
        src/AbstractBaseBuilder.cc
        src/AbstractBaseBuilder.tcc
        src/AbstractBaseException.cc
        src/BooleanBuilder.cc
        src/build_util.cc
        src/ByteArrayBuilder.cc
        src/DoocsException.cc
        src/DoubleArrayBuilder.cc
        src/DoubleBuilder.cc
        src/FloatArrayBuilder.cc
        src/FloatBuilder.cc
        src/GspectrumBuilder.cc
        src/IfffBuilder.cc
        src/IiiiBuilder.cc
        src/ImageBuilder.cc
        src/IntegerArrayBuilder.cc
        src/IntegerBuilder.cc
        src/LongArrayBuilder.cc
        src/LongBuilder.cc
        src/NamesBuilder.cc
        src/parse_util.cc
        src/py_object_builder.cc
        src/pydoocs.cc
        src/pydoocs_names.cc
        src/pydoocs_read.cc
        src/pydoocs_write.cc
        src/PyDoocsException.cc
        src/SpectrumBuilder.cc
        src/StringBuilder.cc
        src/sync_util.cc
        src/TdsArrayBuilder.cc
        src/TextBuilder.cc
        src/TsFloatArrayBuilder.cc
        src/TsDoubleArrayBuilder.cc
        src/UstrArrayBuilder.cc
        src/XyArrayBuilder.cc
        src/XyzsArrayBuilder.cc)

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
