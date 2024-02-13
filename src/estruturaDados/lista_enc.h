#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

typedef struct{
   struct nodo *prim;
}ListaEnc;

// Funcao que cria uma lista
ListaEnc* criaListaEnc();

// Funcao que destroi uma lista
void destroiListaEnc(ListaEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaEnc(ListaEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaEnc(ListaEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
Nodo* buscaInfoListaEnc(ListaEnc* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaEnc(ListaEnc* lista, int chave);

#endif
