#include <stdio.h>
#include <stdlib.h>
#include "includes/cartas.h"
#include "includes/uno.h"

const char* corANSI(Cores cor) {
    switch(cor) {
        case VERMELHO:
            return "\033[0;31m"; // Vermelho
        case AMARELO:
            return "\033[0;33m"; // Amarelo
        case AZUL:
            return "\033[0;34m"; // Azul
        case VERDE:
            return "\033[0;32m"; // Verde
        default:
            return "\033[0;35m"; // Roxo para especiais
    }
}

const char* corFundoANSI(Cores cor) {
    switch (cor) {
        case VERMELHO:
            return "\033[41m"; // Fundo Vermelho
        case AMARELO:
            return "\033[43m"; // Fundo Amarelo
        case AZUL:
            return "\033[44m"; // Fundo Azul
        case VERDE:
            return "\033[42m"; // Fundo Verde
        default:
            return "\033[45m"; // Fundo Roxo para especiais
    }
}

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
    const char* corTexto = corANSI(carta.cor); 
    const char* corFundo = corFundoANSI(carta.cor); 

    if (index == -1)
        printf("\t%s%-15s\033[0m | %-10s | %-7s\033[0m\n", corFundo, nomeCor(carta.cor), nomeValor(carta.valorCarta), nomeEspecial(carta.especiais));
    else
        printf("\t%s%-3d\033[0m %s%-10s | %-7s | %-7s\033[0m\n", corFundo, index, corTexto, nomeCor(carta.cor), nomeValor(carta.valorCarta), nomeEspecial(carta.especiais));
}

void mostrarCorEscolhida(StatusJogada* statusJogada) {
    const char* corTexto = corANSI(statusJogada->carta.cor); 
    const char* corFundo = corFundoANSI(statusJogada->carta.cor);

    // Imprime a cor escolhida com o fundo colorido
    printf("%s%sCor Escolhida: %s\033[0m\n", corFundo, corTexto, nomeCor(statusJogada->carta.cor));
}

void escolherCorPorTerJogadoCartaEspecial(StatusJogada* statusJogada) {
    printf("Escolha a cor da próxima jogada:\n");

    for (int cor = VERMELHO; cor <= VERDE; cor++) {
        const char* corTexto = corANSI(cor); 
        const char* corFundo = corFundoANSI(cor); 

        printf("%s%-3d\033[0m %s%-10s\033[0m\n", corFundo, cor, corTexto, nomeCor(cor));
    }

    int opc;
    scanf("%d", &opc);
    getchar();
    statusJogada->carta.cor = opc;
}
