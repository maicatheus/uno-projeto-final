#include "estruturas.h"
#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc* criaListaEnc(){
   ListaEnc *lista = (ListaEnc*)malloc(sizeof(ListaEnc));
   if (lista != NULL) // Idealmente, sempre checar!
      lista->prim = NULL; // Representacao de lista vazia
   return lista;
}

// Funcao que destroi uma lista
void destroiListaEnc(ListaEnc *lista){
   Nodo *aux = lista->prim;
   while(aux != NULL){
       Nodo *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc(ListaEnc *lista){
   Nodo *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %s (%s)\n", aux->info.chave,
                               aux->info.nome,
                               aux->info.email);
   printf("-----------------------------------------\n");
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc(ListaEnc *lista, Info info){
   Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
   if (novo == NULL) // Idealmente, sempre checar!
      return 0;
   novo->info = info;
   novo->prox = lista-> prim;
   lista->prim = novo;
   return 1;
}

// Funcao que resgata um nodo com uma informacao de uma lista
Nodo* buscaInfoListaEnc(ListaEnc* lista, int chave){
   Nodo *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.chave == chave)
         return aux;
   return NULL;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc(ListaEnc* lista, int chave){
   Nodo* ant = NULL;
   Nodo *aux = lista->prim;
   while(aux != NULL && aux->info.chave != chave){
      ant = aux;
      aux = aux->prox;
   }
   if (aux != NULL){
      if (ant == NULL)
         lista->prim = aux->prox;
      else
         ant->prox = aux->prox;
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}

