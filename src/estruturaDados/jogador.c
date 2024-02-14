#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/jogador.h"

void mostrarMao(Jogador* jogador){
    printf("Jogador %s:\n", jogador->nome);
    listarLista(jogador->mao);
}

void comprarCartas(Jogador* jogador, PilhaBaralho* baralho, PilhaBaralho* mesa ,int numeroCartasParaComprar){
    for(int i = 0; i< numeroCartasParaComprar; i++){
        if(vaziaPilhaEnc(baralho))
            colocaMesaNoBaralho(mesa,baralho);

        insereListaEnc(jogador->mao,desempilhaPilhaEnc(baralho));
    }
}