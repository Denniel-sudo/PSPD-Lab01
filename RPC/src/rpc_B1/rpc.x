struct operandos {
  char words<>;
  int tam;
};
typedef struct word_freq *word_freq_link;
struct word_freq {
  char word[100];
  int freq;
  word_freq_link next;
};

typedef struct words_freq *Words_freq;
struct words_freq {
  word_freq_link words;
  int tam;
};
program PROG {
  version VERSAO {
    word_freq_link numDiffWords(operandos) = 1;
  } = 100;
} = 12121212;
