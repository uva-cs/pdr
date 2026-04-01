FROM ubuntu:bionic

LABEL "name"="Run make scripts and push changes"
LABEL "maintainer"="Winston Liu"
LABEL "version"="0.0.1"

LABEL "com.github.actions.name"="Run make scripts and push changes"
LABEL "com.github.actions.description"="Run `make all` to post-process all files and then push changes"
LABEL "com.github.actions.icon"="package"
LABEL "com.github.actions.color"="green"

RUN apt-get update > /dev/null && apt-get -yqq install git make pandoc astyle source-highlight > /dev/null

COPY entrypoint.sh /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
