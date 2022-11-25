FROM ubuntu:16.04

WORKDIR /app

COPY ./src .

WORKDIR /app/src

RUN apt update

RUN apt-get install gcc make rpcbind gdb -y

CMD [ "tail", "-f", "/dev/null" ]