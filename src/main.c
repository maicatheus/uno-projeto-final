#include <stdio.h>
#include <string.h>
#include "estruturaDados/includes/baralho.h"
#include "estruturaDados/includes/pilha_enc.h"
#include "estruturaDados/includes/lista_circular.h"
#include "estruturaDados/includes/lista_enc.h"
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
    } while (numJogadores < 2 || numJogadores > 4);

    Jogador *listaJogadores = NULL;

    for (int i = 0; i < numJogadores; i++) {
        char nomeJogador[TAM_MAX_NOME];
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", nomeJogador);

        Jogador *novoJogador = criaJogador(nomeJogador); 
        insereJogador(&listaJogadores, novoJogador); 

        ListaEnc *mao = criaListaEnc();
        for(int k=0; k<7; k++){
            insereListaEnc(mao, desempilhaPilhaEnc(baralho));            
        }

        novoJogador->mao = mao;
    }

    imprimeJogadores(listaJogadores);
    
    Carta infoAux;
    int i = 0;
    while (!vaziaPilhaEnc(baralho)){
        infoAux = desempilhaPilhaEnc(baralho);
        printf("%d -> %d | %d (%d)\n",i+1, infoAux.cor, infoAux.valorCor, infoAux.especiais);
        i++;
    }

    int gameOver = 0;

    while(!gameOver){


    }
    return 0;
}
