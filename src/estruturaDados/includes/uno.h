#include "jogador.h"
#include "cartas.h"
#include "pilha_enc.h"

#ifndef _UNO_H_
#define _UNO_H_


typedef struct statusJogada{
    int jogadaPermitida;
    int jogadaEspecial;
    int jogadaSacana;
    int gameOver;
    Carta carta;
} StatusJogada;

StatusJogada* contrutorStatusJogada();

void efetuarJogada(Jogador* jogador, PilhaBaralho* mesa, StatusJogada* statusJogada);

void validarJogada(NodoBaralho* nodoBaralhoJogador, NodoBaralho* nodoBaralhoMesa, StatusJogada* statusJogada);

int checarEspecialOuSacanas(StatusJogada* statusJogada);

void escolherCorPorTerJogadoCartaEspecial(StatusJogada* statusJogada);

void mostrarCorEscolhida(StatusJogada* statusJogada);
#endif