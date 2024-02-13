#include "includes/baralho.h"
#include "includes/lista_circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Jogador* criaJogador(const char *nome) {
    Jogador *novoJogador = (Jogador*)malloc(sizeof(Jogador));
    if (novoJogador == NULL) {
        printf("Erro ao alocar memória para um novo jogador.\n");
        return NULL;
    }

    strncpy(novoJogador->nome, nome, TAM_MAX_NOME);
    novoJogador->nome[TAM_MAX_NOME - 1] = '\0'; 
   
    novoJogador->mao = NULL;
    novoJogador->disseUno = 0;

    novoJogador->prox = NULL;
    novoJogador->ant = NULL;

    return novoJogador;
}

void insereJogador(Jogador **primeiro, Jogador *novoJogador) {
    if (*primeiro == NULL) {
        *primeiro = novoJogador;
        novoJogador->prox = novoJogador; 
        novoJogador->ant = novoJogador;
    } else {
        Jogador *ultimo = (*primeiro)->ant; 

        ultimo->prox = novoJogador;
        novoJogador->ant = ultimo;

        novoJogador->prox = *primeiro; 
        (*primeiro)->ant = novoJogador;
    }
}

void imprimeJogadores(Jogador *primeiro) {
    if (primeiro == NULL) {
        printf("Não há jogadores na lista.\n");
        return;
    }

    Jogador *atual = primeiro;
    do {
        printf("Jogador: %s\n", atual->nome);
        // Aqui, você pode adicionar mais informações para imprimir, se necessário.
        atual = atual->prox;
    } while (atual != primeiro); // Continua até que a lista faça um ciclo completo
}

// // Funcao que cria uma lista
// ListaCircular* criaJogador(){
//    ListaCircular *lista = (ListaCircular*)malloc(sizeof(ListaCircular));
//    if (lista != NULL) // Idealmente, sempre checar!
//       lista->prim = NULL; // Representacao de lista vazia
//    return lista;
// }

// // Funcao que destroi uma lista
// void destroiListaCircular(ListaCircular *lista){
//    NodoBaralho *aux = lista->prim;
//    while(aux != NULL){
//        NodoBaralho *tmp = aux->prox;
//        free(aux); // Cuidar ordem do free
//        aux = tmp;
//    }
//    free(lista);
// }

// Funcao que imprime todos os nodos de uma lista
// void imprimeListaCircular(ListaCircular *lista){
//    NodoBaralho *aux;
//    printf("-----------------------------------------\n");
//    for(aux = lista->prim; aux != NULL; aux = aux->prox)
//       printf("%d | %d (%d)\n", aux->carta.cor,
//                                aux->carta.valorCor,
//                                aux->carta.especiais);
//    printf("-----------------------------------------\n");
// }

// Funcao que resgata um nodo com uma informacao de uma lista
// NodoBaralho* buscaInfoListaCircular(ListaCircular* lista, int chave){
//    NodoBaralho *aux;
//    for(aux = lista->prim; aux != NULL; aux = aux->prox)
//       if (aux->carta.chave == chave)
//          return aux;
//    return NULL;
// }

// Funcao que insere um nodo no inicio de uma lista
// int insereInicioListaCircular(ListaCircular *lista, Carta carta){
//    NodoBaralho *novo = (NodoBaralho*)malloc(sizeof(NodoBaralho));
//    if (novo == NULL) // Idealmente, sempre checar!
//       return 0;
//    novo->info = info;
//    novo->ant = NULL;
//    novo->prox = lista->prim;
//    if (lista->prim != NULL)
//       lista->prim->ant = novo;
//    lista->prim = novo;
//    return 1;
// }

// Funcao que remove um nodo com uma informacao de uma lista
// int removeInfoListaCircular(ListaCircular* lista, int chave){
//    NodoBaralho *aux = lista->prim;
//    while(aux != NULL && aux->carta.chave != chave){
//       aux = aux->prox;
//    }
//    if (aux != NULL){
//       if (aux->ant == NULL){
//          lista->prim = aux->prox;
//          if (aux->prox != NULL)
//             aux->prox->ant = NULL;
//       }else{
//          aux->ant->prox = aux->prox;
//          if (aux->prox != NULL)
//             aux->prox->ant = aux->ant;
//       }
//       free(aux);
//       return 1;
//    }
//    return 0; // Nao encontrou
// }

