#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_
/* Estruturas gerais */
#include "cartas.h"
#include "lista_enc.h"
#include "jogador.h"


typedef struct nodoBaralho{
   Carta carta;
   struct nodoBaralho *prox;
} NodoBaralho;



#endif
