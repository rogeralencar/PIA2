#ifndef INTERFACE_H
#define INTERFACE_H

#include "cartas.h"
#include "lista.h"
#include "pilha.h"
#include "main.h"


void fazerCartas(Carta c, int x, int y);
void fazerCartasDescarte(Carta c);
void fazerCartasManilha(Carta c, int x);
void esconderCartas(Lista *l, int x, int y);
void mostrarRanking(); 
void mostrarCreditos(); 
void mostrarIcone(); 
void mostrarInterface(Pilha **p, Jogador *j);  
void menu();


#endif