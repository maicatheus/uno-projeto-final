#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/jogador.h"
#include "includes/uno.h"
#include "includes/cartas.h"

void efetuarJogada(Jogador* jogador, PilhaBaralho* mesa, StatusJogada* statusJogada) {

    printf("\n\nMESA:\n");
    mostrarCarta(mesa->topo->carta, -1);

    ListaEnc* maoDoJogador = jogador->mao;

    mostrarMao(jogador);

    int opc;
    int flgContinuar = 1;
    do {
        printf("\n\nEscolha uma carta para jogar:\n");
        scanf("%d", &opc);
        getchar();

        if (opc <= 0 || opc > maoDoJogador->numCartas) {
            printf("Número inválido. Escolha um número dentro do intervalo de cartas.\n");
            continue; 
        }

        NodoBaralho* nodoBaralhoJogador = buscarCartaBaralhoAPartirDoIndice(maoDoJogador, opc);
        Carta carta = nodoBaralhoJogador->carta;
        if (nodoBaralhoJogador == NULL) {
            printf("Carta não encontrada na mão do jogador.\n");
            continue; 
        }

        validarJogada(nodoBaralhoJogador, mesa->topo, statusJogada);
        if (statusJogada->jogadaPermitida) {
            removeCartaBaralhoAPartirDoIndice(maoDoJogador, opc);
            empilhaPilhaEnc(mesa, carta);
            flgContinuar = 0; // Indica que a jogada foi realizada com sucesso, encerrando o loop
        } else {
            printf("A carta escolhida não pode ser jogada nesta rodada.\n");
            continue; 
        }

    } while (flgContinuar);
}


void validarJogada(NodoBaralho* nodoBaralhoJogador, NodoBaralho* nodoBaralhoMesa, StatusJogada* statusJogada) {
    if (nodoBaralhoJogador->carta.valorCarta == nodoBaralhoMesa->carta.valorCarta || 
        nodoBaralhoJogador->carta.cor == nodoBaralhoMesa->carta.cor) {
        statusJogada->jogadaPermitida = 1;
    } else {
        statusJogada->jogadaPermitida = 0;   
    }


}


StatusJogada* contrutorStatusJogada(){
    StatusJogada *statusJogada = (StatusJogada*)malloc(sizeof(StatusJogada));
    if(statusJogada != NULL)
        statusJogada->jogadaEspecial = 0;
        statusJogada->jogadaPermitida = 0;
        statusJogada->jogadaSacana = 0;
        statusJogada->gameOver = 0;
    
    return statusJogada;
}
