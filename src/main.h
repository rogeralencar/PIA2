#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include "controles.h"
#include "lista.h"
#include "pilha.h"
#include "jogador.h"
#include "interface.h"

extern const wchar_t *paus;
extern const wchar_t *espadas;
extern const wchar_t *copas;
extern const wchar_t *ouros;
extern char *valores[13];
extern int row, col;

typedef struct Lista_Estatica {
    struct Carta cartas[52];
    int nElementos;
} Lista_Estatica;

void inserirListaCircular(Lista *lista, Lista_Estatica *estatica, int indice);
No *recuperaInicio(Lista *lista);
No *desenfileira(Lista *lista);
void inserirElementos(Lista *lista, Lista *f);
No *cartasVisiveis(Lista *lista);
void inserirElementosNo(Lista *lista, No *n, Jogador *j);
void deletarElementos(Lista *lista);
void trocarElementos(Lista *lista, Lista *lista1, Jogador *j);
void apagarCartasVisiveis(Lista *lista);
void trocarElementosDeck(Lista *lista, Lista *lista1, Jogador *j);
void enfileiraFim(Lista *lista, No *no);
void inserirManilha(Pilha *p, Lista *lista, Jogador *j);
void inserirManilhaDireto(Pilha *p, Lista *lista, Jogador *j);
void inserirCartasPilha(Pilha *pilha, Lista_Estatica *estatica, int indice);
No *peek(Pilha *p, int x);
Lista *iniciarLista();
Pilha *iniciarPilha();
Lista_Estatica *embaralharCartas(Lista_Estatica *lista); 
void inserirCartasEstatica(Lista_Estatica *lista); 
void iniciarJogo();
int main();

#endif
