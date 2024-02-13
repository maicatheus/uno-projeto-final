#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_
#include "cartas.h"

typedef struct{
   struct nodoBaralho *prim;
}ListaEnc;


// Funcao que cria uma lista
ListaEnc* criaListaEnc();

// Funcao que insere um nodo no inicio de uma lista
int insereListaEnc(ListaEnc *lista, Carta carta);

void listarLista(ListaEnc *lista);
// // Funcao que destroi uma lista
// void destroiListaEnc(ListaEnc *lista);

// // Funcao que imprime todos os nodos de uma lista
// void imprimeListaEnc(ListaEnc *lista);


// // Funcao que resgata um nodo com uma informacao de uma lista
// Nodo* buscaInfoListaEnc(ListaEnc* lista, int chave);

// // Funcao que remove um nodo com uma informacao de uma lista
// int removeInfoListaEnc(ListaEnc* lista, int chave);

#endif