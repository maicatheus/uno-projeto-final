#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/jogador.h"

void mostrarMao(Jogador* jogador){
    printf("Jogador %s:\n", jogador->nome);
    listarLista(jogador->mao);
}