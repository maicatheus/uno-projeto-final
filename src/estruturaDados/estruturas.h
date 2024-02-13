#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_

/* Estruturas gerais */

#define TAM_MAX_NOME 40

typedef enum {VERMELHO=0, AMARELO, AZUL, VERDE} Cores;
typedef enum {ZERO=0, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, PULA, INVERTE, COMPRA_DOIS} ValoresCor;
typedef enum {MUDA_COR, COMPRA_QUATRO} Especiais;

typedef struct carta{
    Cores cor;
    ValoresCor valorCor;
    Especiais especiais;
} Carta;

typedef struct nodoBaralho{
   Carta carta;
   struct nodoBaralho *prox;
} NodoBaralho;

typedef struct jogador{
   char nome[TAM_MAX_NOME];
   NodoBaralho *mao;
   int disseUno;
   struct jogador *prox;
   struct jogador *ant;  
} Jogador;

#endif
