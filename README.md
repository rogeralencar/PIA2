# Jogo Paciência em C

 - Jogo criado para um projeto da faculdade em Estrutura de Dados.
 - Totalmente escrito em C
 - Foi utilizado as seguintes estruturas: **pilhas(1), listas encadeadas(7), lista estática(1) e lista encadeada circular(1)**
 - Para compilar o projeto: 
 > gcc main.c controles.c interface.c core.c $(ncursesw5-config --cflags) -c -g -Wall -Wextra -Wshadow<br>
 > gcc main.o controles.o interface.o core.o $(ncursesw5-config --libs) -o main<br>
 > ./main
 
 - Instalar a biblioteca Ncurses
 > sudo apt install libncurses5-dev libncursesw5-dev


