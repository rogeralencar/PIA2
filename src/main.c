#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>
#include <locale.h>
#include "structs.h"
#include "comandos.h"
#include "main.h"
#include "cartas.h"

Lista *iniciarLista(){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

Pilha *iniciarPilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->numCartas = 0;
    return p;
}

void enfileira(Lista *Fila, Lista_Estatica *estatica, int indice){
    No *n = malloc(sizeof(No));

    n->carta.valor = estatica->cartas[indice].valor;
    n->carta.naipe = estatica->cartas[indice].naipe;
    n->prox = NULL;
    n->ant = NULL;

    if (Fila->inicio == NULL){
        Fila->inicio = n;
        Fila->fim = n;
    } else {
        n->prox = Fila->fim;
        Fila->fim->ant = n;
    }

    Fila->fim = n;
}

No *recuperaInicio(Lista *l){
    No *inicio = l->inicio;

    if(inicio == NULL){
        printf("Descarte vazio.\n");
    } else {
        printf("%s%ls\n", inicio->carta.valor, inicio->carta.naipe);
        return inicio;
    }

    return NULL;
}

No *pop(Pilha *p){
    No *topo = malloc(sizeof(No));

    topo = p->topo;

    if(topo == NULL){
        printf("Pilha vazia!\n");
        return NULL;
    }

    if(topo->prox != NULL){
        p->topo = p->topo->prox;
    } else {
        p->topo = NULL;
    }
    
    p->numCartas--;
    return topo;
}

No *desenfileira(Lista *lista){
    No *inicio = malloc(sizeof(No));
    inicio->carta = lista->inicio->carta;

    if(lista->inicio == NULL){
        printf("Fila vazia!");
        return NULL;
    } else {
        free(lista->inicio);
        lista->inicio = lista->inicio->ant;
        lista->inicio->prox = NULL;

    }

    return inicio;
}

void inserirElementos(Lista *l, Lista *f){
    No *n = malloc(sizeof(No));

    n = desenfileira(f);
    n->prox = NULL;

   if(l->inicio == NULL){
        l->inicio = n;
        l->fim = n;
    } else {
        l->fim->prox = n;
        l->fim = n;
    }
}

No *cartasVisiveis(Lista *l){
    if(l->inicio == NULL){
        printf("Lista vazia!");
    } else {
        No *n = l->inicio;
        while(n != NULL){
            if(n->carta.flag == 1){
                return n;
                break;
            }
            n = n->prox;
        }
    }
}

void inserirElementosNo(Lista *l, No *n){   
    No *no = malloc(sizeof(No));
    no = n;

    if(l->inicio == NULL){
        l->inicio = no;
        l->fim = no;
    } else {
        l->fim->prox = no;
        l->fim = no;
    }
}

void deletarElementos(Lista *l) {
    if(l->inicio != NULL) {
        if(l->inicio->prox == NULL) {
            l->inicio = NULL;
        } else {
            No *p = l->inicio;
            while(p->prox->prox != NULL){
                p = p->prox; 
            }
            p->carta.flag = 1;
            No *ultimoNo = p->prox;
            free(ultimoNo); 
            p->prox = NULL;
            l->fim = p;
        }
    }
}

void deletarElementosNo(Lista *l) {
    if(l->inicio != NULL) {
        if(l->inicio->prox == NULL) {
            l->inicio = NULL;
        } else {
            No *p = l->inicio;
            while(p->prox->prox != NULL){
                p = p->prox; 
            }
            p->carta.flag = 1;
            No *ultimoNo = p->prox;
            free(ultimoNo); 
            p->prox = NULL;
            l->fim = p;
        }
    }
}

void inserirManilha(Pilha *p, Lista *l){
    No *no = malloc(sizeof(No));

    no->carta = l->fim->carta;
    p->numCartas++;

    if(p->topo == NULL){
        p->topo = no;
    } else {
        No *tmp = p->topo;
        p->topo = no;
        p->topo->prox = tmp;
    }

    deletarElementos(l);
}

void inserirManilhaDireto(Pilha *p, Lista *l){
    No *no = malloc(sizeof(No));

    no->carta = l->inicio->carta;
    p->numCartas++;

    if(p->topo == NULL){
        p->topo = no;
    } else {
        No *tmp = p->topo;
        p->topo = no;
        p->topo->prox = tmp;
    }

    desenfileira(l);
}

//Função para trocar os elementos das listas encadeadas
void trocarElementos(Lista *l, Lista *l1){
    No *n = malloc(sizeof(No)), *m = malloc(sizeof(No));
    
    m = l1->inicio;
    No *proximo = m->prox;

    while(proximo != NULL){
        m = proximo;
        proximo = m->prox;
    }

    n->carta.valor = m->carta.valor;
    n->carta.naipe = m->carta.naipe;
    n->carta.flag = 1;
    n->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = n;
        l->fim = n;
    } else {
        l->fim->prox = n;
        l->fim = n;
    }

    deletarElementos(l1);
}

void apagarCartasVisiveis(Lista *l){
    No *n = l->inicio;
    int i = 0;

    while(n != NULL){
        if(n->carta.flag == 1){
            i++;
        }
        n = n->prox;
    }

    for(int j = 0; j < i; j++){
        deletarElementos(l);
    }
}

void trocarElementosMaisCartas(Lista *origem, Lista *destino){
    No *n = malloc(sizeof(No)), *m = malloc(sizeof(No));
    
    m = origem->inicio;

    while(m != NULL){
        if(m->carta.flag == 1){
            m = m->prox;
            n->carta.valor = m->carta.valor;
            n->carta.naipe = m->carta.naipe;
            n->carta.flag = 1;
            n->prox = NULL;

            if(destino->inicio == NULL){
                destino->inicio = n;
                destino->fim = n;
            } else {
                destino->fim->prox = n;
                destino->fim = n;
            }
        }
        m = m->prox;
    }

    deletarElementosNo(origem);
}

void trocarElementosDeck(Lista *l, Lista *l1){
    No *n = malloc(sizeof(No)), *m = malloc(sizeof(No));
    
    m = l1->inicio;
    No *proximo = m->prox;

    while(proximo != NULL){
        m = proximo;
        proximo = m->prox;
    }

    n = desenfileira(l1);
    n->carta.flag = 1;
    n->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = n;
        l->fim = n;
    } else {
        l->fim->prox = n;
        l->fim = n;
    }
}

Lista_Estatica *embaralharCartas(Lista_Estatica *lista){
    int j;
    srand(time(NULL));  
    No *n = malloc(sizeof(No));

    // Algoritmo de Fisher-Yates para a randomização das cartas.
    for(int i = 0; i < lista->nElementos; i++){
        j = rand() % lista->nElementos;
        n->carta = lista->cartas[i];
        lista->cartas[i] = lista->cartas[j];
        lista->cartas[j] = n->carta; 
    }

    return lista;
}

// Isso deve ser substituído para uma pilha
//Colocar as cartas na lista estática, que é o deck do baralho
void inserirCartasEstatica(Lista_Estatica *lista){
    //Ordem dos naipes: paus, espadas, copas e ouros
    const wchar_t *naipes[4] = {L"\x2663", L"\x2660", L"\x2665", L"\x2666"};
    char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    //Laço de repetição para colocar os valores das cartas na lista estática
    int aux = 0;
    while(lista->nElementos < 52){
        for(int i = 0; i < 13; i++){
            lista->cartas[aux].valor = valores[i];
            aux++;
            lista->nElementos++;
        }
    }

    //Laço de repetição para colocar os naipes das cartas na lista estática
    //A cada 13 cartas, é um naipe diferente.
    int aux2 = 0;
    while(aux2 < 52){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                lista->cartas[aux2].naipe = naipes[i];
                aux2++;
            }
        }
    }

    for(int i = 0; i < lista->nElementos; i++){
        lista->cartas[i].flag = 0;
    }
}

void inserirCartasPilha(Pilha *pilha, Lista_Estatica *estatica, int indice){
    No *n = malloc(sizeof(No));

    n->carta.valor = estatica->cartas[indice].valor;
    n->carta.naipe = estatica->cartas[indice].naipe;

    if(pilha->numCartas == 0){
        pilha->topo = n;
    } else {
        No *tmp = pilha->topo;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = n;
    }
    pilha->numCartas++;
}

// Função que verifica o naipe das cartas
//Ordem dos naipes: paus, espadas, copas e ouros
// L"\x2663", L"\x2660", L"\x2665", L"\x2666"
void verificarNaipe(Lista *l, Lista *l1){
    const wchar_t *paus = L"\x2663";
    const wchar_t *espadas = L"\x2660";
    const wchar_t *copas = L"\x2665";
    const wchar_t *ouros = L"\x2666";

    No *c1 = l->fim;
    No *c2 = l1->fim;

    if(c1->carta.naipe == paus && c2->carta.naipe == copas){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == paus && c2->carta.naipe == ouros){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == copas){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == ouros){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == paus){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == espadas){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == paus){
        trocarElementos(l, l1);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == espadas){
        trocarElementos(l, l1);
        return;
    } else {
        printf("\nMovimento inválido.\n");
    }
}

int append(No **inicio, Carta c) {
    No *tmp = malloc(sizeof(No));
    int success = tmp != NULL;

    if(success){
        tmp->carta = c;
        tmp->prox = NULL;
        while (*inicio) inicio = &( *inicio )->prox;
        *inicio = tmp;
    }
    return success;
}

No *copy(No *source){
    No *destination = NULL;

    for(;source;source = source->prox) 
      append(&destination, source->carta);

    return destination;
}

void moverMaisCartas(Lista *origem, Lista *destino){
    No *m = copy(cartasVisiveis(origem));

    if(destino->inicio == NULL){
        if(m->carta.valor == "K"){
            while(m != NULL){
                inserirElementosNo(destino, m);
                m = m->prox;
            }
        }
    } else {
        while(m != NULL){
            inserirElementosNo(destino, m);
            m = m->prox;
        }
    }
    apagarCartasVisiveis(origem);
}

void verificarNaipeMoverMaisCartas(Lista *origem, Lista *destino){
    const wchar_t *paus = L"\x2663";
    const wchar_t *espadas = L"\x2660";
    const wchar_t *copas = L"\x2665";
    const wchar_t *ouros = L"\x2666";

    No *c1 = cartasVisiveis(origem);
    No *c2 = destino->fim;

    if(c1->carta.naipe == paus && c2->carta.naipe == copas){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == paus && c2->carta.naipe == ouros){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == copas){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == ouros){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == paus){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == espadas){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == paus){
        moverMaisCartas(origem, destino);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == espadas){
        moverMaisCartas(origem, destino);
        return;
    } else {
        printf("\nMovimento inválido.\n");
    }
}

void verificarNaipeComprar(Lista *l, Lista *l1){
    const wchar_t *paus = L"\x2663";
    const wchar_t *espadas = L"\x2660";
    const wchar_t *copas = L"\x2665";
    const wchar_t *ouros = L"\x2666";

    No *c1 = l->fim;
    No *c2 = l1->inicio;

    if(c1->carta.naipe == paus && c2->carta.naipe == copas){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == paus && c2->carta.naipe == ouros){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == copas){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == espadas && c2->carta.naipe == ouros){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == paus){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == copas && c2->carta.naipe == espadas){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == paus){
        trocarElementosDeck(l, l1);
        return;
    } else if(c1->carta.naipe == ouros && c2->carta.naipe == espadas){
        trocarElementosDeck(l, l1);
        return;
    } else {
        printf("\nMovimento inválido.\n");
    }
}

void verificarNaipeManilha(Pilha *p, Lista *l1){
    const wchar_t *paus = L"\x2663";
    const wchar_t *espadas = L"\x2660";
    const wchar_t *copas = L"\x2665";
    const wchar_t *ouros = L"\x2666";

    No *topo = p->topo;
    No *c1 = l1->fim;
    No *inicio = l1->inicio;

    if(p->topo == NULL){
        inserirManilha(p, l1);
    } else {
        if(topo->carta.naipe == paus && c1->carta.naipe == paus){
            inserirManilha(p, l1);
        } else if(topo->carta.naipe == ouros && c1->carta.naipe == ouros){
            inserirManilha(p, l1);
        } else if(topo->carta.naipe == copas && c1->carta.naipe == copas){
            inserirManilha(p, l1);
        } else if(topo->carta.naipe == espadas && c1->carta.naipe == espadas){
            inserirManilha(p, l1);
        } else if(topo->carta.naipe == paus && inicio->carta.naipe == paus){
            inserirManilhaDireto(p, l1); 
        } else if(topo->carta.naipe == ouros && inicio->carta.naipe == ouros){
            inserirManilhaDireto(p, l1);
        } else if(topo->carta.naipe == copas && inicio->carta.naipe == copas){
            inserirManilhaDireto(p, l1);
        } else if(topo->carta.naipe == espadas && inicio->carta.naipe == espadas){
            inserirManilhaDireto(p, l1);
        } else {
            printf("\nMovimento inválido.\n");
        }
    }
}

void vNaipeManilha(Pilha *p, Lista *l1){
    const wchar_t *paus = L"\x2663";
    const wchar_t *espadas = L"\x2660";
    const wchar_t *copas = L"\x2665";
    const wchar_t *ouros = L"\x2666";

    No *topo = p->topo;
    No *inicio = l1->inicio;

    if(p->topo == NULL){
        inserirManilha(p, l1);
    } else {
        if(topo->carta.naipe == paus && inicio->carta.naipe == paus){
            inserirManilhaDireto(p, l1); 
        } else if(topo->carta.naipe == ouros && inicio->carta.naipe == ouros){
            inserirManilhaDireto(p, l1);
        } else if(topo->carta.naipe == copas && inicio->carta.naipe == copas){
            inserirManilhaDireto(p, l1);
        } else if(topo->carta.naipe == espadas && inicio->carta.naipe == espadas){
            inserirManilhaDireto(p, l1);
        } else {
            printf("\nMovimento inválido.\n");
        }
    }
}

// Responsável por ordernar as cartas de forma decrescente nas listas encadeadas.
void decrescente(Lista *l, Lista *l1){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

  No *atual = malloc(sizeof(No));
  atual = (l->fim);

  if(l->inicio == NULL){
      if(l1->fim->carta.valor == valores[12]){
          trocarElementos(l, l1);
      }
  }
    
  for(int i = 0; i < 13; i++){
    if(atual->carta.valor == valores[i] && l1->fim->carta.valor == valores[i-1]){
        verificarNaipe(l, l1);
        break;
    } 
  }
}

void decrescenteComprar(Lista *l, Lista *l1){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    No *atual = l->fim;

    if(l->inicio == NULL){
        if(l1->inicio->carta.valor == valores[12]){
            trocarElementosDeck(l, l1);
        }
    }
    
  for(int i = 0; i < 13; i++){
    if(atual->carta.valor == valores[i] && l1->inicio->carta.valor == valores[i-1]){
        verificarNaipeComprar(l, l1);
        break;
    } 
  }
}

void decrescenteManilha(Lista *l, Lista *l1){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    No *atual = l->fim;
    
  for(int i = 0; i < 13; i++){
    if(atual->carta.valor == valores[i] && l1->inicio->carta.valor == valores[i-1]){
        verificarNaipe(l, l1);
        break;
    } 
  }
}

// Verificar ordem decrescente para mover mais cartas
void decrescenteMoverMaisCartas(Lista *origem, Lista *destino){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};


    No *atual = cartasVisiveis(origem);
    
    if(destino->inicio == NULL){
        if(atual->carta.valor == valores[12]){
            moverMaisCartas(origem, destino);
        }
    }
    
    for(int i = 0; i < 13; i++){
        if(destino->fim->carta.valor == valores[i] && atual->carta.valor == valores[i-1]){
            verificarNaipeMoverMaisCartas(origem, destino);
            break;
        } 
    }
}

void crescenteManilhaDireto(Pilha *p, Lista *l1){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

  No *atual = l1->fim;

    if(p->topo == NULL){
        if(l1->inicio->carta.valor == valores[0]){
            inserirManilhaDireto(p, l1);
            return;
        } 
    } else {
        for(int i = 0; i < 13; i++){
            if(p->topo->carta.valor == valores[i] && l1->inicio->carta.valor == valores[i+1]){
                vNaipeManilha(p, l1);
                break;
            } 
        }
    }
}

void crescenteManilha(Pilha *p, Lista *l1){
  char *valores[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

  No *atual = l1->fim;

    if(p->topo == NULL){
        if(atual->carta.valor == valores[0]) {
            inserirManilha(p, l1);
            return;
        }
    } else {
        for(int i = 0; i < 13; i++){
            if(p->topo->carta.valor == valores[i] && atual->carta.valor == valores[i+1]){
                verificarNaipeManilha(p, l1);
                break;
            }
        }
    }
}

No *peek(Pilha *p){
    if(p->numCartas == 0){
        printf("[]");
        return NULL;
    } else {
        printf("%s%ls", p->topo->carta.valor, p->topo->carta.naipe);
        return p->topo;
    }
}

void enfileiraFim(Lista *lista, No *no){
  no->ant = NULL;
  no->prox = lista->fim;
  lista->fim->ant = no;
  lista->fim = no;
}

int main(){
    setlocale(LC_ALL, "");

    Lista *f = iniciarLista();
    // Inicialização da Lista Estática
    Lista *l = iniciarLista();
    Lista_Estatica *l_estatica;
    l_estatica = malloc(sizeof(Lista_Estatica));
    l_estatica->nElementos = 0;
    inserirCartasEstatica(l_estatica);
    embaralharCartas(l_estatica);
    // Fim da inicialização da lista estática

    /* Início do array de pilhas.
    Um array com 6 posições, em cada uma contendo uma pilha. 
    4 pilhas são para as manilhas e as outras 2 são para comprar cartas. */
    Pilha *pilhas = malloc(sizeof(Pilha)*6);

    Pilha *p1 = iniciarPilha();
    Pilha *p2 = iniciarPilha();
    Pilha *p3 = iniciarPilha();
    Pilha *p4 = iniciarPilha();
    Pilha *p5 = iniciarPilha();
    Pilha *p6 = iniciarPilha();

    pilhas[0] = *p1; // Manilha 1
    pilhas[1] = *p2; // Manilha 2
    pilhas[2] = *p3; // Manilha 3
    pilhas[3] = *p4; // Manilha 4
    pilhas[4] = *p5; // Baralho de cartas
    pilhas[5] = *p6; // Pilha auxiliar para comprar cartas

    for(int i = 0; i < 52; i++){
        // inserirCartasPilha(&pilhas[4], l_estatica, i);
        enfileira(f, l_estatica, i);
    }

    /* Início do array de listas encadeadas. 
    Um array com 7 posições, em cada uma contendo uma lista encadeada, 
    que vai receber as cartas no início do jogo */
    Lista *arr = malloc(sizeof(Lista)*7);

    Lista *l1 = iniciarLista();
    Lista *l2 = iniciarLista();
    Lista *l3 = iniciarLista();
    Lista *l4 = iniciarLista();
    Lista *l5 = iniciarLista();
    Lista *l6 = iniciarLista();
    Lista *l7 = iniciarLista();

    arr[0] = *l1; //No início do jogo deve ter somente uma carta
    arr[1] = *l2; //No início do jogo deve ter duas cartas
    arr[2] = *l3; //No início do jogo deve ter três cartas
    arr[3] = *l4; //Assim por diante
    arr[4] = *l5;
    arr[5] = *l6;
    arr[6] = *l7;

    // Representa a quantidade de cartas por coluna, de 0 a 6, no caso 1 a 7 //
    int numeros[28] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6};

    //Insere elementos nas listas encadeadas//
    for(int i = 0; i < 28; i++){
        int indice = numeros[i];
        // inserirElementos(&arr[indice], &pilhas[4]);
        inserirElementos(&arr[indice], f);
    }
      
    opcoesDoJogo(&arr, &pilhas, f);

    return 0;
}