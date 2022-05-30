#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "cartas.h"

void mostrarCartas(Lista *l){    
    No *n = l->inicio;
    No *m = l->fim;

    if(n == NULL){
        printf("[]");
    } else {
        printf("[");
        while(n != NULL){
            if(n != m && n->carta.flag == 0) {
                printf("- ");
            }
            m->carta.flag = 1;
            if (n->carta.flag == 1) {
                printf("%s%ls ", n->carta.valor, n->carta.naipe);
            }
            n = n->prox;
        }
        printf("]");
    }
} 
