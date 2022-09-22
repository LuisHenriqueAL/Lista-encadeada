#ifndef LISTA_H_LISTA_
#define LISTA_H_LISTA


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  int info;                // Valor que quero armazenar
  struct elemento *prox; // Pponteiro para o proximo item da lista
} No;

typedef struct {
  No *prim;
  No *ult;
  int tam;
} Lista;

Lista *cria_lista();
int vazia(Lista *li);
int tamanho(Lista *li);
int modifica_elemento(Lista *li, int val, int pos);
int insere_elemento(Lista *li, int val, int pos);
int remove_elemento(Lista *li, int pos);
int imprime_lista(Lista *li);

#endif