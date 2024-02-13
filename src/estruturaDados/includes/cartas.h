#ifndef _CARTAS_H_
#define _CARTAS_H_


typedef enum {VERMELHO=0, AMARELO, AZUL, VERDE} Cores;
typedef enum {ZERO=0, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, PULA, INVERTE, COMPRA_DOIS} ValoresCor;
typedef enum {MUDA_COR, COMPRA_QUATRO} Especiais;

typedef struct carta{
    Cores cor;
    ValoresCor valorCor;
    Especiais especiais;
} Carta;

#endif