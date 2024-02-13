#include "lista_enc.h"
#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#define TAM_MAX_NOME 40

typedef struct jogador{
   char nome[TAM_MAX_NOME];
   ListaEnc *mao;
   int disseUno;
   struct jogador *prox;
   struct jogador *ant;  
} Jogador;


#endif