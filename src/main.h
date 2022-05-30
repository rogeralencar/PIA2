#ifndef MAIN_H
#define MAIN_H

Lista *iniciarLista();
Pilha *iniciarPilha();
void enfileira(Lista *Fila, Lista_Estatica *estatica, int indice);
No *recuperaInicio(Lista *Fila);
No *pop(Pilha *p);
No *desenfileira(Lista *lista);
void inserirElementos(Lista *l, Lista *f);
No *cartasVisiveis(Lista *l);
void inserirElementosNo(Lista *l, No *n);
void deletarElementos(Lista *l);
void deletarElementosNo(Lista *l);
void inserirManilha(Pilha *p, Lista *l);
void inserirManilhaDireto(Pilha *p, Lista *l);
void trocarElementos(Lista *l, Lista *l1);
void apagarCartasVisiveis(Lista *l);
void trocarElementosMaisCartas(Lista *origem, Lista *destino);
void trocarElementosDeck(Lista *l, Lista *l1);
Lista_Estatica *embaralharCartas(Lista_Estatica *lista);
void inserirCartasEstatica(Lista_Estatica *lista);
void inserirCartasPilha(Pilha *pilha, Lista_Estatica *estatica, int indice);
void verificarNaipe(Lista *l, Lista *l1);
int append(No **inicio, Carta c);
No *copy(No *source);
void moverMaisCartas(Lista *origem, Lista *destino);
void verificarNaipeMoverMaisCartas(Lista *origem, Lista *destino);
void verificarNaipeComprar(Lista *l, Lista *l1);
void verificarNaipeManilha(Pilha *p, Lista *l1);
void vNaipeManilha(Pilha *p, Lista *l1);
void decrescente(Lista *l, Lista *l1);
void decrescenteComprar(Lista *l, Lista *l1);
void decrescenteManilha(Lista *l, Lista *l1);
void decrescenteMoverMaisCartas(Lista *origem, Lista *destino);
void crescenteManilhaDireto(Pilha *p, Lista *l1);
void crescenteManilha(Pilha *p, Lista *l1);
No *peek(Pilha *p);
void enfileiraFim(Lista *lista, No *no);
int main();

#endif