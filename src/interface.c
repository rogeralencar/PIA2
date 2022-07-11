#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include "interface.h"

void fazerCartas(Carta c, int x, int y)
{
    if (c.naipe == paus || c.naipe == espadas) { 
        attron(COLOR_PAIR(3));
        if (strcmp(c.valor, "10") == 0) {
            mvprintw(x, y - 3, "%s%ls  ", c.valor, c.naipe);
            mvprintw(x + 1, y - 3, "  %ls  ", c.naipe);
            mvprintw(x + 2, y - 3, "  %ls%s", c.naipe, c.valor);
        } else { 
            mvprintw(x, y - 3, "%s%ls   ", c.valor, c.naipe);
            mvprintw(x + 1, y - 3, "  %ls  ", c.naipe);
            mvprintw(x + 2, y - 3, "   %s%ls", c.valor, c.naipe);
        }
        attroff(COLOR_PAIR(3));
    } else { 
        attron(COLOR_PAIR(1));
        if (strcmp(c.valor, "10") == 0) {
            mvprintw(x, y - 3, "%s%ls  ", c.valor, c.naipe);
            mvprintw(x + 1, y - 3, "  %ls  ", c.naipe);
            mvprintw(x + 2, y - 3, "  %ls%s", c.naipe, c.valor);
        } else { 
            mvprintw(x, y - 3, "%s%ls   ", c.valor, c.naipe);
            mvprintw(x + 1, y - 3, "  %ls  ", c.naipe);
            mvprintw(x + 2, y - 3, "   %s%ls", c.valor, c.naipe);
        }
        attroff(COLOR_PAIR(1));
    }
}

void fazerCartasDescarte(Carta c)
{
    if (c.naipe == paus || c.naipe == espadas) { 
        attron(COLOR_PAIR(3));
        if (strcmp(c.valor, "10") == 0) {
            mvprintw(0, 0, "%s%ls  ", c.valor, c.naipe);
            mvprintw(1, 0, "  %ls  ", c.naipe);
            mvprintw(2, 0, "  %ls%s", c.naipe, c.valor);
        } else { 
            mvprintw(0, 0, "%s%ls   ", c.valor, c.naipe);
            mvprintw(1, 0, "  %ls  ", c.naipe);
            mvprintw(2, 0, "   %s%ls", c.valor, c.naipe);
        }
        attroff(COLOR_PAIR(3));
    } else { 
        attron(COLOR_PAIR(1));
        if (strcmp(c.valor, "10") == 0) {
            mvprintw(0, 0, "%s%ls  ", c.valor, c.naipe);
            mvprintw(1, 0, "  %ls  ", c.naipe);
            mvprintw(2, 0, "  %ls%s", c.naipe, c.valor);
        } else { 
            mvprintw(0, 0, "%s%ls   ", c.valor, c.naipe);
            mvprintw(1, 0, "  %ls  ", c.naipe);
            mvprintw(2, 0, "   %s%ls", c.valor, c.naipe);
        }
        attroff(COLOR_PAIR(1));
    }
}

void fazerCartasManilha(Carta c, int x)
{
    if (c.naipe == paus || c.naipe == espadas) { 
        attron(COLOR_PAIR(3));
        mvprintw(0, x, "%s%ls   ", c.valor, c.naipe);
        mvprintw(1, x, "  %ls  ", c.naipe);
        mvprintw(2, x, "   %s%ls", c.valor, c.naipe);
        attroff(COLOR_PAIR(3));
    } else { 
        attron(COLOR_PAIR(1));
        mvprintw(0, x, "%s%ls   ", c.valor, c.naipe);
        mvprintw(1, x, "  %ls  ", c.naipe);
        mvprintw(2, x, "   %s%ls", c.valor, c.naipe);
        attroff(COLOR_PAIR(1));
    }
}

void esconderCartas(Lista *l, int x, int y)
{
    No *n = l->inicio;
    No *m = l->fim;
    if (n == NULL) { 
        printw(" ");
    } else { 
        while (n != NULL) {
            if (n != m && n->carta.flag == 0) {
                attron(A_BOLD);
                attron(COLOR_PAIR(4));
                mvprintw(x, y, "┏━━━┓");
                mvprintw(x + 1, y, "┃   ┃");
                mvprintw(x + 2, y, "┗━━━┛");
                attroff(COLOR_PAIR(4));
                attroff(A_BOLD);
            }
            m->carta.flag = 1;
            if (n->carta.flag == 1)
                fazerCartas(n->carta, x, y + 3);

            x += 1;
            n = n->prox;
        }
    }
}

void mostrarIcone(){

	attron(COLOR_PAIR(15));  
	mvprintw(0, 0, "      PACIÊNCIA     ");
	attroff(COLOR_PAIR(15));

	// segunda
	attron(COLOR_PAIR(4));  
	mvprintw(4, 5, "┗━━━┛");
	mvprintw(5, 10, "┗━━━┛");
	mvprintw(4, 10, "┗━━━┛");
	mvprintw(5, 15, "┗━━━┛");
	mvprintw(6, 15, "┗━━━┛");
	mvprintw(4, 15, "┗━━━┛");
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(1));  
	mvprintw(1, 0, "K%ls   ", ouros);
	mvprintw(2, 0, "  %ls  ", ouros);
	mvprintw(3, 0, "   %lsK", ouros);
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(7));  
	mvprintw(1, 5, "Q%ls   ", paus);
	mvprintw(2, 5, "  %ls  ", paus);
	mvprintw(3, 5, "   %lsQ", paus);
	attroff(COLOR_PAIR(7));
	
	attron(COLOR_PAIR(1));  
	mvprintw(1, 10, "J%ls   ", copas);
	mvprintw(2, 10, "  %ls  ", copas);
	mvprintw(3, 10, "   %lsJ", copas);
	attroff(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(7));  
	mvprintw(1, 15, "10%ls  ", espadas);
	mvprintw(2, 15, "  %ls  ", espadas);
	mvprintw(3, 15, "  %ls10", espadas);
	attroff(COLOR_PAIR(7));
	
}

void mostrarRanking()
{
    clear();
    refresh();
    char nome[50];
    int pontuacao = 0; int y = 1;

    FILE *arquivo;
    arquivo = fopen("ranking.txt", "r");

    mostrarIcone();

    attron(COLOR_PAIR(3));
    mvprintw(0 , 22, "Nome\t\t|Pontuação\t", nome, pontuacao);
    attroff(COLOR_PAIR(3));
    while(fscanf(arquivo, "\nNome: %s Pontuação: %d\n", nome, &pontuacao) != -1){
        attron(COLOR_PAIR(77));
        mvprintw(y,22, "%s", nome);
        mvprintw(y,40, "|%d\n", pontuacao);
        y++;
    }

    mvprintw(10, 22, "ENTER Voltar");
    attroff(COLOR_PAIR(77));
    fclose(arquivo);
    getch();
}

void mostrarInterface(Pilha **p, Jogador *j)
{
    int x = 0;

    peek(&(*p)[0], 30);
    peek(&(*p)[1], 40);
    peek(&(*p)[2], 50);
    peek(&(*p)[3], 60);
    attron(COLOR_PAIR(3));
    mvprintw(3, 30, "0%d/13", (*p)[0].numCartas);
    mvprintw(3, 40, "0%d/13", (*p)[1].numCartas);
    mvprintw(3, 50, "0%d/13", (*p)[2].numCartas);
    mvprintw(3, 60, "0%d/13", (*p)[3].numCartas);
    attroff(COLOR_PAIR(3));
    fimDoJogo(p);

    mvprintw(row - 3, 0, "Jogador: %s", j->nome);
    mvprintw(row - 2, 0, "Pontuação: %d", j->pontuacao);
    attron(COLOR_PAIR(3));
    mvprintw(row - 1, 0, "b: Voltar para o menu | Enter: seleciona carta | s: Prox. carta descarte");
    attroff(COLOR_PAIR(3));

    for (int i = 0; i < 70; i++) { 
        mvprintw(4, x, "━");
        x += 1;
    }
}

void mostrarCreditos()
{
    erase();
    refresh();
    mostrarIcone();
    attron(COLOR_PAIR(1));
    mvprintw(0, 22, "\t\tGrupo Loop\t\t");
    mvprintw(1, 22, "\t\tIntegrantes\t\t");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(2, 22, "Nome\t\tMatrícula\t" );
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(77));
    mvprintw(3, 22, "Roger Alencar\t2022130015");
    mvprintw(4, 22, "Sabrina Braga\t2022130004");
    mvprintw(5, 22, "Danilo Rosa\t2112130051");
    mvprintw(6, 22, "ENTER Voltar");
    attroff(COLOR_PAIR(77));
    getch();
}

void menu()
{
    while (true) {
        erase();
        refresh();
        mostrarIcone();
        attron(COLOR_PAIR(15));  
        mvprintw(0, 22, "    MENU   ");
	    attroff(COLOR_PAIR(15));
        attron(COLOR_PAIR(77));
        mvprintw(1, 22, "1 Novo jogo");
        mvprintw(2, 22, "2 Ranking  ");
        mvprintw(3, 22, "3 Créditos " );
        mvprintw(6, 22, "ESC Sair   ");
        attroff(COLOR_PAIR(77));

        switch (wgetch(stdscr)) { 
            case 49:
                erase();
                refresh();
                mostrarIcone();
                iniciarJogo();
                break;
            case 50:
                mostrarRanking();
                break;
            case 51:
                mostrarCreditos();
                break;
            case 27:
                endwin();
                exit(1);
            default:
                break;
        }
    }

    wclear(stdscr);
    refresh();
    wrefresh(stdscr);
}
