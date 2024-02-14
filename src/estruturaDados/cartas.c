#include <stdio.h>
#include <stdlib.h>
#include "includes/cartas.h"


const char* nomeCor(Cores cor) {
    switch(cor) {
        case VERMELHO:
            return "Vermelho";
        case AMARELO:
            return "Amarelo";
        case AZUL:
            return "Azul";
        case VERDE:
            return "Verde";
        default:
            return "Especial";
    }
}

const char* nomeValor(ValoresCor valor) {
    switch(valor) {
        case ZERO:
            return "Zero";
        case UM:
            return "Um";
        case DOIS:
            return "Dois";
        case TRES:
            return "Três";
        case QUATRO:
            return "Quatro";
        case CINCO:
            return "Cinco";
        case SEIS:
            return "Seis";
        case SETE:
            return "Sete";
        case OITO:
            return "Oito";
        case NOVE:
            return "Nove";
        case PULA:
            return "Pula";
        case INVERTE:
            return "Inverte";
        case COMPRA_DOIS:
            return "Compra Dois";
        default:
            return "---------";
    }
}

const char* nomeEspecial(Especiais especial) {
    switch(especial) {
        case MUDA_COR:
            return "Muda Cor";
        case COMPRA_QUATRO:
            return "Compra Quatro";
        default:
            return "Normal";
    }
}


void mostrarCarta(Carta carta, int index) {
    if(index == -1)
        printf("\t%-15s\t| %-10s\t| %-7s\n", nomeCor(carta.cor), nomeValor(carta.valorCarta), nomeEspecial(carta.especiais));
    else
        printf("\t%-3d\t%-10s\t| %-7s\t| %-7s\n",index, nomeCor(carta.cor), nomeValor(carta.valorCarta), nomeEspecial(carta.especiais));
}

