#ifndef CORE_H
#define CORE_H

#include "pilha.h"
#include "lista.h"
#include "main.h"

bool comparaNaipe(const wchar_t * n1, const wchar_t * n2);
bool comparaNaipeCrescente(const wchar_t * n1, const wchar_t * n2);
void verificarNaipe(Lista *l, Lista *l1, Jogador *j);
int inserirNosCopia(No **inicio, Carta c);
No *copiarNosLista(No *origem);
void moverMaisCartas(Lista * origem, Lista * destino, Jogador *j);
void verificarNaipeMoverMaisCartas(Lista *origem, Lista *destino, Jogador *j);
void verificarNaipeComprar(Lista *l, Lista *l1, Jogador *j);
void verificarNaipeManilha(Pilha *p, Lista *l1, Jogador *j);
void decrescente(Lista *destino, Lista *origem, Jogador *j);
void decrescenteComprar(Lista *destino, Lista *origem, Jogador *j);
void decrescenteMoverMaisCartas(Lista *origem, Lista *destino, Jogador *j);
void crescenteManilhaDireto(Pilha *p, Lista *l1, Jogador *j);
void crescenteManilha(Pilha *p, Lista *l1, Jogador *j);
void fimDoJogo(Pilha **p);
void ranking(Jogador * j);

#endif