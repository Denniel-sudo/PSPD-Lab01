from google.protobuf.internal import containers as _containers
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional

DESCRIPTOR: _descriptor.FileDescriptor

class WordCountRequest(_message.Message):
    __slots__ = ["text"]
    TEXT_FIELD_NUMBER: _ClassVar[int]
    text: str
    def __init__(self, text: _Optional[str] = ...) -> None: ...

class WordCountResponse(_message.Message):
    __slots__ = ["number_words", "words_freq"]
    class WordsFreqEntry(_message.Message):
        __slots__ = ["key", "value"]
        KEY_FIELD_NUMBER: _ClassVar[int]
        VALUE_FIELD_NUMBER: _ClassVar[int]
        key: str
        value: int
        def __init__(self, key: _Optional[str] = ..., value: _Optional[int] = ...) -> None: ...
    NUMBER_WORDS_FIELD_NUMBER: _ClassVar[int]
    WORDS_FREQ_FIELD_NUMBER: _ClassVar[int]
    number_words: int
    words_freq: _containers.ScalarMap[str, int]
    def __init__(self, number_words: _Optional[int] = ..., words_freq: _Optional[_Mapping[str, int]] = ...) -> None: ...
