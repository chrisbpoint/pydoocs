FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="teamcity-messages"

WORKDIR /workdir

#COPY clientlib clientlib
#COPY doocslibs doocslibs

COPY CMakeLists.txt .

COPY include include
COPY src src
#COPY test test
#COPY setup.py .
#COPY README.md .
#COPY LICENSE .


RUN conda update -n base -c defaults conda && \
    conda create -n python35 python=3.5 $DEPENDENCIES_CONDA \
    source activate python35 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    apt-get update && apt-get install -y build-essential cmake libldap2-dev && \    
    mkdir build
  
ENTRYPOINT ["/bin/bash", "-c"]
