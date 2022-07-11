#ifndef cartas_H
#define cartas_H
#include <wchar.h>
#include <wctype.h>

typedef struct Carta
{
    char *valor;
    const wchar_t *naipe;
    int flag;
} Carta;

#endif