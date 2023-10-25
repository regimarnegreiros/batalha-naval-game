#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {

    while (1) {
        system("cls");
        /*MENU*/
        int dificuldade, tentativas;
        int qNavio[5];
        int menu = 0;
        int escolhaMenu = 0;
        int escolhaMenuDificuldade = 0;
        while (menu == 0) {
            printf("\nBem-vindo ao jogo de batalha naval!\n\n");
            printf("1. Jogar\n2. Creditos\n3. Sair\n\nEscolha uma opcao: ");
            scanf("%i", &escolhaMenu);

            switch(escolhaMenu) {
                case 1:
                    system("cls");
                    escolhaMenuDificuldade = 0;
                    while(escolhaMenuDificuldade == 0) {
                        printf("\nSelecione uma dificuldade abaixo:\n\n1. Facil\n2. Medio\n3. Dificil\n\n4. Voltar para o menu principal\n\nEscolha uma opcao: ");
                        scanf("%i", &dificuldade);
                        
                        switch (dificuldade) {
                            case 1: // facil
                                qNavio[4] = 3;
                                qNavio[3] = 3;
                                qNavio[2] = 3;
                                qNavio[1] = 3;
                                qNavio[0] = 3;
                                tentativas = 9;

                                menu = 1;
                                escolhaMenuDificuldade = 1;
                                break;
                            case 2: // medio
                                qNavio[4] = 2;
                                qNavio[3] = 2;
                                qNavio[2] = 2;
                                qNavio[1] = 2;
                                qNavio[0] = 2;
                                tentativas = 6;
                                
                                menu = 1;
                                escolhaMenuDificuldade = 2;
                                break;
                            case 3: // dificil
                                qNavio[4] = 1;
                                qNavio[3] = 1;
                                qNavio[2] = 1;
                                qNavio[1] = 1;
                                qNavio[0] = 1;
                                tentativas = 3;
                                
                                menu = 1;
                                escolhaMenuDificuldade = 3;
                                break;
                            case 4: // menu principal
                                escolhaMenuDificuldade = 4;
                                system("cls");
                                break;
                            default:
                                system("cls");
                                printf("\nOpcao invalida. Tente novamente!\n");
                                while (getchar() != '\n');
                        }
                    }
                    break;
                case 2:
                    system("cls");
                    printf("Desenvolvido por: Regimar de Deus Negreiros\n\n");
                    printf("Pressione enter para voltar ao menu principal.\n");
                    getchar();
                    getchar();
                    system("cls");
                    break;
                case 3:
                    return 0;
                default:
                    system("cls");
                    printf("\nOpcao invalida. Tente novamente!\n");
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

        char matriz_navios[10][10];

        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                matriz_navios[i][j] = 'O';
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
                                        if (i == 0 && 1+i == navio[tipoNavio][1]) {
                                            matriz_navios[x][y] = 'X';
                                        } else if (i == 0) {
                                            matriz_navios[x][y] = '<';
                                        } else if (1+i == navio[tipoNavio][1]) {
                                            matriz_navios[x][i + y] = '>';
                                        } else {
                                            matriz_navios[x][i + y] = '-';
                                        }
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
                                        if (j == 0 && 1+j == navio[tipoNavio][1]) {
                                            matriz_navios[x][y] = 'X';
                                        } else if (j == 0) {
                                            matriz_navios[x][y] = '^';
                                        } else if (1+j == navio[tipoNavio][1]) {
                                            matriz_navios[j + x][y] = 'v';
                                        } else {
                                            matriz_navios[j + x][y] = '|';
                                        }
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

        printf(" ");
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                printf("  %c", matriz_navios[i][j]);
            }
            printf("\n ");
        }
        printf("\n");
        getchar();
        getchar();
        */

        char linha;
        int linhaInt, coluna, digitouCorreto, k, aindaTemNavio;
        char matriz_escondida[10][10];
        
        /*CRIA A MATRIZ ESCONDIDA*/
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                matriz_escondida[i][j] = '*';
            }
        }
        
        int naviosEliminados = -1;
        int tentativasAnterior = -1;
        int naviosEliminadosAnterior = -1;

        do {
            /*VERIFICA SE UM NAVIO FOI COMPLETAMENTE ELIMINADO*/
            naviosEliminadosAnterior = naviosEliminados;
            naviosEliminados = 0;
            for (k = 1; k <= numDoNavio; k++) {
                aindaTemNavio = 0;
                for(i = 0; i < 10; i++) {
                    for(j = 0; j < 10; j++) {
                        if (matriz_padrao[i][j] == k) {
                            aindaTemNavio = 1;
                        }
                    }
                }
                if (aindaTemNavio == 0) {
                    naviosEliminados++;
                }
            }
            
            system("cls");
            if (escolhaMenuDificuldade == 1) {
                printf("\nVoce esta jogando na dificuldade FACIL.\n\n");
            } else if (escolhaMenuDificuldade == 2) {
                printf("\nVoce esta jogando na dificuldade MEDIA.\n\n");
            } else if (escolhaMenuDificuldade == 3) {
                printf("\nVoce esta jogando na dificuldade DIFICIL.\n\n");
            } else {
                printf("\nErro na escolha de dificuldade!\n\n");
            }

            printf("   0  1  2  3  4  5  6  7  8  9\n");
            for(i = 0; i < 10; i++) {
                printf("%c  ", i + 65);
                for(j = 0; j < 10; j++) {
                    printf("%c  ", matriz_escondida[i][j]);
                }
                printf("\n");
            }
            printf("\nTentativas restantes: %i\n", tentativas);
            printf("Navios restantes: %i\n\n", numDoNavio - naviosEliminados);

            
            if (tentativas == 0) {
                tentativas--;
            }

            if (tentativasAnterior == -1 && naviosEliminadosAnterior == -1) {
                printf("Essa e sua primeira jogada!\n\n");
            } else if (tentativasAnterior > tentativas) {
                printf("Voce acertou na agua!\n\n");
            } else if (naviosEliminadosAnterior < naviosEliminados) {
                printf("Voce eliminou um navio por completo!\n\n");
            } else {
                printf("Voce acertou uma parte de um navio\n\n");
            }
            
            if (tentativas > 0 && naviosEliminados < numDoNavio) {
                /*RECOLHE A CORDENADA DIGITADA PELO USUARIO*/
                digitouCorreto = 0;
                while(digitouCorreto == 0) {
                    printf("Insira uma letra de A a J e um numero de 0 a 9 (Ex: a1 ou A1):\n");
                    scanf(" %c%i", &linha, &coluna);
                    printf("\n");

                    linha = tolower(linha);
                    linhaInt = linha - 'a';

                    if (linhaInt >= 0 && linhaInt <= 9 && coluna >= 0 && coluna <= 9) {
                        // digitou corretamente
                        if (matriz_escondida[linhaInt][coluna] != matriz_navios[linhaInt][coluna]) {
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
                matriz_escondida[linhaInt][coluna] = matriz_navios[linhaInt][coluna];
                tentativasAnterior = tentativas;
                if (matriz_padrao[linhaInt][coluna] == 0) {
                    tentativas--;
                }

                /*SUBSTITUI A POSICAO QUE O USUARIO DIGITOU POR 0*/
                matriz_padrao[linhaInt][coluna] = 0;
            }

        } while (tentativas > -1 && naviosEliminados < numDoNavio);

        if (naviosEliminados == 0) {
            printf("VOCE NAO ELIMINOU NENHUM DOS %i NAVIOS!!!\n\n", numDoNavio);
        } else if (tentativas <= 0) {
            printf("SUAS TENTATIVAS ACABARAM, VOCE ELIMINOU %i/%i NAVIOS!\n\n", naviosEliminados, numDoNavio);
        } else {
            printf("PARABENS VOCE ELMINOU TODOS OS %i NAVIOS!!!\n\n", numDoNavio);
        }

        printf("Pressione enter para voltar ao menu principal.\n");
        getchar();
        getchar();
    }

    return 0;
}