#include "lista.h"

// Cria lista vazia
Lista *cria_lista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));

  lista->prim = NULL;
  lista->ult = NULL;
  lista->tam = 0;
  printf("Lista criada com sucesso!!\n\n");

  return lista;
}

// Verifica se a lista está vazia
int vazia(Lista *li) {
  if (li->prim == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Obtém tamanho (e imprime lista)
int tamanho(Lista *li) {
  // Condições de falha
  if (li == NULL) {
    printf("A lista não existe\n");
    return -1;
  } else if (li->prim == NULL) {
    printf("A lista está vazia\n");
    return -1;
  }

  // imprime tamanho da lista
  printf("\nO tamanho atual da lista é: %d\n", li->tam);
  imprime_lista(li);

  return 0;
}

// Modifica elemento numa determinada posição da lista
int modifica_elemento(Lista *li, int val, int pos) {
  // Condições de falha
  if (li == NULL) {
    printf("A lista não existe\n");
    return -1;
  } else if (li->prim == NULL) {
    printf("A lista está vazia\n");
    return -1;
  }

  // Verifica se a posição é válida 
  if ((pos < 1) || (pos > li->tam)) {
    printf("A posição %d é inválida\n", pos);
    return -1;
  }

  // Auxiliar aponta para inicio da lista
  No *aux = li->prim;

  // Percorre as posições até chegar no elemento que sera alterado
  for (int i = 1; i < pos; i++) {
    aux = aux->prox;
  }

  int anterior = aux->info;

  // Altera o valor propriamente dito
  aux->info = val;

  printf("Valor anterior: %d\nNovo valor: %d\n", anterior, aux->info);

  return 0;
}

// Insere elemento numa determinada posição da lista
int insere_elemento(Lista *li, int val, int pos) {
  // Condições de falha
  if (li == NULL) {
    printf("A lista não existen\n");
    return -1;
  }

  // Verifica se a posição é válida 
  if ((pos < 1) || (pos > li->tam+1)) {
    printf("A posição %d é inválida\n", pos);
    return -1;
  }

  // Aloca memoria para novo nó na lista
  No *novo = (No *)malloc(sizeof(No));
  
  // Verifica se a nova alocação deu certo
  if (novo == NULL) {
    return -1;
  }
  // Atribui o valor para atributo do nó
  novo->info = val;

  // Inserção para caso a lista esteja vazia
  if (li->prim == NULL) {
    novo->prox = NULL; // O próximo do novo elemento se torna NULL
    li->prim = novo; // O ponteiro do início da lista aponta para o novo nó criado
    li->ult = novo;    // A lista só tem um elemento

    // Insere numa posição específica da lista
  } else {
    // Auxiliar aponta para inicio da lista
    No *aux = li->prim;

    // Inserir no inicio
    if (pos == 1) {
      li->prim = novo;
      novo->prox = aux;

      // Inserir no meio ou final
    } else {
      // Percorre as posições até chegar no elemento anterior a posição de inserção
      for (int i = 1; i < pos - 1; i++) {
        aux = aux->prox;
      }
      // Auxiliar 2 vai guardar o elemento da posicao a ser inserida
      No *aux2 = aux->prox;
      // Ponteiro para o próximo do aux passa a ser o novo elemento inserido
      aux->prox = novo;
      // Ponteiro para o próximo do novo passa a ser o auxliar guardado antes
      novo->prox = aux2;

      // Atualiza o ponteiro final, caso insira no ínicio
      if (pos == li->tam + 1) {
        li->ult = novo;
      }
    }
  }

  li->tam++;
  return 0;
}

// Remove elemento numa determinada posição da lista
int remove_elemento(Lista *li, int pos) {

 // Condições de falha
  if (li == NULL) {
    printf("A lista não existe\n");
    return -1;
  } else if (li->prim == NULL) {
    printf("A lista está vazia\n");
    return -1;
  }

  // Verifica se a posição é válida 
  if ((pos < 1) || (pos > li->tam)) {
    printf("A posição %d é inválida\n", pos);
    return -1;
  }

  // Aux aponta para inicio da lista
  No *aux = li->prim;

  // Remover do inicio
  if (pos == 1) {
    // Ponteiro para o início da lista passa a apontar para o próximo elemento
    li->prim = aux->prox;
    // Libera memoria eliminando elemento
    free(aux);

    // Remove no meio ou final
  } else {
    // Percorre as posições até chegar no elemento anterior a posição de remoção
    for (int i = 1; i < pos - 1; i++) {
      aux = aux->prox;
    }

    // Auxiliar 2 vai guardar o elemento da posição a ser removida
    No *aux2 = aux->prox;

    // O ponteiro prox do elemento aux passa a apontar para o ponteiro prox do que será removido (aux2)
    aux->prox = aux2->prox;

    // Libera memória do elemento a ser removido
    free(aux2);

    // Se a remoção é o ultimo elemento, atualiza fim para o aux2
    if (pos == li->tam) {
      li->ult = aux;
    }
  }

  li->tam--;
  return 0;
}

// 7) imprime lista
int imprime_lista(Lista *li) {
  
  if (li == NULL) {
    printf("\nA lista não existe\n");
    return 0;
  }

  if (li->prim == NULL) {
    printf("\nLista Vazia\n");
    return 0;
  }

  printf("\nElementos da Lista:\n");

  // Aux aponta para inicio da lista
  No *aux = li->prim;

  int i = 1; // indice do nó na lista
  
  // Percorre a lista imprimindo cada valor
  while (aux != NULL) {
    printf("Nó %d - Valor: %d\n", i, aux->info);
    i++;
    aux = aux->prox;
  }
  return 0;
}