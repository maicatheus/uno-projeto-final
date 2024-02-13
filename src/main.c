#include <stdio.h>
#include <string.h>
#include "estruturaDados/estruturas.h"
#include "estruturaDados/pilha_enc.h"
#include "estruturaDados/lista_circular.h"
#include "raylib.h"



int main(){

    PilhaBaralho *baralho;
    baralho = criaPilhaEnc();
    inicializaBaralho(baralho);

    embaralhaPilhaEnc(baralho);

    int numJogadores = 0;
    do {
        printf("Quantos jogadores vão jogar? (entre 2 e 4): ");
        scanf("%d", &numJogadores);
        if (numJogadores < 2 || numJogadores > 4) {
            printf("Número inválido de jogadores. Por favor, insira um número entre 2 e 4.\n");
        }
    } while (numJogadores < 1 || numJogadores > 4);

    Jogador *listaJogadores = NULL;

    for (int i = 0; i < numJogadores; i++) {
        char nomeJogador[TAM_MAX_NOME];
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", nomeJogador);

        Jogador *novoJogador = criaJogador(nomeJogador);
        insereJogador(&listaJogadores, novoJogador); 
    }

    imprimeJogadores(listaJogadores);
    
    int gameOver = 0;

    while(!gameOver){


    }
    return 0;
}
