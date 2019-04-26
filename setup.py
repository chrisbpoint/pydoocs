""" Setup file for building and distributing pydoocs packages. """
import os
import setuptools

import numpy
from numpy.distutils.misc_util import get_numpy_include_dirs


with open("VERSION") as f:
    VERSION = f.read()

with open("README.md") as f:
    README = f.read()

with open("LICENSE") as f:
    LICENSE = f.read()

SOURCES = ["AbstractBaseBuilder.cc", "AbstractBaseException.cc", "BooleanBuilder.cc", "build_util.cc",
           "ByteArrayBuilder.cc", "DoocsException.cc", "DoubleArrayBuilder.cc", "DoubleBuilder.cc",
           "FloatArrayBuilder.cc", "FloatBuilder.cc", "GspectrumBuilder.cc", "IfffBuilder.cc", "IiiiBuilder.cc",
           "ImageBuilder.cc", "IntegerArrayBuilder.cc", "IntegerBuilder.cc", "LongArrayBuilder.cc", "LongBuilder.cc",
           "NamesBuilder.cc", "parse_util.cc", "py_object_builder.cc", "pydoocs.cc", "pydoocs_names.cc",
           "pydoocs_read.cc", "pydoocs_write.cc", "PyDoocsException.cc", "SpectrumBuilder.cc", "StringBuilder.cc",
           "sync_util.cc", "TdsArrayBuilder.cc", "TextBuilder.cc", "TsFloatArrayBuilder.cc", "TsDoubleArrayBuilder.cc",
           "UstrArrayBuilder.cc", "XyArrayBuilder.cc", "XyzsArrayBuilder.cc"]

INCLUDE = os.environ["PY_VERSION"] + "/include/"
SRC = os.environ["PY_VERSION"] + "/src/"

PYDOOCS = setuptools.Extension("pydoocs", language="c++", extra_compile_args=["-std=c++11"],
                               include_dirs=[INCLUDE, SRC, "clientlib"] + get_numpy_include_dirs(),
                               library_dirs=["doocslibs"], libraries=["pthread", "ldap", "lber"],
                               extra_objects=["doocslibs/libDOOCSapi.a", "doocslibs/libgul.a"],
                               sources=[SRC + source for source in SOURCES])

setuptools.setup(name="pydoocs",
                 version=VERSION,
                 description="Python bindings to the standard DOOCS client API (C/C++)",
                 long_description=README,
                 author="Christopher Behrens",
                 author_email="christopher.behrens@desy.de",
                 url="https://github.com/chrisbpoint/pydoocs",
                 license=LICENSE,
                 ext_modules=[PYDOOCS],
                 install_requires=["numpy>=" + numpy.__version__])
