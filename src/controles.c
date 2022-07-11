#include <ncurses.h>
#include <curses.h>
#include "controles.h"

void opcoesDoJogo(int tamEscolhas, Lista **arr, Pilha **p, Lista *f, Jogador *j)
{
    int highlight = 0;
    int numEscolhas = 10;
    int escolhas = 0;
    int opt = 0;
    int cont = 0;
    int posicoes[2];

    while(opt != 9) {
        erase();
        refresh();
        int k = 0;
        
        for (int v = 0; v < 7; v++) { 
            escolhas = numEscolhas * v;
            if(v == highlight){
                attron(COLOR_PAIR(6));
                mvprintw(5,  escolhas, "  %d  ", highlight);        
                attroff(COLOR_PAIR(6));
            }
            else 
                mvprintw(5, -escolhas, " ");   
            
            esconderCartas(&(*arr)[v], 6, k);
            k += 10;
        }

        mostrarInterface(p, j);
        recuperaInicio(f);
        
        if (cont == 0)
            mvwprintw(stdscr, row - 4, 0, "Coluna: 0 -> 0");
        else 
            mvwprintw(stdscr, row - 4, 0, "Coluna: %d -> %d", posicoes[0], highlight);

        switch (wgetch(stdscr)) {
            case KEY_LEFT:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_RIGHT:
                highlight++;
                if(highlight == tamEscolhas)
                    highlight = tamEscolhas - 1;
                break;
            case 's': // Próxima carta do descarte
                enfileiraFim(f, desenfileira(f));
                break;
            case 'd': // Comprar a carta do descarte para uma coluna
                decrescenteComprar(&(*arr)[highlight], f, j);
                break;
            case 'q': // Descarte -> manilha 1
                crescenteManilhaDireto(&(*p)[0], f, j);
                break;
            case 'w': // Descarte -> manilha 2
                crescenteManilhaDireto(&(*p)[1], f, j);
                break;
            case 'e': // Descarte -> manilha 3
                crescenteManilhaDireto(&(*p)[2], f, j);
                break;
            case 'r': // Descarte -> manilha 4
                crescenteManilhaDireto(&(*p)[3], f, j);
                break;
            case 'b': // Voltar para o menu inicial.
                ranking(j);
                main();
                break;
            case 49: // Manilha 1
                crescenteManilha(&(*p)[0], &(*arr)[highlight], j);
                break;
            case 50: // Manilha 2
                crescenteManilha(&(*p)[1], &(*arr)[highlight], j);
                break;
            case 51: // Manilha 3
                crescenteManilha(&(*p)[2], &(*arr)[highlight], j);
                break;
            case 52: // Manilha 4
                crescenteManilha(&(*p)[3], &(*arr)[highlight], j);
                break;
            case ' ': // Mover mais de uma carta 
                posicoes[cont] = highlight;
                cont++;
                if(cont == 2){ 
                    decrescenteMoverMaisCartas(&(*arr)[posicoes[0]], &(*arr)[posicoes[1]], j);
                    cont = 0;
                    posicoes[cont] = 0;
                }
                break;
            case 10: // Mover uma carta para determinada coluna.
                posicoes[cont] = highlight;
                cont++;
                if(cont == 2){ 
                    decrescente(&(*arr)[posicoes[1]], &(*arr)[posicoes[0]], j);
                    cont = 0;
                }
                break;
            case 27: 
                posicoes[2] = 0;
                cont = 0; 
                break;
            default:
                break;
        }
    }

    wclear(stdscr);
    refresh();
    wrefresh(stdscr);
}