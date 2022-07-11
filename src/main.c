/*
 * Projeto Integrador A2 
 * Data: 27/06/2022
 * Grupo Loop
 * Roger Alencar - 2022130015
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "main.h"

const wchar_t *paus = L"\x2663";
const wchar_t *espadas = L"\x2660";
const wchar_t *copas = L"\x2665";
const wchar_t *ouros = L"\x2666";
char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int row, col;

Lista *iniciarLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

Pilha *iniciarPilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->numCartas = 0;
    return p;
}

void inserirListaCircular(Lista *lista, Lista_Estatica *estatica, int indice)
{
    No *n = malloc(sizeof(No));

    n->carta.valor = estatica->cartas[indice].valor;
    n->carta.naipe = estatica->cartas[indice].naipe;
    n->prox = NULL;
    n->ant = NULL;

    if (lista->inicio == NULL) { 
        lista->inicio = n;
        lista->fim = n;
    } else { 
        n->prox = lista->fim;
        lista->fim->ant = n;
    }

    lista->fim = n;
}

No *recuperaInicio(Lista *lista)
{
    No *inicio = lista->inicio;

    if (inicio == NULL) { 
        attron(A_BOLD);
        attron(COLOR_PAIR(4));
        mvprintw(0, 0, "┏━━━┓");
        mvprintw(1, 0, "┃ Ø ┃");
        mvprintw(2, 0, "┗━━━┛");
        attroff(COLOR_PAIR(4));
        attroff(A_BOLD);
        return NULL;
    } else { 
        fazerCartasDescarte(inicio->carta);
        return inicio;
    }
}

No *desenfileira(Lista *lista)
{
    No *inicio = malloc(sizeof(No));
    inicio->carta = lista->inicio->carta;

    if (lista->inicio == NULL) { 
        return NULL;
    } else { 
        free(lista->inicio);
        lista->inicio = lista->inicio->ant;
        lista->inicio->prox = NULL;
    }

    return inicio;
}

void inserirElementos(Lista *lista, Lista *f)
{
    No *n = malloc(sizeof(No));

    n = desenfileira(f);
    n->prox = NULL;

    if (lista->inicio == NULL) { 
        lista->inicio = n;
        lista->fim = n;
    } else { 
        lista->fim->prox = n;
        lista->fim = n;
    }
}

No *cartasVisiveis(Lista *lista)
{
    if (lista->inicio == NULL) { 
        printf("Lista vazia!");
    } else { 
        No *n = lista->inicio;
        while (n != NULL) {
            if (n->carta.flag == 1) {
                return n;
                break;
            }
            n = n->prox;
        }
    }
    return NULL;
}

void inserirElementosNo(Lista *lista, No *n, Jogador *j)
{
    No *no = malloc(sizeof(No));
    no = n;

    if (lista->inicio == NULL) { 
        lista->inicio = no;
        lista->fim = no;
    } else { 
        lista->fim->prox = no;
        lista->fim = no;
    }

    j->pontuacao += 5;
}

void deletarElementos(Lista *lista)
{
    if (lista->inicio != NULL && lista->inicio->prox == NULL) { 
        lista->inicio = NULL;
    } else { 
        No *p = lista->inicio;
        while (p->prox->prox != NULL)
            p = p->prox;
        p->carta.flag = 1;

        No *ultimoNo = p->prox;
        free(ultimoNo);
        p->prox = NULL;
        lista->fim = p;
    }
    
}

void inserirManilha(Pilha *p, Lista *lista, Jogador *j)
{
    No *no = malloc(sizeof(No));

    no->carta = lista->fim->carta;
    p->numCartas++;

    if (p->topo == NULL) { 
        p->topo = no;
    } else { 
        No *tmp = p->topo;
        p->topo = no;
        p->topo->prox = tmp;
    }

    j->pontuacao += 15;

    deletarElementos(lista);
}

void inserirManilhaDireto(Pilha *p, Lista *lista, Jogador *j)
{
    No *no = malloc(sizeof(No));

    no->carta = lista->inicio->carta;
    p->numCartas++;

    if (p->topo == NULL) { 
        p->topo = no;
    } else { 
        No *tmp = p->topo;
        p->topo = no;
        p->topo->prox = tmp;
    }

    j->pontuacao += 15;

    desenfileira(lista);
}

// Função para trocar os elementos das listas encadeadas
void trocarElementos(Lista *lista, Lista *lista1, Jogador *j)
{
    No *n = malloc(sizeof(No));
    No *m = malloc(sizeof(No));

    m = lista1->inicio;
    No *proximo = m->prox;

    while (proximo != NULL) { 
        m = proximo;
        proximo = m->prox;
    }

    n->carta.valor = m->carta.valor;
    n->carta.naipe = m->carta.naipe;
    n->carta.flag = 1;
    j->pontuacao += 5;
    n->prox = NULL;

    if (lista->inicio == NULL) { 
        lista->inicio = n;
        lista->fim = n;
    } else { 
        lista->fim->prox = n;
        lista->fim = n;
    }

    deletarElementos(lista1);
}

void apagarCartasVisiveis(Lista *lista)
{
    No *n = lista->inicio;
    int i = 0;

    while (n != NULL) { 
        if (n->carta.flag == 1)
            i++;
        n = n->prox;
    }

    for (int j = 0; j < i; j++)
        deletarElementos(lista);
}

void trocarElementosDeck(Lista *lista, Lista *lista1, Jogador *j)
{
    No *n = malloc(sizeof(No)), *m = malloc(sizeof(No));

    m = lista1->inicio;
    No *proximo = m->prox;

    while (proximo != NULL) { 
        m = proximo;
        proximo = m->prox;
    }

    n = desenfileira(lista1);
    n->carta.flag = 1;
    j->pontuacao += 5;
    n->prox = NULL;

    if (lista->inicio == NULL) { 
        lista->inicio = n;
        lista->fim = n;
    } else { 
        lista->fim->prox = n;
        lista->fim = n;
    }
}

Lista_Estatica *embaralharCartas(Lista_Estatica *lista)
{
    int j;
    srand((unsigned int)time(NULL));
    No *n = malloc(sizeof(No));

    // Algoritmo de Fisher-Yates para a randomização das cartas.
    for (int i = 0; i < lista->nElementos; i++) {
        j = rand() % lista->nElementos;
        n->carta = lista->cartas[i];
        lista->cartas[i] = lista->cartas[j];
        lista->cartas[j] = n->carta;
    }

    return lista;
}

// A lista estática é o baralho
void inserirCartasEstatica(Lista_Estatica *lista)
{
    // Ordem dos naipes: paus, espadas, copas e ouros
    const wchar_t *naipes[4] = {L"\x2663", L"\x2660", L"\x2665", L"\x2666"};

    // Laço de repetição para colocar os valores das cartas na lista estática
    int aux = 0;
    while (lista->nElementos < 52) {
        for (int i = 0; i < 13; i++) {
            lista->cartas[aux].valor = valores[i];
            aux++;
            lista->nElementos++;
        }
    }

    // Laço de repetição para colocar os naipes das cartas na lista estática
    // A cada 13 cartas, é um naipe diferente.
    int aux2 = 0;
    while (aux2 < 52) {
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j < 13; j++) {
                lista->cartas[aux2].naipe = naipes[i];
                aux2++;
            }
        }
    }

    for (int i = 0; i < lista->nElementos; i++)
        lista->cartas[i].flag = 0;
}

void inserirCartasPilha(Pilha *pilha, Lista_Estatica *estatica, int indice)
{
    No *n = malloc(sizeof(No));

    n->carta.valor = estatica->cartas[indice].valor;
    n->carta.naipe = estatica->cartas[indice].naipe;

    if (pilha->numCartas == 0) { 
        pilha->topo = n;
    } else { 
        No *tmp = pilha->topo;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = n;
    }
    pilha->numCartas++;
}

No *peek(Pilha *p, int x)
{
    if (p->numCartas == 0) { 
        attron(A_BOLD);
        attron(COLOR_PAIR(4));
        mvprintw(0, x, "┏━━━┓");
        mvprintw(1, x, "┃ M ┃");
        mvprintw(2, x, "┗━━━┛");
        attroff(COLOR_PAIR(4));
        attroff(A_BOLD);
        return NULL;
    } else { 
        fazerCartasManilha(p->topo->carta, x);
        return p->topo;
    }
}

void enfileiraFim(Lista *lista, No *no)
{
    if(no != NULL){
        no->ant = NULL;
        no->prox = lista->fim;
        lista->fim->ant = no;
        lista->fim = no;
    } else {
        return;
    }
}

void fimDoJogo(Pilha **p)
{
    if ((*p)[0].numCartas == 13 && (*p)[1].numCartas == 13 &&
        (*p)[2].numCartas == 13 && (*p)[3].numCartas == 13) { 
        mvprintw(row - 4, 3, "Parabéns! Você ganhou o jogo!");
    }
}

void ranking(Jogador * j){
    FILE *arquivo;
    arquivo = fopen("ranking.txt", "a+");

    if (arquivo == NULL) {
        printw("\n Arquivo nao encontrado");
        return;
    } else {
        fprintf (arquivo,"\nNome: %s Pontuação: %d\n", j->nome, j->pontuacao);
        fclose(arquivo);
    }
}

void iniciarJogo()
{
    Jogador *j = malloc(sizeof(Jogador));
    j->pontuacao = 0;
    Lista *f = iniciarLista();
    // Inicialização da Lista Estática
    Lista_Estatica *l_estatica;
    l_estatica = malloc(sizeof(Lista_Estatica));
    l_estatica->nElementos = 0;
    inserirCartasEstatica(l_estatica);
    embaralharCartas(l_estatica);
   
    // início do array de pilhas.
    Pilha *pilhas = malloc(sizeof(Pilha) * 5);

    Pilha *p1 = iniciarPilha();
    Pilha *p2 = iniciarPilha();
    Pilha *p3 = iniciarPilha();
    Pilha *p4 = iniciarPilha();
    Pilha *p5 = iniciarPilha();

    pilhas[0] = *p1; // manilha 1
    pilhas[1] = *p2; // manilha 2
    pilhas[2] = *p3; // manilha 3
    pilhas[3] = *p4; // manilha 4
    pilhas[4] = *p5; // baralho de cartas

    for (int i = 0; i < 52; i++) { 
        inserirListaCircular(f, l_estatica, i);
    }

    // início do array de listas encadeadas.
    Lista *arr = malloc(sizeof(Lista) * 7);
    Lista *l1 = iniciarLista();
    Lista *l2 = iniciarLista();
    Lista *l3 = iniciarLista();
    Lista *l4 = iniciarLista();
    Lista *l5 = iniciarLista();
    Lista *l6 = iniciarLista();
    Lista *l7 = iniciarLista();

    arr[0] = *l1; 
    arr[1] = *l2; 
    arr[2] = *l3; 
    arr[3] = *l4; 
    arr[4] = *l5;
    arr[5] = *l6;
    arr[6] = *l7;

    // representa a quantidade de cartas por coluna, de 0 a 6, no caso 1 a 7 
    int numeros[28] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6};

    // insere elementos nas listas encadeadas 
    for (int i = 0; i < 28; i++) { 
        int indice = numeros[i];
        inserirElementos(&arr[indice], f);
    }

    attron(COLOR_PAIR(77));
    mvprintw(0,22, "Digite o nome do jogador: ");
    attroff(COLOR_PAIR(77));
    scanw("%s%*c", j->nome);
    clear();
    refresh();
    opcoesDoJogo(7,&arr, &pilhas, f, j);
}

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    start_color();
    keypad(stdscr, true);

    getmaxyx(stdscr, row, col);

    init_pair(1, COLOR_RED, 15);
    init_pair(3, COLOR_BLACK, 15);
    init_pair(77, 15, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, 8);
    init_pair(5, COLOR_WHITE, 16);
    init_pair(6, COLOR_RED, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
    init_pair(8,  15, COLOR_WHITE);
    init_pair(15, 15, 30);
    init_pair(21, 8, COLOR_WHITE);
    init_pair(22, 30, 8);
    init_pair(16, 30, COLOR_BLACK);

    clear();
    refresh();
    menu();
}