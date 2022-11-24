#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_WORDS 654633

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

typedef struct parameters {
  char words[TAM_WORDS];
  int tam;
} parameters;

static word_freq_link newLink(char *str) {
  word_freq_link newLink = malloc(sizeof (struct word_freq));
  strcpy(newLink->word, str);
  newLink->freq = 1;

  return newLink;
}

void exists(char *str, Words_freq wordFreq) {
  word_freq_link link = wordFreq->words->next;
  while (link != NULL) {
    if (strcmp(str, link->word) == 0) {
      link->freq += 1;
      return;
    }
    link = link->next;
  }
  
  word_freq_link new = newLink(str);
  new->next = wordFreq->words->next;
  wordFreq->words->next = new;
  wordFreq->tam += 1;
}

Words_freq numDiffWords(parameters params) {
  char *subStr;
  Words_freq wordsFreq = malloc(sizeof *wordsFreq);
  wordsFreq->words = malloc(sizeof(word_freq_link));
  wordsFreq->words->next = NULL;
  wordsFreq->tam = 0;

  subStr = strtok(params.words, " ");

  while(subStr != NULL) {
    exists(subStr, wordsFreq);
    subStr = strtok(NULL, " ");
  }

  return wordsFreq;
}

int main(int argc, char **argv) {
  FILE *arq;
  parameters params;
  char buffer[TAM_WORDS];
  int buffertTam;
  char path[100] = {"../../../gRPC/src/Models/example.txt"};

  //if (argc < 2) {
    //printf("Necessario passar caminho do arquivo de entrada\n");
    //return 0;
  //}

  arq = fopen(path, "r");
  if (arq == NULL) {
    printf("Erro na abertura de arquivo!\n");
    return 0;
  }
  
  buffertTam = fread(buffer, 1, TAM_WORDS, arq);

  if (buffertTam == 0) {
    printf("Arquivo vazio!\n");
    return 0;
  }

  int index = 0;
  for (int i = 0; i <= buffertTam; i++) {
    if ((buffer[i] >= 65 && buffer[i] <= 90) ||
        (buffer[i] >= 97 && buffer[i] <= 122) ||
        (buffer[i] == 32 && i < buffertTam)) {
      params.words[index++] = buffer[i];
    }
  }
  params.tam = index;
  
  Words_freq wordsFreq = numDiffWords(params);

  printf("Total de palavras: %d\n", wordsFreq->tam);

  word_freq_link link = wordsFreq->words->next;
  int count = wordsFreq->tam-1;
  while (link != NULL) {
    printf("i[%d] -> %s: %d\n", count, link->word, link->freq);
    count--;
    link = link->next;
  }

  return 0;
}
