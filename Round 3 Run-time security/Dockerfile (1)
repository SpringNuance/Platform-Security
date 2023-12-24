FROM ubuntu:latest

RUN apt-get update && apt-get install -y gcc

WORKDIR /app

COPY typeconfusion.c /app

RUN gcc -o typeconfusion typeconfusion.c

CMD "./typeconfusion"