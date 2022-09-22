#include "lista.h"

int main(void) {
  
  Lista* lista;

  // Cria a lista
  lista = cria_lista();

  // Verifica se a lista está vazia
  if (vazia(lista)){
    printf("Lista vazia\n");
  } else printf("Não está vazia\n");

  // Insere o valor 20 na posição 1 e exibe o tamanho
  insere_elemento(lista, 20, 1);
  tamanho(lista);
  // Insere o valor 30 na posição 2 e exibe o tamanho
  insere_elemento(lista, 30, 2);
  tamanho(lista);
  // Insere o valor 40 na posição 1 e exibe o tamanho
  insere_elemento(lista, 40, 1);
  tamanho(lista);
  // Insere o valor 50 na posição 2 e exibe o tamanho
  insere_elemento(lista, 50, 2);
  tamanho(lista);
  // Insere o valor 60 na posição 3 e exibe o tamanho
  insere_elemento(lista, 60, 3);
  tamanho(lista);

  // Exibe a lista na tela
  imprime_lista(lista);
  printf("\n");
  // Modifica o elemento da posição 1 pelo valor 35
  modifica_elemento(lista, 35, 1);
  // Modifica o elemento da posição 2 pelo valor 45
  modifica_elemento(lista, 45, 2);
  // Modifica o elemento da posição 5 pelo valor 55
  modifica_elemento(lista, 55, 5);
  // Exibe a lista na tela
  imprime_lista(lista);
  // Remove o elemento da posição 1
  remove_elemento(lista, 1);
  // Exibe a lista na tela
  imprime_lista(lista);
  // Remove elemento posição 4
  remove_elemento(lista, 4);
  // Exibe a lista na tela
  imprime_lista(lista);

  // Verifica se a lista está vazia
  if (vazia(lista)){
    printf("\nLista vazia\n");
  } else printf("\nNão está vazia\n");
  
  return 0;
}