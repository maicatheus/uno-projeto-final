#include "includes/baralho.h"
#include "includes/pilha_enc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Funcao que cria uma pilha
PilhaBaralho* criaPilhaEnc(){
   PilhaBaralho *pilha = (PilhaBaralho*)malloc(sizeof(PilhaBaralho));
   if (pilha != NULL) // Idealmente, sempre checar!
      pilha->topo = NULL;
   return pilha;
}

// Funcao que inicializa as cartas do baralho
void inicializaBaralho(PilhaBaralho *baralho){
    Carta cartas[108];
    int j = 0,tamanhoBaralho = 0;

    for (int cor = VERMELHO; cor <= VERDE; cor++){
        for (int valor = ZERO; valor <= COMPRA_DOIS; valor++){
            cartas[tamanhoBaralho].cor = cor;
            cartas[tamanhoBaralho].valorCarta = valor;
            cartas[tamanhoBaralho].especiais = -1;
            tamanhoBaralho++;

            if (valor != ZERO){     // Zero tem apenas um por cor, enquanto os demais numeros tem dois
                cartas[tamanhoBaralho].cor = cor;
                cartas[tamanhoBaralho].valorCarta = valor;
                cartas[tamanhoBaralho].especiais = -1;
                tamanhoBaralho++;
            }
        }
    }

    for (int esp = MUDA_COR; esp <= COMPRA_QUATRO; esp++){     // Adicionando as cartas especiais
        for (int i = 0; i < 4; i++){
            cartas[tamanhoBaralho].cor = -1;
            cartas[tamanhoBaralho].valorCarta = -1;
            cartas[tamanhoBaralho].especiais = esp;
            tamanhoBaralho++;
        }
    }

    while (j != tamanhoBaralho){
        empilhaPilhaEnc(baralho, cartas[j]);
        j++;
    }
}


// Funcao que destroi uma pilha
void destroiPilhaEnc(PilhaBaralho *pilha){
   NodoBaralho *aux = pilha->topo;
   while(aux != NULL){
       NodoBaralho *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(pilha);
}

// Funcao que insere um elemento na pilha
void empilhaPilhaEnc(PilhaBaralho *pilha, Carta carta){
    NodoBaralho *novo = (NodoBaralho*)malloc(sizeof(NodoBaralho));
    if (novo != NULL){ // Idealmente, sempre checar!
    novo->carta = carta;
    novo->prox = pilha->topo;
    pilha->topo = novo;
   }
}



// Funcao que remove um elemento da pilha
Carta desempilhaPilhaEnc(PilhaBaralho* pilha){
    NodoBaralho *aux = pilha->topo;
/* Aqui assumimos que desempilha eh
   chamada apenas se a pilha nao eh vazia */
    Carta info = aux->carta;
    pilha->topo = aux->prox;
    free(aux);
    return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilhaEnc(PilhaBaralho *pilha){
   return (pilha->topo == NULL);
}

void embaralhaCartas(NodoBaralho *nodos[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        NodoBaralho *temp = nodos[i];
        nodos[i] = nodos[j];
        nodos[j] = temp;
    }
}

void embaralhaPilhaEnc(PilhaBaralho *pilha) {
    if (pilha == NULL || pilha->topo == NULL)
        return;

    int tamanho = 0;
    NodoBaralho *atual = pilha->topo;
    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }

    NodoBaralho *nodos[tamanho];

    atual = pilha->topo;
    for (int i = 0; i < tamanho; i++) {
        nodos[i] = atual;
        atual = atual->prox;
    }

    embaralhaCartas(nodos, tamanho);

    pilha->topo = NULL;
    for (int i = 0; i < tamanho; i++) {
        nodos[i]->prox = pilha->topo;
        pilha->topo = nodos[i];
    }
}

void colocaMesaNoBaralho(PilhaBaralho* mesa,PilhaBaralho* baralho){
    Carta cartaDeCimaDaMesa = desempilhaPilhaEnc(mesa);
    embaralhaPilhaEnc(mesa);

    while(!vaziaPilhaEnc(mesa)){
        Carta carta = desempilhaPilhaEnc(mesa);
        empilhaPilhaEnc(baralho,carta);
    }
    
    empilhaPilhaEnc(mesa,cartaDeCimaDaMesa);

}