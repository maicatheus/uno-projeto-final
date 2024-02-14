#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/jogador.h"
#include "includes/uno.h"
#include "includes/cartas.h"

void efetuarJogada(Jogador* jogador, PilhaBaralho* mesa, StatusJogada* statusJogada) {

    statusJogada->jogadaPermitida = 0;

    printf("\n\nMESA:\n");
    if(statusJogada->jogadaEspecial == 1)
        mostrarCorEscolhida(statusJogada);
    else
        mostrarCarta(mesa->topo->carta, -1);

    ListaEnc* maoDoJogador = jogador->mao;

    mostrarMao(jogador);

    int opc;
    int flgContinuar = 0;
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
            flgContinuar = 1;
        } else {
            printf("A carta escolhida não pode ser jogada nesta rodada.\n");
            continue; 
        }

    } while (!flgContinuar);
}


void validarJogada(NodoBaralho* nodoBaralhoJogador, NodoBaralho* nodoBaralhoMesa, StatusJogada* statusJogada) {

    if (statusJogada->jogadaEspecial == 1){
        if(nodoBaralhoJogador->carta.cor == statusJogada->carta.cor){
            statusJogada->jogadaPermitida=1;
        }
    }

    if (statusJogada->jogadaEspecial == 0){
        if (nodoBaralhoJogador->carta.valorCarta == nodoBaralhoMesa->carta.valorCarta || 
            nodoBaralhoJogador->carta.cor == nodoBaralhoMesa->carta.cor) {
                statusJogada->jogadaPermitida = 1;
                statusJogada->jogadaEspecial = 0;
                statusJogada->jogadaSacana = 0;
        }
        else {
            statusJogada->jogadaPermitida = 0;   
            statusJogada->jogadaEspecial = 0;
            statusJogada->jogadaSacana = 0;
        }
    }

    if (statusJogada->jogadaPermitida==1 &&
        (nodoBaralhoJogador->carta.valorCarta == PULA ||
        nodoBaralhoJogador->carta.valorCarta == INVERTE ||
        nodoBaralhoJogador->carta.valorCarta == COMPRA_DOIS)){
    
            statusJogada->jogadaPermitida = 1;
            statusJogada->jogadaEspecial = 0;
            statusJogada->jogadaSacana = 1;
            statusJogada->carta.valorCarta = nodoBaralhoJogador->carta.valorCarta;

    }



    if (nodoBaralhoJogador->carta.especiais == MUDA_COR ||
        nodoBaralhoJogador->carta.especiais == COMPRA_QUATRO){
            statusJogada->jogadaPermitida = 1;
            statusJogada->jogadaEspecial = 1;
            statusJogada->jogadaSacana = 0;
            statusJogada->carta.especiais = nodoBaralhoJogador->carta.especiais;
            escolherCorPorTerJogadoCartaEspecial(statusJogada);
    }
}

void escolherCorPorTerJogadoCartaEspecial(StatusJogada* statusJogada){
    int i = 1;
    for (int cor = VERMELHO; cor <= VERDE; cor++){
        printf("\t%-3d\t%-10s\t\n",i, nomeCor(cor));
        i++;
    }
    int opc;
    printf("Escolha a cor da proxima jogada:\n");
    scanf("%d", &opc);
    getchar();
    statusJogada->carta.cor=opc;
}

int checarEspecialOuSacanas(StatusJogada* statusJogada){
    return statusJogada->jogadaEspecial == 1 || statusJogada->jogadaSacana == 1;
}

void mostrarCorEscolhida(StatusJogada* statusJogada){
    printf("\nCor Escolhida: %s\n", nomeCor(statusJogada->carta.cor));
}

StatusJogada* contrutorStatusJogada(){
    StatusJogada *statusJogada = (StatusJogada*)malloc(sizeof(StatusJogada));
    if(statusJogada != NULL)
        statusJogada->jogadaEspecial = 0;
        statusJogada->jogadaPermitida = 0;
        statusJogada->jogadaSacana = 0;
        statusJogada->gameOver = 0;
        statusJogada->carta.cor = 0;
        statusJogada->carta.especiais =0;
        statusJogada->carta.valorCarta =0;
    
    return statusJogada;
}
