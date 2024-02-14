#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_
#include "cartas.h"
#include "baralho.h"

typedef struct{
   struct nodoBaralho *prim;
   int numCartas;
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


// Funcao que resgata um nodo com uma informacao de uma lista
NodoBaralho* buscarCartaBaralhoAPartirDoIndice(ListaEnc* lista, int index);

// Funcao que remove um nodo com uma informacao de uma lista
int removeCartaBaralhoAPartirDoIndice(ListaEnc* lista, int index);

#endif