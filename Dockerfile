FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG BASE_DEPENDENCIES_PIP="cpplint"
ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="pyhamcrest teamcity-messages"

WORKDIR /workdir

COPY CMakeLists.txt .

COPY python2 python2
COPY python3 python3
COPY tests tests

COPY CPPLINT.cfg .

COPY setup.py .
COPY VERSION .
COPY README.md .
COPY LICENSE .

RUN conda update -n base -c defaults conda && \
    pip install $BASE_DEPENDENCIES_PIP && \
    conda create -n python27 python=2.7 $DEPENDENCIES_CONDA && \
    source activate python27 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    conda create -n python35 python=3.5 $DEPENDENCIES_CONDA && \
    source activate python35 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    conda create -n python36 python=3.6 $DEPENDENCIES_CONDA && \
    source activate python36 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    conda create -n python37 python=3.7 $DEPENDENCIES_CONDA && \
    source activate python37 && pip install $DEPENDENCIES_PIP && \
    conda deactivate && \
    conda config --add channels http://doocspkgs.desy.de/pub/doocsconda/ && \
    apt-get update && apt-get install -y build-essential cmake libldap2-dev && \
    mkdir build
  
ENTRYPOINT ["/bin/bash", "-c"]
