#ifndef _PILHA_ENC_H_
#define _PILHA_ENC_H_

typedef struct pilhaEnc{
   Nodo *topo;
} PilhaEnc;

typedef struct pilhaBaralho{
   NodoBaralho *topo;
} PilhaBaralho;

// Funcao que cria uma pilha
PilhaBaralho* criaPilhaEnc();

// Funcao que inicializa as cartas do baralho
void inicializaBaralho(PilhaBaralho *baralho);

// Funcao que destroi uma pilha
void destroiPilhaEnc(PilhaBaralho *pilha);

// Funcao que insere um elemento na pilha
void empilhaPilhaEnc(PilhaBaralho *pilha, Carta carta);

// Funcao que remove um elemento da pilha
Carta desempilhaPilhaEnc(PilhaBaralho *pilha);

// Funcao que determina se uma pilha eh vazia
int vaziaPilhaEnc(PilhaBaralho* pilha);

void embaralhaPilhaEnc(PilhaBaralho *pilha);

#endif
