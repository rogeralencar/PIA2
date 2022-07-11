#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include "core.h"

bool comparaNaipe(const wchar_t * n1, const wchar_t * n2)
{
    return (n1 == paus && n2 == copas) || (n1 == paus && n2 == ouros) ||
            (n1 == espadas && n2 == copas) || (n1 == espadas && n2 == ouros) ||
            (n1 == copas && n2 == paus) || (n1 == copas && n2 == espadas) ||
            (n1 == ouros && n2 == paus) || (n1 == ouros && n2 == espadas);
}

bool comparaNaipeCrescente(const wchar_t * n1, const wchar_t * n2)
{
    return (n1 == paus && n2 == paus) || (n1 == ouros && n2 == ouros) ||
            (n1 == copas && n2 == copas) || (n1 == espadas && n2 == espadas);
}

bool comparaCartaDecrescente(Carta c1, Carta c2)
{
    for (int i = 0; i < 13; i++) { 
        if (c1.valor == valores[i] && c2.valor == valores[i - 1]) {
            return true;
            break;
        }
    }

    return false;
}

bool comparaCartaCrescente(Carta c1, Carta c2){
    for (int i = 0; i < 13; i++) { 
        if (c1.valor == valores[i] && c2.valor == valores[i + 1]) {
            return true;
            break;
        }
    }

    return false;
}

int inserirNosCopia(No **inicio, Carta c)
{
    No *tmp = malloc(sizeof(No));
    int sucesso = tmp != NULL;

    if (sucesso) { 
        tmp->carta = c;
        tmp->prox = NULL;
        while (*inicio)
            inicio = &(*inicio)->prox;
        *inicio = tmp;
    }
    return sucesso;
}

No *copiarNosLista(No *origem)
{
    No *destino = NULL;

    while (origem != NULL) {
        inserirNosCopia(&destino, origem->carta);
        origem = origem->prox;
    }

    return destino;
}

void moverMaisCartas(Lista * origem, Lista * destino, Jogador *j)
{
    No * m = copiarNosLista(cartasVisiveis(origem));

    if (destino->inicio == NULL && strcmp(m->carta.valor, "K") == 0) { 
        while (m != NULL) {
            inserirElementosNo(destino, m, j);
            m = m->prox;
        }
    } else { 
        while (m != NULL) {
            inserirElementosNo(destino, m, j);
            m = m->prox;
        }
    }
    apagarCartasVisiveis(origem);
}

void verificarNaipeMoverMaisCartas(Lista *origem, Lista *destino, Jogador *j)
{
    No *c1 = cartasVisiveis(origem);
    No *c2 = destino->fim;

    if (comparaNaipe(c1->carta.naipe, c2->carta.naipe))
        moverMaisCartas(origem, destino, j);
    else  
        mvwprintw(stdscr, row - 5, 3, "Movimento inválido.");

}

void verificarNaipeComprar(Lista *l, Lista *l1, Jogador *j)
{
    No *c1 = l->fim;
    No *c2 = l1->inicio;
    
    if (comparaNaipe(c1->carta.naipe, c2->carta.naipe)) 
        trocarElementosDeck(l, l1, j);
    else 
        mvwprintw(stdscr, row - 5, 3, "Movimento inválido.");

}

void verificarNaipeManilha(Pilha *p, Lista *l1, Jogador *j)
{
    No *topo = p->topo;
    No *c1 = l1->fim;
    No *inicio = l1->inicio;

    if (p->topo == NULL) { 
        inserirManilha(p, l1, j);
    } else if (comparaNaipeCrescente(topo->carta.naipe, c1->carta.naipe)) { 
        inserirManilha(p, l1, j);
        return;
    } else if (comparaNaipeCrescente(topo->carta.naipe, inicio->carta.naipe)){
        inserirManilhaDireto(p, l1, j);
        return;
    } else { 
        mvwprintw(stdscr, row - 5, 3, "Movimento inválido.");
    }
}

// Responsável por ordernar as cartas de forma decrescente nas listas encadeadas.
void decrescente(Lista *destino, Lista *origem, Jogador *j)
{
    if (origem->fim == NULL) {
        mvprintw(row - 4, 4, "%s", "Coluna vazia!");
        return;
    } else if (destino->inicio == NULL && origem->fim->carta.valor == valores[12]) { 
        trocarElementos(destino, origem, j);
        return;
    } else {
        if (comparaCartaDecrescente(destino->fim->carta, origem->fim->carta) 
        && comparaNaipe(destino->fim->carta.naipe, origem->fim->carta.naipe))
            trocarElementos(destino, origem, j);
    }
}

void decrescenteComprar(Lista *destino, Lista *origem, Jogador *j)
{
    if (origem->inicio == NULL) {
        mvprintw(row - 4, 4, "%s", "Descarte vazio!");
        return;
    } else { 
        if (destino->inicio == NULL && origem->inicio->carta.valor == valores[12])  
            trocarElementosDeck(destino, origem, j);
        
        if (comparaCartaDecrescente(destino->fim->carta, origem->inicio->carta))
            verificarNaipeComprar(destino, origem, j);
    }
}

// Verificar ordem decrescente para mover mais cartas
void decrescenteMoverMaisCartas(Lista *origem, Lista *destino, Jogador *j)
{
    if (origem == NULL) { 
        mvprintw(row - 4, 4, "%s", "Coluna vazia!");
        return;
    } else { 
        No *n = cartasVisiveis(origem);
        
        if (destino->inicio == NULL && n->carta.valor == valores[12]) 
            moverMaisCartas(origem, destino, j);

        if (comparaCartaDecrescente(destino->fim->carta, n->carta))
            verificarNaipeMoverMaisCartas(origem, destino, j);
    }
}

void crescenteManilhaDireto(Pilha *pilha, Lista *lista, Jogador *j)
{
    No *atual = lista->inicio;
    No *topo = pilha->topo;

    if (topo == NULL) {
        if (atual->carta.valor == valores[0]) 
            inserirManilhaDireto(pilha, lista, j);
        else
            return; 
    } else { 
        if (comparaCartaCrescente(topo->carta, atual->carta))
            verificarNaipeManilha(pilha, lista, j);
    }
}

void crescenteManilha(Pilha *pilha, Lista *lista, Jogador *j)
{
    No *atual = lista->fim;
    No *topo = pilha->topo;

    if (topo == NULL) { 
        if (atual->carta.valor == valores[0]) 
            inserirManilha(pilha, lista, j);
        else
            return;
    } else { 
        if (comparaCartaCrescente(topo->carta,  atual->carta)) 
            verificarNaipeManilha(pilha, lista, j);
    }
}
