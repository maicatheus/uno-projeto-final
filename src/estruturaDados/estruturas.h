#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_

    /* Estruturas gerais */

#define TAM_MAX_NOME 40
#define TAM_MAX_EMAIL 25


typedef struct{
   int chave;
   char nome[TAM_MAX_NOME];
   char email[TAM_MAX_EMAIL];
}Aluno;

typedef Aluno Info;

typedef enum {VERMELHO=0, AMARELO, AZUL, VERDE} Cores;
typedef enum {ZERO=0, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, PULA, INVERTE, COMPRA_DOIS} ValoresCor;
typedef enum {MUDA_COR, COMPRA_QUATRO} Especiais;

typedef struct{
    Cores cor;
    ValoresCor valorCor;
    Especiais especiais;
}Carta;

    /* Listas simples e pilhas*/

typedef struct nodo{
   Info info;
   struct nodo *prox;
}Nodo;

typedef struct nodoBaralho{
   Carta carta;
   struct nodoBaralho *prox;
}NodoBaralho;

    /* Listas duplas */

typedef struct nodoLEnc2{
   Info info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

#endif

