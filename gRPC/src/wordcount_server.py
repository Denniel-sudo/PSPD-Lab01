from concurrent import futures
import logging

import grpc
import wordcount_pb2
import wordcount_pb2_grpc


class WordCount(wordcount_pb2_grpc.WordCountServicer):
    def SendText(self, request, context):
        words = request.text.split()
        words_freq = {}

        for word in words:
            if word not in words_freq.keys():
                words_freq[word] = words.count(word)

        number_words = len(request.text.split())

        return wordcount_pb2.WordCountResponse(number_words=number_words, words_freq=words_freq)


def serve():
    port = '8089'
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    wordcount_pb2_grpc.add_WordCountServicer_to_server(WordCount(), server)
    server.add_insecure_port('[::]:' + port)
    server.start()
    print("Server started, listening on " + port)
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()