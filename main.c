#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    /*CRIANDO A TABELA ZERADA*/

    int matriz_padrao[10][10];
    int i, j;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            matriz_padrao[i][j] = 0;
            // printf("%i ", matriz_padrao[i][j]);
        }
        // printf("\n");   
    }

    /*SELECIONANDO A POSICAO DOS NAVIOS*/

    /*quantidade / tamanho*/
    int navio5[2] = {1, 5};

    srand(time(NULL));
    int x = rand() % 10;
    int y = rand() % 10;

    /*0 horizontal / 1 vertical*/
    int horizontalVertical = rand() % 2;
    //horizontalVertical = 0;
    
    printf("\n%i %i %i\n\n", x, y, horizontalVertical);

    /*verifica se o navio cabe na matriz e se nao esta sobrepondo outros navios*/

    int taSobrepondo = 0;

    switch (horizontalVertical) {
        case 0: //Horizontal
            while (1) {
                taSobrepondo = 0;
                if (navio5[1] + y < 10) {
                    for(i = 0; i < navio5[1]; i++) {
                        taSobrepondo = matriz_padrao[x][i + y] == 1;
                    }
                    if (taSobrepondo == 0) {
                        for(i = 0; i < navio5[1]; i++) {
                            matriz_padrao[x][i + y] = 1;
                        }
                        break;
                    } else {
                        x = rand() % 10;
                        y = rand() % 10;
                    }
                } else {
                    x = rand() % 10;
                    y = rand() % 10;
                }
            }
            taSobrepondo = 0;
        break;

        case 1: //Vertical
            while (1) {
                taSobrepondo = 0;
                if (navio5[1] + x < 10) {
                    for(j = 0; j < navio5[1]; j++) {
                        taSobrepondo = matriz_padrao[j + x][y] == 1;
                    }
                    if (taSobrepondo == 0) {
                        for(j = 0; j < navio5[1]; j++) {
                            matriz_padrao[j + x][y] = 1;
                        }
                        break;
                    } else {
                        x = rand() % 10;
                        y = rand() % 10;
                    }
                } else {
                    x = rand() % 10;
                    y = rand() % 10;
                }
            }
            taSobrepondo = 0;
        break;

        default:
        printf("Erro no switch case");
    }

    // matriz_padrao[x][y] = 1;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%i  ", matriz_padrao[i][j]);
        }
        printf("\n");   
    }


    return 0;
}