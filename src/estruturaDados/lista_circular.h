#ifndef _LISTA_CIRUCLAR_H_
#define _LISTA_CIRUCLAR_H_

typedef struct ListaCircular{
   NodoBaralho *prim;
} ListaCircular;

// Funcao que cria uma lista
ListaCircular* criaListaCircular();

// Funcao que destroi uma lista
void destroiListaCircular(ListaCircular *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaCircular(ListaCircular *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaCircular(ListaCircular *lista, Carta carta);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoBaralho* buscaInfoListaCircular(ListaCircular* lista, int chave);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaCircular(ListaCircular* lista, int chave);

Jogador* criaJogador(const char *nome);

void insereJogador(Jogador **primeiro, Jogador *novoJogador);

void imprimeJogadores(Jogador *primeiro);
#endif
