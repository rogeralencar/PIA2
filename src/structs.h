#ifndef STRUCTS_H
#define STRUCTS_H

#include <wchar.h>
#include <wctype.h>

typedef struct Carta{
    char *valor;
    const wchar_t *naipe;
    int flag;
} Carta;

// Lista Encadeada
typedef struct No {
    struct Carta carta;
    struct No *prox;
    struct No *ant;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;
// Fim da lista Encadeada

// Pilha
typedef struct Pilha {
    No *topo;
    int numCartas;
} Pilha;
// Fim da pilhas

typedef struct Lista_Estatica {
    struct Carta cartas[52];
    int nElementos;
} Lista_Estatica;

#endif