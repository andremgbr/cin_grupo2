FROM ubuntu:latest

COPY . .

RUN apt-get update && apt-get install -y \
    build-essential \
    tmux \