#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>

#define linhas 8
#define colunas 8

void inicializarTabuleiro(char tabuleiro[linhas][colunas]) {
    tabuleiro[0][0] = 'T';
    tabuleiro[0][1] = 'C';
    tabuleiro[0][2] = 'B';
    tabuleiro[0][3] = 'R';
    tabuleiro[0][4] = 'K';
    tabuleiro[0][5] = 'B';
    tabuleiro[0][6] = 'C';
    tabuleiro[0][7] = 'T';
    
    for (int j = 0; j < 8; ++j) {
        tabuleiro[1][j] = 'P';
    }
    
    tabuleiro[7][0] = 't';
    tabuleiro[7][1] = 'c';
    tabuleiro[7][2] = 'b';
    tabuleiro[7][3] = 'k';
    tabuleiro[7][4] = 'r';
    tabuleiro[7][5] = 'b';
    tabuleiro[7][6] = 'c';
    tabuleiro[7][7] = 't';
    
    for (int j = 0; j < 8; ++j) {
        tabuleiro[6][j] = 'p';
    }
    
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            tabuleiro[i][j] = '-';
        }
    }
}

void exibirTabuleiro(char tabuleiro[linhas][colunas]) {
    // Exibir os números das colunas
    printf("  ");
    for (int i = 0; i < colunas; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");
    
    // Exibir o tabuleiro do jogo
    for (int i = 0; i < linhas; ++i) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < colunas; ++j) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void vezPreto(char tabuleiro[linhas][colunas]) {
    int linha, coluna, linha_antiga, coluna_antiga, peca_movida, i, contador;
    char c, continuar;

    do {
        printf("Digite qual linha e coluna que quer mover: ");
        scanf(" %c %d", &c, &coluna);
        linha = c - 'A';
        coluna--;
        linha_antiga = linha;
        coluna_antiga = coluna;
        peca_movida = 0;
        continuar = 'N';

        if (tabuleiro[linha][coluna] == 'C') {
            do {
                printf("Você quer mover o Cavalo para que posição? ");
                scanf(" %c %d", &c, &coluna);
                linha = c - 'A';
                coluna--;

                if ((linha == linha_antiga + 2 && coluna == coluna_antiga + 1) || (linha == linha_antiga + 1 && coluna == coluna_antiga + 2) ||
                    (linha == linha_antiga - 1 && coluna == coluna_antiga + 2) || (linha == linha_antiga - 2 && coluna == coluna_antiga + 1) ||
                    (linha == linha_antiga - 2 && coluna == coluna_antiga - 1) || (linha == linha_antiga - 1 && coluna == coluna_antiga - 2) ||
                    (linha == linha_antiga + 1 && coluna == coluna_antiga - 2) || (linha == linha_antiga + 2 && coluna == coluna_antiga - 1)) {

                    if (tabuleiro[linha][coluna] != 'P' && tabuleiro[linha][coluna] != 'T' && tabuleiro[linha][coluna] != 'C' &&
                        tabuleiro[linha][coluna] != 'B' && tabuleiro[linha][coluna] != 'R' && tabuleiro[linha][coluna] != 'K') {

                        if (tabuleiro[linha][coluna] == '-') {
                            printf("Peça movida com sucesso.\n");
                            tabuleiro[linha][coluna] = 'C';
                            tabuleiro[linha_antiga][coluna_antiga] = '-';
                            peca_movida++;
                            break;
                        } else {
                            printf("Posição inexistente ou ocupada.\n");
                            printf("Ainda quer usar o cavalo? S/N \n");
                            scanf(" %c", &continuar);
                        }
                    } else {
                        printf("Uma peça sua já está ocupando esse lugar\n");
                        printf("Ainda quer usar o cavalo? S/N\n");
                        scanf(" %c", &continuar);
                    }
                } else {
                    printf("Movimento inválido para o Cavalo.\n");
                    printf("Ainda quer usar o cavalo? S/N \n");
                    scanf(" %c", &continuar);
                }
            }while (continuar == 'S');
        }
        if (tabuleiro[linha][coluna] == 'P') {
            do {
                printf("Você quer mover o Peão para que posição? ");
                scanf(" %c %d", &c, &coluna);
                linha = c - 'A';
                coluna--;
                if ((linha == linha_antiga + 1 && coluna == coluna_antiga + 1) || (linha == linha_antiga + 1 && coluna == coluna_antiga -1)){
					if ((tabuleiro[linha][coluna] == 'p') || (tabuleiro[linha][coluna] == 'b') || (tabuleiro[linha][coluna] == 'c') || (tabuleiro[linha][coluna] == 't') || (tabuleiro[linha][coluna] == 'k') || (tabuleiro[linha][coluna] == 'r')){
						printf("Peça movida com sucesso.\n");
                        tabuleiro[linha][coluna] = 'P';
                        tabuleiro[linha_antiga][coluna_antiga] = '-';
                        peca_movida++;
                        break;
                	}
                	else if(tabuleiro[linha][coluna] == '-'){
						printf("Movimento inválido para o Peão.\n");
						printf("Ainda quer usar o Peão? S/N\n");
						scanf(" %c", &continuar);
					}
                	else{
                		printf("Posição inexistente ou ocupada por uma de suas peças.\n");
                		printf("Ainda quer usar o Peão? S/N \n");
                        scanf(" %c", &continuar);                		
					}
				}
            	else if (linha == linha_antiga + 1 && coluna == coluna_antiga){
                    if (tabuleiro[linha][coluna] == '-') {
                        printf("Peça movida com sucesso.\n");
                        tabuleiro[linha][coluna] = 'P';
                        tabuleiro[linha_antiga][coluna_antiga] = '-';
                        peca_movida++;
                        break;
                    } else {
                        printf("Posição inexistente ou ocupada.\n");
                        printf("Ainda quer usar o Peão? S/N \n");
                        scanf(" %c", &continuar);
                    }
                }
            	else{
                    	printf("Movimento inválido para o Peão.\n");
                    	printf("Ainda quer usar o Peão? S/N \n");
                    	scanf(" %c", &continuar);
            }				
            }while (continuar == 'S');
		}
			if (tabuleiro[linha][coluna] == 'K') {
            do {
                printf("Você quer mover o Rei para que posição? ");
                scanf(" %c %d", &c, &coluna);
                linha = c - 'A';
                coluna--;
                if ((linha < linha_antiga + 2) && (linha > linha_antiga - 2) && (coluna < coluna_antiga + 2) && (coluna > coluna_antiga - 2)){
					if (tabuleiro[linha][coluna] != 'P' && tabuleiro[linha][coluna] != 'T' && tabuleiro[linha][coluna] != 'C' &&
                        tabuleiro[linha][coluna] != 'B' && tabuleiro[linha][coluna] != 'R' && tabuleiro[linha][coluna] != 'K') {
                        if (tabuleiro[linha][coluna] == '-') {
                            printf("Peça movida com sucesso.\n");
                            tabuleiro[linha][coluna] = 'K';
                            tabuleiro[linha_antiga][coluna_antiga] = '-';
                            peca_movida++;
                            break;
                        } else {
                            printf("Posição inexistente ou ocupada.\n");
                            printf("Ainda quer usar o Rei? S/N \n");
                            scanf(" %c", &continuar);
                        }
                    }	else {
                        	printf("Uma peça sua já está ocupando esse lugar\n");
                        	printf("Ainda quer usar o Rei? S/N\n");
                        	scanf(" %c", &continuar);
                    }
                }else {
                    	printf("Movimento inválido para o Rei.\n");
                    	printf("Ainda quer usar o Rei? S/N \n");
                    	scanf(" %c", &continuar);
                }
        	}while (continuar == 'S');
        	}
        	if (tabuleiro[linha][coluna] == 'T') {
            do {
                printf("Você quer mover a Torre para que posição? ");
                scanf(" %c %d", &c, &coluna);
                linha = c - 'A';
                coluna--;
                if (linha > linha_antiga && coluna == coluna_antiga){
                	for (i = linha_antiga; i < linha; i++){
                		if (tabuleiro[i][coluna] == '-'){
                			continue;
						}
						else if (tabuleiro[i][coluna] == ' '){
							printf("Você quer ir para uma posição inexistente");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
						else if(i == linha - 1){
							if (tabuleiro[linha][coluna] == '-') {
                            	printf("Peça movida com sucesso.\n");
                            	tabuleiro[linha][coluna] = 'T';
                            	tabuleiro[linha_antiga][coluna_antiga] = '-';
                            	peca_movida++;
                            	break;
                        	}
                        	else if(tabuleiro[linha][coluna] == ' '){
                        		printf("Você quer ir para uma posição inexistente");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
							else{
                        		printf("Você quer ir para uma posição ocupada\n");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
						}
						
						else{
							printf("Tem uma peça no caminho");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
					}
				}
				else if (linha < linha_antiga && coluna == coluna_antiga){
                	for (i = linha_antiga; i > linha; i--){
                		if (tabuleiro[i][coluna] == '-'){
                			continue;
						}
						if (tabuleiro[i][coluna] == ' '){
							printf("Você quer ir para uma posição inexistente");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
						else if(i == linha + 1){
							if (tabuleiro[linha][coluna] == '-') {
                            	printf("Peça movida com sucesso.\n");
                            	tabuleiro[linha][coluna] = 'T';
                            	tabuleiro[linha_antiga][coluna_antiga] = '-';
                            	peca_movida++;
                            	break;
                        	}
                        	else if(tabuleiro[linha][coluna] == ' '){
                        		printf("Você quer ir para uma posição inexistente");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}else{
                        		printf("Você quer ir para uma posição ocupada\n");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
						}
						else if(peca_movida == 1){
							break;
						}
						else{
							printf("Tem uma peça no caminho");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
					}
				}
				else if (coluna > coluna_antiga && linha == linha_antiga){
                	for (i = coluna_antiga; i < coluna; i++){
                		if (tabuleiro[linha][i] == '-'){
                			continue;
						}
						if (tabuleiro[linha][i] == ' '){
							printf("Você quer ir para uma posição inexistente");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
						else if(i == coluna - 1){
							if (tabuleiro[linha][coluna] == '-') {
                            	printf("Peça movida com sucesso.\n");
                            	tabuleiro[linha][coluna] = 'T';
                            	tabuleiro[linha_antiga][coluna_antiga] = '-';
                            	peca_movida++;
                            	break;
                        	}
                        	else if(tabuleiro[linha][coluna] == ' '){
                        		printf("Você quer ir para uma posição inexistente");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
                        	}else{
                        		printf("Você quer ir para uma posição ocupada\n");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
						}
						else{
							printf("Tem uma peça no caminho");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
					}
			}
				else if (coluna < coluna_antiga && linha == linha_antiga){
                	for (i = coluna_antiga; i > coluna; i--){
                		if (tabuleiro[linha][i] == '-'){
                			continue;
						}
						if (tabuleiro[linha][i] == ' '){
							printf("Você quer ir para uma posição inexistente");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
						else if(i == coluna + 1){
							if (tabuleiro[linha][coluna] == '-') {
                            	printf("Peça movida com sucesso.\n");
                            	tabuleiro[linha][coluna] = 'T';
                            	tabuleiro[linha_antiga][coluna_antiga] = '-';
                            	peca_movida++;
                            	break;
                        	}
                        	else if(tabuleiro[linha][coluna] == ' '){
                        		printf("Você quer ir para uma posição inexistente");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
							else{
                        		printf("Você quer ir para uma posição ocupada\n");
                        		printf("Ainda quer usar a Torre? S/N:");
                        		scanf(" %c", &continuar);
                        		break;
							}
						}
						else{
							printf("Tem uma peça no caminho");
							printf("Ainda quer usar a Torre? S/N:");
							scanf(" %c", &continuar);
							break;
						}
					}
				}
				else {
					printf("Movimento não permitido para a Torre\n");
					printf("Ainda quer usar a Torre? S/N:");
					scanf(" %c", &continuar);
					break;
				}
			}while (continuar == 'S');
		}
    }while (peca_movida == 0);
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    char tabuleiro[linhas][colunas];
    
    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);
    vezPreto(tabuleiro);
    exibirTabuleiro(tabuleiro);
    vezPreto(tabuleiro);
    exibirTabuleiro(tabuleiro);

}
