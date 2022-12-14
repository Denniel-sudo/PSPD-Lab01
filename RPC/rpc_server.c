/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpc.h"

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

  if (wf->words == NULL){
    wf->words = new_link;
    return;
  }

  last_link->next = new_link;
}

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

// Print do total de palavras
char *formatResponseWordTam(Words_freq *wf){
	char total_words[25] = "Total de palavras: ";
  char buffer_total[5];
	
	char *response = malloc(sizeof(char) * (wf->tam + 30));
  
  sprintf(buffer_total, "%d", wf->tam);
  strcat(total_words, buffer_total);
  strcat(total_words, "\n");
  strcat(response, total_words);

	return response;
}

char * formatResponseWordFreq(Words_freq *wf){
	word_freq_link *link = wf->words;

	char *response = malloc(sizeof(char) * (wf->tam * 30));

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

char *numDiffWords(Words_freq *wf, char *text){
  char *sub_str = strtok(text, " ");

  while(sub_str != NULL){
    exists(wf, sub_str);
    sub_str = strtok(NULL, " ");
    wf->tam++;
  }
}

void freeList(Words_freq *wf){
	word_freq_link *link = wf->words;
	while(link != NULL){
		wf->words = link->next;
		free(link);
		link = wf->words;
	}
	free(wf);
}

char **
words_freq_100_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;
	char *request = *argp;
	Words_freq *wf = initWF();

	numDiffWords(wf, request);

	result = formatResponseWordFreq(wf);
	freeList(wf);

	return &result;
}

char **
words_length_100_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;
	char *request = *argp;

	Words_freq *wf = initWF();

	numDiffWords(wf, request);

	result = formatResponseWordTam(wf);
	freeList(wf);

	return &result;
}
