#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/jogador.h"
#include "includes/uno.h"
#include "includes/cartas.h"

void efetuarJogada(Jogador* jogador, PilhaBaralho* mesa, PilhaBaralho* baralho, StatusJogada* statusJogada) {
    int erro = 0;

    if (vaziaPilhaEnc(baralho)) {
        colocaMesaNoBaralho(mesa, baralho);
    }

    statusJogada->jogadaPermitida = 0;

    int opc;
    int flgContinuar = 0;
    do {
        printf("\033[2J\033[H");
        printf("\n\nMESA:\n");
        if (statusJogada->jogadaEspecial == 1)
            mostrarCorEscolhida(statusJogada);
        else
            mostrarCarta(mesa->topo->carta, -1);

        ListaEnc* maoDoJogador = jogador->mao;

        mostrarMao(jogador);
        mostrarOpcaoCompraBaralho();

        if (erro) { 
            printf("\033[1;31mErro: %s\033[0m\n", "Número inválido. Escolha um número dentro do intervalo de cartas ou 'c' para comprar.");
            erro = 0; 
        }

        printf("\n\nEscolha uma opcao: ");
        char input[2];
        scanf("%s", input);
        getchar();

        if (input[0] == 'c') {
            comprarCartas(jogador, baralho, 1);
            continue;
        }

        opc = atoi(input);
        if (opc <= 0 || opc > maoDoJogador->numCartas) {
            erro = 1; 
            continue;
        }

        NodoBaralho* nodoBaralhoJogador = buscarCartaBaralhoAPartirDoIndice(maoDoJogador, opc);
        Carta carta = nodoBaralhoJogador->carta;
        if (nodoBaralhoJogador == NULL) {
            erro = 1; 
            continue;
        }

        validarJogada(nodoBaralhoJogador, mesa->topo, statusJogada);

        if (statusJogada->jogadaPermitida) {
            removeCartaBaralhoAPartirDoIndice(maoDoJogador, opc);
            empilhaPilhaEnc(mesa, carta);
            flgContinuar = 1;
        } else {
            erro = 1;
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

int checarEspecialOuSacanas(StatusJogada* statusJogada){
    return statusJogada->jogadaEspecial == 1 || statusJogada->jogadaSacana == 1;
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

void mostrarOpcaoCompraBaralho(){
    printf("\t%-3s\t%-10s\t\n","c", "comprar uma ");
}
