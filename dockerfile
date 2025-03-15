FROM ubuntu:latest

COPY . /cin_grupo2

RUN apt-get update && apt-get install -y \
    build-essential \
    tmux

WORKDIR /cin_grupo2

CMD make clean && make && clear && make run && /bin/bash