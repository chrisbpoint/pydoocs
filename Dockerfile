FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="teamcity-messages"

WORKDIR /workdir

#COPY clientlib clientlib
#COPY doocslibs doocslibs

COPY CMakeLists.txt .

COPY python3/include python3/include
COPY python3/src python3/src
COPY python2/include python2/include
COPY python2/src python2/src

#COPY test test
#COPY setup.py .
#COPY README.md .
#COPY LICENSE .

RUN conda update -n base -c defaults conda && \
    conda create -n python35 python=3.5 $DEPENDENCIES_CONDA && \
    source activate python35 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    echo "placeholder for python 3.6 and 3.7" && \
    conda create -n python27 python=2.7 $DEPENDENCIES_CONDA && \
    source activate python27 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    apt-get update && apt-get install -y build-essential cmake libldap2-dev && \    
    mkdir build
  
ENTRYPOINT ["/bin/bash", "-c"]
