FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="teamcity-messages"



#COPY src src
#COPY test test
#COPY setup.py .
COPY README.md .
COPY LICENSE .

COPY clientlib clientlib
COPY doocslibs doocslibs

#COPY CMakeLists.txt .

ENTRYPOINT ["/bin/bash", "-c"]
