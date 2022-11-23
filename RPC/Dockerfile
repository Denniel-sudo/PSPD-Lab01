FROM ubuntu:16.04

WORKDIR /app

RUN apt update

RUN apt-get install gcc make rpcbind -y

CMD [ "tail", "-f", "/dev/null" ]