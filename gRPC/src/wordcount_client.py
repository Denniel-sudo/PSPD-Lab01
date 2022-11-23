from __future__ import print_function
from threading import Thread
import time
from Models.Utils import divide_file, read_file
import logging

import grpc
import wordcount_pb2
import wordcount_pb2_grpc

def request_to_worker(text, worker_ip, worker_port, responses):
    with grpc.insecure_channel(f'{worker_ip}:{worker_port}') as channel:
        stub = wordcount_pb2_grpc.WordCountStub(channel)
        response = stub.SendText(wordcount_pb2.WordCountRequest(text=text))
        responses.append(response)

def run():
    print("Dividing example.txt file...")
    divide_file()

    text1 = read_file(worker=1)
    text2 = read_file(worker=2)

    print("Will try to count words ...")

    threads = []
    responses = []

    thread = Thread(target=request_to_worker, args=(text2, 'grpc_worker2', 8089, responses))
    threads.append(thread)
    thread = Thread(target = request_to_worker, args=(text1, 'grpc_worker1', 8089, responses))
    threads.append(thread)

    for thread in threads:
        thread.start()
    
    for thread in threads:
        thread.join()

    number_words = 0
    words_freq = {}

    for response in responses:
        number_words = number_words + response.number_words
        words_freq.update(response.words_freq)

    print(f"WordCount received: {number_words}")
    for word in words_freq.keys():
        print(f"{word}: {words_freq[word]}")

if __name__ == '__main__':
    logging.basicConfig()
    run()