#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    char jogarNovamente;
    do {
        /*MENU*/
        int dificuldade, tentativas;
        int qNavio[5];
        int menu = 0;
        while (menu == 0) {
            printf("\nBem-vindo ao jogo de batalha naval!\n\n");
            printf("Selecione uma dificuldade abaixo:\n1 - Facil\n2 - Medio\n3 - Dificil\n\nDigite Aqui: ");
            scanf("%i", &dificuldade);
            
            switch (dificuldade) {
                case 1: // facil
                    printf("\nVoce selecionou a dificuldade facil!\n\n");
                    qNavio[4] = 3;
                    qNavio[3] = 3;
                    qNavio[2] = 3;
                    qNavio[1] = 3;
                    qNavio[0] = 3;
                    tentativas = 9;

                    menu = 1;
                    break;
                case 2: // medio
                    printf("\nVoce selecionou a dificuldade media!\n\n");
                    qNavio[4] = 2;
                    qNavio[3] = 2;
                    qNavio[2] = 2;
                    qNavio[1] = 2;
                    qNavio[0] = 2;
                    tentativas = 6;
                    
                    menu = 1;
                    break;
                case 3: // dificil
                    printf("\nVoce selecionou a dificuldade DIFICIL!\n\n");
                    qNavio[4] = 1;
                    qNavio[3] = 1;
                    qNavio[2] = 1;
                    qNavio[1] = 1;
                    qNavio[0] = 1;
                    tentativas = 3;
                    
                    menu = 1;
                    break;
                default:
                    printf("OPCAO INVAILIDA!!!");
                    while (getchar() != '\n');
            }
        }


        /*CRIANDO A TABELA ZERADA*/

        int matriz_padrao[10][10];
        int i, j;

        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                matriz_padrao[i][j] = 0;
            } 
        }

        /*SELECIONANDO A POSICAO DOS NAVIOS*/

        /*quantidade / tamanho de navios*/
        int navio[5][2] = {
            {qNavio[4], 5},
            {qNavio[3], 4},
            {qNavio[2], 3},
            {qNavio[1], 2},
            {qNavio[0], 1}
        };
        

        srand(time(NULL));
        int x;
        int y;
        int horizontalVertical;
        
        int tipoNavio, numNavio, numDoNavio;
        numDoNavio = 0;

        for(tipoNavio = 0; tipoNavio < 5; tipoNavio++) {
            for(numNavio = 0; numNavio < navio[tipoNavio][0]; numNavio++) {
                x = rand() % 10;
                y = rand() % 10;
                /*0 horizontal / 1 vertical*/
                horizontalVertical = rand() % 2;


                /*verifica se o navio cabe na matriz e se nao esta sobrepondo outros navios*/

                int taSobrepondo = 0;

                switch (horizontalVertical) {
                    case 0: //Horizontal
                        while (1) {
                            taSobrepondo = 0;
                            if (navio[tipoNavio][1] + y < 10) {
                                for(i = 0; i < navio[tipoNavio][1]; i++) {
                                    if(matriz_padrao[x][i + y] >= 1) {
                                        taSobrepondo = 1;
                                    }
                                }
                                if (taSobrepondo == 0) {
                                    numDoNavio++;
                                    for(i = 0; i < navio[tipoNavio][1]; i++) {
                                        matriz_padrao[x][i + y] = numDoNavio;
                                    }
                                    break;
                                } else {
                                    x = rand() % 10;
                                    y = rand() % 10;
                                    horizontalVertical = rand() % 2;
                                }
                            } else {
                                x = rand() % 10;
                                y = rand() % 10;
                                horizontalVertical = rand() % 2;
                            }
                        }
                        taSobrepondo = 0;
                        break;

                    case 1: //Vertical
                        while (1) {
                            taSobrepondo = 0;
                            if (navio[tipoNavio][1] + x < 10) {
                                for(j = 0; j < navio[tipoNavio][1]; j++) {
                                    if(matriz_padrao[j + x][y] >= 1) {
                                        taSobrepondo = 1;
                                    }
                                }
                                if (taSobrepondo == 0) {
                                    numDoNavio++;
                                    for(j = 0; j < navio[tipoNavio][1]; j++) {
                                        matriz_padrao[j + x][y] = numDoNavio;
                                    }
                                    break;
                                } else {
                                    x = rand() % 10;
                                    y = rand() % 10;
                                    horizontalVertical = rand() % 2;
                                }
                            } else {
                                x = rand() % 10;
                                y = rand() % 10;
                                horizontalVertical = rand() % 2;
                            }
                        }
                        taSobrepondo = 0;
                        break;
                    default:
                    printf("Erro no switch case");
                }
            }   
        }

        /*
        printf(" ");
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                printf("%3i", matriz_padrao[i][j]);
            }
            printf("\n ");   
        }
        printf("\n");
        */
        
        char linha;
        int linhaInt, coluna, digitouCorreto, k, temTodosOsNaviosAinda;
        char matriz_escondida[10][10];
        
        /*CRIA A MATRIZ ESCONDIDA*/
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                matriz_escondida[i][j] = '*';
            }
        }

        while(tentativas > 0) {
            printf("   0  1  2  3  4  5  6  7  8  9\n");
            for(i = 0; i < 10; i++) {
                printf("%c  ", i + 65);
                for(j = 0; j < 10; j++) {
                    printf("%c  ", matriz_escondida[i][j]);
                }
                printf("\n");
            }
            printf("\nRestam %i tentativas\n\n", tentativas);
            
            /*RECOLHE A CORDENADA DIGITADA PELO USUARIO*/
            digitouCorreto = 0;
            while(digitouCorreto == 0) {
                printf("Insira uma letra de A a J e um numero de 0 a 9 (Ex: a1 ou A1):\n");
                scanf(" %c%i", &linha, &coluna);
                printf("\n");

                linha = tolower(linha);
                linhaInt = linha - 'a';

                if (linhaInt >= 0 && linhaInt <= 9 && coluna >= 0 && coluna <= 9) {
                    // printf("\nVoce digitou corretamente\n\n");
                    if (matriz_escondida[linhaInt][coluna] != 'O' && matriz_escondida[linhaInt][coluna] != '#') {
                        digitouCorreto = 1;
                    } else {
                        printf("VOCE JA SELECIONOU ESSA COORDENADA\n\n");
                        while (getchar() != '\n');
                    }
                } else {
                    printf("VOCE DIGITOU INCORRETAMENTE!\n\n");
                    while (getchar() != '\n');
                }
            }

            /*VERIFICA SE A POSICAO POSSUI NAVIO OU NAO*/
            if (matriz_padrao[linhaInt][coluna] == 0) {
                matriz_escondida[linhaInt][coluna] = 'O';
                tentativas--;
            } else {
                matriz_escondida[linhaInt][coluna] = '#';
            }

            /*SUBSTITUI A POSICAO QUE O USUARIO DIGITOU POR 0*/
            matriz_padrao[linhaInt][coluna] = 0;

            /*VERIFICA SE UM NAVIO FOI COMPLETAMENTE ELIMINADO*/
            for (k = 1; k <= numDoNavio; k++) {
                temTodosOsNaviosAinda = 0;
                for(i = 0; i < 10; i++) {
                    for(j = 0; j < 10; j++) {
                        if (matriz_padrao[i][j] == k) {
                            temTodosOsNaviosAinda = 1;
                        }
                    }
                }
                if (temTodosOsNaviosAinda == 0) {
                    break;
                }
            }
            if (temTodosOsNaviosAinda == 0) {
                break;
            }
        }

        if (tentativas <= 0) {
            printf("VOCE PERDEU!\n\n");
        } else {
            printf("PARABENS VOCE GANHOU!!!\n\n");
        }

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
        while (getchar() != '\n');
        
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    return 0;
}