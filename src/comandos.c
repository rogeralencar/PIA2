#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"
#include "comandos.h"
#include "main.h"
#include "cartas.h"

void opcoesDoJogo(Lista **arr, Pilha **p, Lista *f){
    setlocale(LC_ALL, "");
    int opt;
    while(opt != 9){
        printf("Descarte: "); 
        recuperaInicio(f);
        printf("\n--- Manilhas ---\n");
        printf("\nManilha 1 (%d/13): ", (*p)[0].numCartas);
        peek(&(*p)[0]);
        printf("\nManilha 2 (%d/13): ", (*p)[1].numCartas);
        peek(&(*p)[1]);
        printf("\nManilha 3 (%d/13): ", (*p)[2].numCartas);
        peek(&(*p)[2]);
        printf("\nManilha 4 (%d/13): ", (*p)[3].numCartas);
        peek(&(*p)[3]);    
        printf("\n -------------- \n");
        for(int i = 0; i < 7; i++){
            printf("Array[%i]: ", i);
            mostrarCartas(&(*arr)[i]);
            printf("\n");
        }
        
        printf("\n Opção: ");
        scanf("%d%*c", &opt);
        system("clear");
        switch (opt){
        // Origem 0 - Início
        case 01:
            decrescente(&(*arr)[0], &(*arr)[1]);
            break;
        case 02:
            decrescente(&(*arr)[0], &(*arr)[2]);
            break;
        case 03:
            decrescente(&(*arr)[0], &(*arr)[3]);
            break;
        case 04:
            decrescente(&(*arr)[0], &(*arr)[4]);
            break;
        case 05:
            decrescente(&(*arr)[0], &(*arr)[5]);
            break;
        case 06:
            decrescente(&(*arr)[0], &(*arr)[6]);
            break;
        // Origem 0 - Fim
        // Origem 1 - Início
        case 10:
            decrescente(&(*arr)[1], &(*arr)[0]);
            break;
        case 12:
            decrescente(&(*arr)[1], &(*arr)[2]);
            break;
        case 13:
            decrescente(&(*arr)[1], &(*arr)[3]);
            break;
        case 14:
            decrescente(&(*arr)[1], &(*arr)[4]);
            break;
        case 15:
            decrescente(&(*arr)[1], &(*arr)[5]);
            break;
        case 16:
            decrescente(&(*arr)[1], &(*arr)[6]);
            break;
        // Origem 1 - Fim
        // Origem 2 - Início
        case 20:
            decrescente(&(*arr)[2], &(*arr)[0]);
            break;
        case 21:
            decrescente(&(*arr)[2], &(*arr)[1]);
        break;
        case 23:
            decrescente(&(*arr)[2], &(*arr)[3]);
            break;
        case 24:
            decrescente(&(*arr)[2], &(*arr)[4]);
            break;
        case 25:
            decrescente(&(*arr)[2], &(*arr)[5]);
            break;
        case 26:
            decrescente(&(*arr)[2], &(*arr)[6]);
            break;
        // Origem 2 - Fim
        // Origem 3 - Início
        case 30:
            decrescente(&(*arr)[3], &(*arr)[0]);
            break;
        case 31:
            decrescente(&(*arr)[3], &(*arr)[1]);
            break;
        case 32:
            decrescente(&(*arr)[3], &(*arr)[2]);
            break;
        case 33:
            decrescente(&(*arr)[3], &(*arr)[3]);
            break;
        case 34:
            decrescente(&(*arr)[3], &(*arr)[4]);
            break;
        case 35:
            decrescente(&(*arr)[3], &(*arr)[5]);
            break;
        case 36:
            decrescente(&(*arr)[3], &(*arr)[6]);
            break;
        // Origem 3 - Fim
        // Origem 4 - Início
        case 40:
            decrescente(&(*arr)[4], &(*arr)[0]);
            break;
        case 41:
            decrescente(&(*arr)[4], &(*arr)[1]);
            break;
        case 42:
            decrescente(&(*arr)[4], &(*arr)[2]);
            break;
        case 43:
            decrescente(&(*arr)[4], &(*arr)[3]);
            break;
        case 44:
            decrescente(&(*arr)[4], &(*arr)[4]);
            break;
        case 45:
            decrescente(&(*arr)[4], &(*arr)[5]);
            break;
        case 46:
            decrescente(&(*arr)[4], &(*arr)[6]);
            break;
        // Origem 4 - Fim
        // Origem 5 - Inicio
        case 50:
            decrescente(&(*arr)[5], &(*arr)[0]);
            break;
        case 51:
            decrescente(&(*arr)[5], &(*arr)[1]);
            break;
        case 52:
            decrescente(&(*arr)[5], &(*arr)[2]);
            break;
        case 53:
            decrescente(&(*arr)[5], &(*arr)[3]);
            break;
        case 54:
            decrescente(&(*arr)[5], &(*arr)[4]);
            break;
        case 55:
            decrescente(&(*arr)[5], &(*arr)[5]);
            break;
        case 56:
            decrescente(&(*arr)[5], &(*arr)[6]);
            break;
        // Origem 5 - Fim
        // Origem 6 - Inicio
        case 60:
            decrescente(&(*arr)[6], &(*arr)[0]);
            break;
        case 61:
            decrescente(&(*arr)[6], &(*arr)[1]);
            break;
        case 62:
            decrescente(&(*arr)[6], &(*arr)[2]);
            break;
        case 63:
            decrescente(&(*arr)[6], &(*arr)[3]);
            break;
        case 64:
            decrescente(&(*arr)[6], &(*arr)[4]);
            break;
        case 65:
            decrescente(&(*arr)[6], &(*arr)[5]);
            break;
        case 66:
            decrescente(&(*arr)[6], &(*arr)[6]);
            break;
        // Origem 6 - Fim
        // Inserir cartas na manilha 1
        case 410:
            crescenteManilha(&(*p)[0], &(*arr)[0]);
            break;
        case 411:
            crescenteManilha(&(*p)[0], &(*arr)[1]);
            break;
        case 412:
            crescenteManilha(&(*p)[0], &(*arr)[2]);
            break;
        case 413:
            crescenteManilha(&(*p)[0], &(*arr)[3]);
            break;
        case 414:
            crescenteManilha(&(*p)[0], &(*arr)[4]);
            break;
        case 415:
            crescenteManilha(&(*p)[0], &(*arr)[5]);
            break;
        case 416:
            crescenteManilha(&(*p)[0], &(*arr)[6]);
            break;
        // Inserir cartas na manilha 2
        case 420:
            crescenteManilha(&(*p)[1], &(*arr)[0]);
            break;
        case 421:
            crescenteManilha(&(*p)[1], &(*arr)[1]);
            break;
        case 422:
            crescenteManilha(&(*p)[1], &(*arr)[2]);
            break;
        case 423:
            crescenteManilha(&(*p)[1], &(*arr)[3]);
            break;
        case 424:
            crescenteManilha(&(*p)[1], &(*arr)[4]);
            break;
        case 425:
            crescenteManilha(&(*p)[1], &(*arr)[5]);
            break;
        case 426:
            crescenteManilha(&(*p)[1], &(*arr)[6]);
            break;
        // Inserir cartas na manilha 3
        case 430:
            crescenteManilha(&(*p)[2], &(*arr)[0]);
            break;
        case 431:
            crescenteManilha(&(*p)[2], &(*arr)[1]);
            break;
        case 432:
            crescenteManilha(&(*p)[2], &(*arr)[2]);
            break;
        case 433:
            crescenteManilha(&(*p)[2], &(*arr)[3]);
            break;
        case 434:
            crescenteManilha(&(*p)[2], &(*arr)[4]);
            break;
        case 435:
            crescenteManilha(&(*p)[2], &(*arr)[5]);
            break;
        case 436:
            crescenteManilha(&(*p)[2], &(*arr)[6]);
            break;
        // Inserir cartas na manilha 4
        case 440:
            crescenteManilha(&(*p)[3], &(*arr)[0]);
            break;
        case 441:
            crescenteManilha(&(*p)[3], &(*arr)[1]);
            break;
        case 442:
            crescenteManilha(&(*p)[3], &(*arr)[2]);
            break;
        case 443:
            crescenteManilha(&(*p)[3], &(*arr)[3]);
            break;
        case 444:
            crescenteManilha(&(*p)[3], &(*arr)[4]);
            break;
        case 445:
            crescenteManilha(&(*p)[3], &(*arr)[5]);
            break;
        case 446:
            crescenteManilha(&(*p)[3], &(*arr)[6]);
            break;
        // Fim das cartas nas manilhas
        // Mover mais de uma carta - 0 para outras listas
        case 501:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[1]);
            break;
        case 502:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[2]);
            break;
        case 503:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[3]);
            break;
        case 504:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[4]);
            break;
        case 505:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[5]);
            break;
        case 506:
            decrescenteMoverMaisCartas(&(*arr)[0], &(*arr)[6]);
            break;
        // Mover mais cartas - Origem 1 - para qualquer lista
        case 512:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[2]);
            break;
        case 513:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[3]);
            break;
        case 514:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[4]);
            break;
        case 515:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[5]);
            break;
        case 516:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[6]);
            break;
        case 510:
            decrescenteMoverMaisCartas(&(*arr)[1], &(*arr)[0]);
            break;
        // Mover mais cartas - Origem 2 - para qualquer lista
        case 520:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[0]);
            // trocarElementosMaisCartas(&(*arr)[2], &(*arr)[0]);
            break;
        case 521:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[1]);
            break;
        case 523:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[3]);
            break;
        case 524:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[4]);
            break;
        case 525:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[5]);
            break;
        case 526:
            decrescenteMoverMaisCartas(&(*arr)[2], &(*arr)[6]);
            break;
        // Mover mais cartas - Origem 3 - para qualquer lista
        case 530:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[0]);
            break;
        case 531:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[1]);
            break;
        case 532:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[2]);
            break;
        case 534:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[4]);
            break;
        case 535:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[5]);
            break;
        case 536:
            decrescenteMoverMaisCartas(&(*arr)[3], &(*arr)[6]);
            break;
        // Mover mais cartas - Origem 4 - para qualquer lista
        case 540:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[0]);
            break;
        case 541:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[1]);
            break;
        case 542:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[2]);
            break;
        case 543:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[3]);
            break;
        case 545:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[5]);
            break;
        case 546:
            decrescenteMoverMaisCartas(&(*arr)[4], &(*arr)[6]);
            break;
        // Mover mais cartas - Origem 5 - para qualquer lista
        case 550:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[0]);
            break;
        case 551:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[1]);
            break;
        case 552:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[2]);
            break;
        case 553:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[3]);
            break;
        case 554:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[4]);
            break;
        case 556:
            decrescenteMoverMaisCartas(&(*arr)[5], &(*arr)[6]);
            break;
        // Mover mais cartas - Origem 6 - para qualquer lista
        case 560:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[0]);
            break;
        case 561:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[1]);
            break;
        case 562:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[2]);
            break;
        case 563:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[3]);
            break;
        case 564:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[4]);
            break;
        case 565:
            decrescenteMoverMaisCartas(&(*arr)[6], &(*arr)[5]);
            break;
        // Fim do mover mais de uma carta
        case 77:
            enfileiraFim(f, desenfileira(f));
            break;
        // Do descarte para as manilhas
        case 701:
            crescenteManilhaDireto(&(*p)[0], f);
            break;
        case 702:
            crescenteManilhaDireto(&(*p)[1], f);
            break;
        case 703:
            crescenteManilhaDireto(&(*p)[2], f);
            break;
        case 704:
            crescenteManilhaDireto(&(*p)[3], f);
            break;
        // Fim
        case 710:
            decrescenteComprar(&(*arr)[0], f);
            break;
        case 711:
            decrescenteComprar(&(*arr)[1], f);
            break;
        case 712:
            decrescenteComprar(&(*arr)[2], f);
            break;
        case 713:
            decrescenteComprar(&(*arr)[3], f);
            break;
        case 714:
            decrescenteComprar(&(*arr)[4], f);
            break;
        case 715:
            decrescenteComprar(&(*arr)[5], f);
            break;
        case 716:
            decrescenteComprar(&(*arr)[6], f);
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Comando inválido!\n");
            break;
        }
    }
}
