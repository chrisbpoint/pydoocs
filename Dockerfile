FROM continuumio/miniconda3

SHELL ["/bin/bash", "-c"]

ARG DEPENDENCIES_CONDA="numpy conda-build"
ARG DEPENDENCIES_PIP="pyhamcrest teamcity-messages"

WORKDIR /workdir


COPY CMakeLists.txt .

COPY python2 python2
COPY python3 python3

COPY tests tests

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
