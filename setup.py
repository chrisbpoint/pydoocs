""" TODO """
import os
from setuptools import setup, Extension

import numpy
from numpy.distutils.misc_util import get_numpy_include_dirs


DOOCS_DIR = "/export/doocs/"


def get_long_description_from(file_name):
    """ Utility function to read the README file. """
    return open(os.path.join(os.path.dirname(__file__), file_name)).read()


CLIENTLIB_INCLUDE_DIR = DOOCS_DIR + "lib/include/"
CLIENTLIB_LIBRARY_DIR = DOOCS_DIR + "lib/"

PYDOOCS = Extension("pydoocs",
                    include_dirs=["./include", "./src", CLIENTLIB_INCLUDE_DIR] + get_numpy_include_dirs(),
                    library_dirs=[CLIENTLIB_LIBRARY_DIR],

                    # dynamic linking
                    # runtime_library_dirs=[CLIENT_LIB_DIR],
                    # libraries=["DOOCSapi"],

                    # static linking
                    libraries=["pthread", "ldap", "lber"],
                    extra_objects=[CLIENTLIB_LIBRARY_DIR + "libDOOCSapi.a",
                                   CLIENTLIB_LIBRARY_DIR + "libgul.a"],

                    language="c++",
                    extra_compile_args=["-std=c++11"],
                    sources=["./src/AbstractBaseBuilder.cc",
                             "./src/AbstractBaseException.cc",
                             "./src/BooleanBuilder.cc",
                             "./src/build_util.cc",
                             "./src/ByteArrayBuilder.cc",
                             "./src/DoocsException.cc",
                             "./src/DoubleArrayBuilder.cc",
                             "./src/DoubleBuilder.cc",
                             "./src/FloatArrayBuilder.cc",
                             "./src/FloatBuilder.cc",
                             "./src/GspectrumBuilder.cc",
                             "./src/IfffBuilder.cc",
                             "./src/IiiiBuilder.cc",
                             "./src/ImageBuilder.cc",
                             "./src/IntegerArrayBuilder.cc",
                             "./src/IntegerBuilder.cc",
                             "./src/LongArrayBuilder.cc",
                             "./src/LongBuilder.cc",
                             "./src/NamesBuilder.cc",
                             "./src/parse_util.cc",
                             "./src/pydoocs.cc",
                             "./src/PyDoocsException.cc",
                             "./src/pydoocs_names.cc",
                             "./src/pydoocs_read.cc",
                             "./src/pydoocs_write.cc",
                             "./src/py_object_builder.cc",
                             "./src/SpectrumBuilder.cc",
                             "./src/StringBuilder.cc",
                             "./src/sync_util.cc",
                             "./src/TdsArrayBuilder.cc",
                             "./src/TextBuilder.cc",
                             "./src/TsFloatArrayBuilder.cc",
                             "./src/TsDoubleArrayBuilder.cc",
                             "./src/UstrArrayBuilder.cc",
                             "./src/XyArrayBuilder.cc",
                             "./src/XyzsArrayBuilder.cc"])

setup(name="pydoocs",
      ext_modules=[PYDOOCS],
      version="2.0.5",
      description="Python bindings to the standard DOOCS client API (C/C++)",
      author="Christopher Behrens",
      author_email="christopher.behrens@desy.de",
      url="http://doocs-git.desy.de/cgit/doocs/library/python/pydoocs.git",
      long_description=get_long_description_from("README.md"),
      install_requires=["numpy>=" + numpy.__version__])
