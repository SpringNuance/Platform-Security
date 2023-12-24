FROM ubuntu:latest

RUN apt-get update && apt-get install -y gcc

WORKDIR /app

COPY stackoverflow.c /app

RUN gcc -o stackoverflow stackoverflow.c

CMD "./stackoverflow"