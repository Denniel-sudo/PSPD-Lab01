# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: wordcount.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0fwordcount.proto\" \n\x10WordCountRequest\x12\x0c\n\x04text\x18\x01 \x01(\t\"\x92\x01\n\x11WordCountResponse\x12\x14\n\x0cnumber_words\x18\x01 \x01(\x05\x12\x35\n\nwords_freq\x18\x02 \x03(\x0b\x32!.WordCountResponse.WordsFreqEntry\x1a\x30\n\x0eWordsFreqEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12\r\n\x05value\x18\x02 \x01(\x05:\x02\x38\x01\x32@\n\tWordCount\x12\x33\n\x08SendText\x12\x11.WordCountRequest\x1a\x12.WordCountResponse\"\x00\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'wordcount_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _WORDCOUNTRESPONSE_WORDSFREQENTRY._options = None
  _WORDCOUNTRESPONSE_WORDSFREQENTRY._serialized_options = b'8\001'
  _WORDCOUNTREQUEST._serialized_start=19
  _WORDCOUNTREQUEST._serialized_end=51
  _WORDCOUNTRESPONSE._serialized_start=54
  _WORDCOUNTRESPONSE._serialized_end=200
  _WORDCOUNTRESPONSE_WORDSFREQENTRY._serialized_start=152
  _WORDCOUNTRESPONSE_WORDSFREQENTRY._serialized_end=200
  _WORDCOUNT._serialized_start=202
  _WORDCOUNT._serialized_end=266
# @@protoc_insertion_point(module_scope)