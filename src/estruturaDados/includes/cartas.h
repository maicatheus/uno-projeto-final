#ifndef _CARTAS_H_
#define _CARTAS_H_


typedef enum {VERMELHO=1, AMARELO, AZUL, VERDE} Cores;
typedef enum {ZERO=1, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, PULA, INVERTE, COMPRA_DOIS} ValoresCor;
typedef enum {MUDA_COR=99, COMPRA_QUATRO=100} Especiais;

typedef struct carta{
    Cores cor;
    ValoresCor valorCarta;
    Especiais especiais;
} Carta;

const char* nomeCor(Cores cor);

const char* nomeEspecial(Especiais especial);

const char* nomeValor(ValoresCor valor);

void mostrarCarta(Carta carta, int index);
#endif