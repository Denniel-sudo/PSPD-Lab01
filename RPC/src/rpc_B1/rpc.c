#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_WORDS 654633

typedef struct word_freq {
  char word[100];
  int freq;
  struct word_freq *next;
} word_freq_link;


typedef struct list_words {
  struct word_freq *words;
  int tam;
} Words_freq;

typedef struct parameters {
  char words[TAM_WORDS];
  int tam;
} parameters;

Words_freq *initWF(){
  Words_freq *wf = malloc(sizeof(Words_freq));
  wf->words = NULL;
  wf->tam = 0;

  return wf;
}

void newWordLink(Words_freq *wf, word_freq_link *last_link, char *str) {
  word_freq_link *new_link = malloc(sizeof(word_freq_link));
  new_link->freq = 1;

  strcpy(new_link->word, str);
  new_link->next = NULL;

  wf->tam++;
  if (wf->words == NULL){
    wf->words = new_link;
    return;
  }

  last_link->next = new_link;
}

// static word_freq_link newLink(char *str) {
//   word_freq_link newLink = malloc(sizeof (struct word_freq));
//   strcpy(newLink->word, str);
//   newLink->freq = 1;

//   return newLink;
// }

void exists(Words_freq *wf, char *str){
  if (wf->words == NULL) {
    newWordLink(wf, wf->words, str);
    return;
  }

  word_freq_link *link = wf->words;

  while(link != NULL){
    if(strcmp(link->word, str) == 0){
      link->freq += 1;
      return;
    }

    link = link->next;
  }
  link = wf->words;

  while(link->next != NULL) link = link->next;
  newWordLink(wf, link, str);
}

void imprimirLista (Words_freq *wf) {
  word_freq_link *link = wf->words;

  while(link != NULL){
    printf("word: %s\nfreq: %d\n", link->word, link->freq);
    link = link->next;
  }
}

// void exists(char *str, Words_freq wordFreq) {
//   word_freq_link link = wordFreq->words->next;
//   while (link != NULL) {
//     if (strcmp(str, link->word) == 0) {
//       link->freq += 1;
//       return;
//     }
//     link = link->next;
//   }
  
//   word_freq_link new = newLink(str);
//   new->next = wordFreq->words->next;
//   wordFreq->words->next = new;
//   wordFreq->tam += 1;
// }

char *numDiffWords(Words_freq *wf, parameters params){
  char *sub_str = strtok(params.words, " ");

  while(sub_str != NULL){
    exists(wf, sub_str);
    sub_str = strtok(NULL, " ");
    // imprimirLista(wf);
  }

  char *response = malloc(sizeof(char) * (wf->tam * 101 + 30));

  char total_words[25] = "Total de palavras: ";
  char buffer_total[5];
  
  sprintf(buffer_total, "%d", wf->tam);
  strcat(total_words, buffer_total);
  strcat(total_words, "\n");
  strcat(response, total_words);

  word_freq_link *link = wf->words;

  while(link != NULL){
    char aux[10000];
    char buffer[10];

    strcpy(aux, link->word);
    strcat(aux, ": ");
    sprintf(buffer, "%d", link->freq);
    strcat(aux, buffer);
    strcat(aux, "\n");
    strcat(response, aux);

    link = link->next;
  }

  return response;
}

int main(int argc, char **argv) {
  FILE *arq;
  parameters params;
  char buffer[TAM_WORDS];
  int buffertTam;
  char path[100] = "./example.txt";

  Words_freq *wf = initWF();

  // Abre o arquivo example.txt
  arq = fopen(path, "r");
  if (arq == NULL) {
    printf("Erro na abertura de arquivo!\n");
    return 1;
  }
  
  // pega o tamanho máximo
  buffertTam = fread(buffer, 1, TAM_WORDS, arq);

  if (buffertTam == 0) {
    printf("Arquivo vazio!\n");
    return 0;
  }

  // percorre todo o arquivo
  int index = 0;
  for (int i = 0; i <= buffertTam; i++) {
    if ((buffer[i] >= 65 && buffer[i] <= 90) ||
        (buffer[i] >= 97 && buffer[i] <= 122) ||
        (buffer[i] == 32 && i < buffertTam)) {
      params.words[index++] = buffer[i];
    }
  }
  params.tam = index;

  char *response;

  response = numDiffWords(wf, params);

  printf("%s", response);
  
  // Words_freq wordsFreq = numDiffWords(params);

  // printf("Total de palavras: %d\n", wordsFreq->tam);

  // word_freq_link link = wordsFreq->words->next;
  // int count = wordsFreq->tam-1;
  // while (link != NULL) {
  //   printf("i[%d] -> %s: %d\n", count, link->word, link->freq);
  //   count--;
  //   link = link->next;
  // }

  return 0;
}
