#include "includes/baralho.h"
#include "includes/lista_enc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaEnc* criaListaEnc(){
    ListaEnc *lista = (ListaEnc*)malloc(sizeof(ListaEnc));
    if (lista != NULL){
        lista->prim = NULL;
        lista->numCartas = 0;
    } 

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
    lista->numCartas++;
    return 1;
}

void listarLista(ListaEnc *lista) {
    int i=1;
    for(NodoBaralho *nodoBaralho = lista->prim; nodoBaralho != NULL; nodoBaralho = nodoBaralho->prox) {
        mostrarCarta(nodoBaralho->carta,i);
        i++;
    }
}

NodoBaralho* buscarCartaBaralhoAPartirDoIndice(ListaEnc* lista, int index){
    if(lista == NULL || index < 1 || index > lista->numCartas)
        return NULL;

    NodoBaralho* nodoBaralho = lista->prim;
    
    for(int i = 1; i < index; i++){
        if(nodoBaralho == NULL) 
            return NULL; 
        nodoBaralho = nodoBaralho->prox;
    }

    return nodoBaralho;
}

int removeCartaBaralhoAPartirDoIndice(ListaEnc* lista, int index){
    if(lista == NULL || lista->prim == NULL || index < 1 || index > lista->numCartas)
        return 0;

    NodoBaralho *anterior = NULL;
    NodoBaralho *atual = lista->prim;
    int cont = 1;

    while(cont < index){
        anterior = atual;
        atual = atual->prox;
        cont++;
    }

    if(anterior == NULL){
        lista->prim = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    lista->numCartas--;

    return 1;
}

