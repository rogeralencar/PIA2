#ifndef LISTA_H
#define LISTA_H
#include "cartas.h"

typedef struct No {
    struct Carta carta;
    struct No *prox;
    struct No *ant;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;


#endif