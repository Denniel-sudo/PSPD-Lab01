#!/bin/bash

python -m grpc_tools.protoc --proto_path ./proto --python_out=. --pyi_out=. --grpc_python_out=. ./proto/wordcount.proto
python wordcount_client.py