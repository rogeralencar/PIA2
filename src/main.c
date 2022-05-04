/*
A lista estática contém todas as cartas do baralho.
Já as listas encadeadas são as 7 colunas de cartas quando o jogo é iniciado.
Cada uma representada pela quantidade de cartas. 
Ex: 1º coluna - 1 carta, 2º coluna - 2 cartas e etc...
*/
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <time.h>
#include <locale.h>

typedef struct Carta{
    char valor;
    const wchar_t *naipe;
} Carta;

typedef struct No {
    struct Carta carta;
    struct No *prox;
} No;

// Lista Encadeada
typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;

// Lista Estática
typedef struct Lista_Estatica {
    struct Carta cartas[52];
    int nElementos;
} Lista_Estatica;

Lista *iniciarLista(){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
}

void inserirElementos(Lista *l, Lista_Estatica *estatica){
    No *n = NULL;
    n = malloc(sizeof(No));

    n->carta.valor = estatica->cartas->valor;
    n->carta.naipe = estatica->cartas->naipe;
    estatica->nElementos--;
    n->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = n;
        l->fim = n;
    } else {
        l->fim->prox = n;
        l->fim = n;
    }
}

// Listar Elementos das listas encadeadas
void listarElementos(Lista *l){
    No *n = l->inicio;
    
    if(n == NULL){
        printf("Lista vazia!\n");
    } else {
        while(n != NULL){
            printf("%c%ls ", n->carta.valor, n->carta.naipe);
            n = n->prox;
        }
    }
}

void imprimirCartasEmbaralhadas(Lista_Estatica *lista){
    for(int i = 0; i < lista->nElementos; i++){
        if(i == 13){
            printf("\n");
        } else if (i == 26){
            printf("\n");
        } else if(i == 39){
            printf("\n");
        } else if(i == 52){
            printf("\n");
        }
        if(lista->cartas[i].valor == '1'){
            printf("%c0%ls ", lista->cartas[i].valor, lista->cartas[i].naipe);
        } else {
            printf("%c%ls ", lista->cartas[i].valor, lista->cartas[i].naipe);
        }
    }
}

Lista_Estatica *embaralharCartas(Lista_Estatica *lista){
    int i, j;
    Lista_Estatica *tmp;
    tmp = malloc(sizeof(Lista_Estatica));
    srand(time(NULL));  

    /* Algoritmo de Fisher-Yates para a randomização das cartas,
    porém não está funcionando perfeitamente, contém repetição de cartas de mesmo naipe. */
    for(i = lista->nElementos - 1; i > 0; i--){
        j = rand() % (i + 1);
        tmp->cartas->valor = lista->cartas[j].valor;
        lista->cartas[j].valor = lista->cartas[i].valor;
        lista->cartas[i].valor = tmp->cartas->valor;
    }
    
    return lista;
}

//Colocar as cartas na lista estática, que é o deck do baralho
void inserirCartasEstatica(Lista_Estatica *lista){
    //Ordem dos naipes: paus, espadas, copas e ouros
    const wchar_t *naipes[4] = {L"\x2663", L"\x2660", L"\x2665", L"\x2666"};
    char valores[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
    
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

    printf("%d\n", lista->nElementos);    
}

int main(){
    setlocale(LC_ALL, "");
    Lista *l = iniciarLista();

    // Inicialização da Lista Estática
    Lista_Estatica *l_estatica;
    l_estatica = malloc(sizeof(Lista_Estatica));

    l_estatica->nElementos = 0;

    inserirCartasEstatica(l_estatica);
    embaralharCartas(l_estatica);
    // Fim da inicialização da lista estática

    /* Início do array de listas encadeadas. 
    Um array com 7 posições, em cada uma contendo uma lista encadeada, 
    que vai receber as cartas no início do jogo */
    Lista *arr;
    arr = malloc(sizeof(Lista)*7);

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
        inserirElementos(&arr[indice], embaralharCartas(l_estatica));
    }

    // Listar elementos de cada array (lista os elementos das listas encadeadas)
    for(int i = 0; i < 7; i++){
        listarElementos(&arr[i]);
        printf("\n");
    }
    printf("Número de cartas restantes: %d\n", l_estatica->nElementos);    
    return 0;
}