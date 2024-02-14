#include <stdio.h>
#include <string.h>
#include "estruturaDados/includes/baralho.h"
#include "estruturaDados/includes/cartas.h"
#include "estruturaDados/includes/lista_circular.h"
#include "estruturaDados/includes/pilha_enc.h"
#include "estruturaDados/includes/jogador.h"
#include "estruturaDados/includes/lista_enc.h"
#include "estruturaDados/includes/uno.h"
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
        getchar();

        if (numJogadores < 2 || numJogadores > 4) {
            printf("Número inválido de jogadores. Por favor, insira um número entre 2 e 4.\n");
        }
    } while (numJogadores < 2 || numJogadores > 4);

    Jogador *listaJogadores = NULL;

    for (int i = 0; i < numJogadores; i++) {
        char nomeJogador[TAM_MAX_NOME];
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", nomeJogador);
        getchar();


        Jogador *novoJogador = criaJogador(nomeJogador); 
        insereJogador(&listaJogadores, novoJogador); 

        ListaEnc *mao = criaListaEnc();
        for(int k=0; k<7; k++){
            Carta carta = desempilhaPilhaEnc(baralho);
            
            insereListaEnc(mao, carta);            
        }

        novoJogador->mao = mao;
    }
    
    StatusJogada* statusJogada = contrutorStatusJogada();

    Jogador *jogadorAtual = listaJogadores;
    PilhaBaralho * mesa = criaPilhaEnc();
    Carta cartaMesa;
    int flgSentidoHorario = 1;
    int flgPrimeiraRodada = 1;
    while(!statusJogada->gameOver){

        if(mesa->topo == NULL){
            Carta carta = desempilhaPilhaEnc(baralho);
            empilhaPilhaEnc(mesa,carta);
        }

        cartaMesa = mesa->topo->carta;

        int ehSacanaOuEspecial = checarEspecialOuSacanas(statusJogada);
        
        while(flgPrimeiraRodada){
            if(cartaMesa.especiais == MUDA_COR || cartaMesa.especiais == COMPRA_QUATRO ||
                cartaMesa.valorCarta == PULA || cartaMesa.valorCarta == INVERTE || 
                cartaMesa.valorCarta == COMPRA_DOIS){
                cartaMesa = desempilhaPilhaEnc(baralho);
                empilhaPilhaEnc(mesa,cartaMesa);
            }else
                flgPrimeiraRodada = 0;
        } 

        //IMPLEMENTAR =-=-=-=-=-=- DEVOLVER O COMPRA QUADRO PRO BARALHO SE FOR A CARTA
        if(ehSacanaOuEspecial){
            if(statusJogada->jogadaEspecial == 1){
                if(statusJogada->carta.especiais == COMPRA_QUATRO){
                    comprarCartas(jogadorAtual,baralho,mesa,4);

                }
            }
            if(statusJogada->jogadaSacana == 1){
                if(statusJogada->carta.valorCarta == COMPRA_DOIS){
                    comprarCartas(jogadorAtual,baralho,mesa,2);
                }

                if(statusJogada->carta.valorCarta == PULA)
                    jogadorAtual = jogadorAtual->prox;

                if(statusJogada->carta.valorCarta == INVERTE){
                    flgSentidoHorario = !flgSentidoHorario;
                    if(flgSentidoHorario)
                        jogadorAtual = jogadorAtual->prox->prox;
                    else
                        jogadorAtual = jogadorAtual->ant->ant;

                }
            }
        }
        efetuarJogada(jogadorAtual,mesa,baralho, statusJogada);
        printf("Aperte enter para continuar\n");
        getchar();
        if(flgSentidoHorario)
            jogadorAtual = jogadorAtual->prox;
        else
            jogadorAtual = jogadorAtual->ant;
    }
    return 0;
}
