FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="teamcity-messages"

WORKDIR /workdir

COPY clientlib clientlib
COPY doocslibs doocslibs

COPY CMakeLists.txt .

COPY include include
COPY src src
#COPY test test
#COPY setup.py .
#COPY README.md .
#COPY LICENSE .


RUN apt-get update && apt-get install -y build-essential cmake && \
    mkdir build && cd build && cmake .. && make


ENTRYPOINT ["/bin/bash", "-c"]
