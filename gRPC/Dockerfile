FROM python:3.9.15-slim
WORKDIR /app

RUN apt update
RUN apt install nano git -y
RUN git clone -b v1.50.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc
RUN pip install --upgrade pip
RUN pip install grpcio grpcio-tools
COPY ./src ./wordcount

WORKDIR /app/wordcount

RUN python -m grpc_tools.protoc --proto_path ./proto --python_out=. --pyi_out=. --grpc_python_out=. ./proto/wordcount.proto

EXPOSE 8089

CMD [ "tail", "-f", "/dev/null" ]