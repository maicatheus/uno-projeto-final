#include "includes/baralho.h"
#include "includes/lista_enc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaEnc* criaListaEnc(){
   ListaEnc *lista = (ListaEnc*)malloc(sizeof(ListaEnc));
   if (lista != NULL) // Idealmente, sempre checar!
      lista->prim = NULL; // Representacao de lista vazia
   return lista;
}

int insereListaEnc(ListaEnc *lista, Carta carta) {
    NodoBaralho *novoNodo = (NodoBaralho *)malloc(sizeof(NodoBaralho));
    if (novoNodo == NULL) {
        return 0;
    }

    novoNodo->carta = carta;
    novoNodo->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = novoNodo; 
    } else {
        novoNodo->prox = lista->prim;
        lista->prim = novoNodo;
    }
    return 1;
}

void listarLista(ListaEnc *lista) {
    for(NodoBaralho *nodoBaralho = lista->prim; nodoBaralho != NULL; nodoBaralho = nodoBaralho->prox) {
        mostrarCarta(nodoBaralho->carta);
    }
}