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
    for(int j = 0; j < 8; ++j){
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
	for (int j = 0; j < 8; ++j){
    	tabuleiro[6][j] = 'p';
	}
	for (int i = 2; i < 6; ++i){
		for (int j = 0; j < 8; ++j){
			tabuleiro[i][j] = '-';
		}
	}
}

void exibirTabuleiro(char tabuleiro[linhas][colunas]) {
	// Exibir os n�meros das colunas
    printf("  ");
    for (int i = 0; i < colunas; ++i) { // Essa fun��o utiliza o I como um indice para as colunas.
        printf("%d ", i + 1); // Se printa cada espa�o com o valor que ele tem no Vetor.
    }
    printf("\n"); // Quebra a linha
    
	// Exibir o tabuleiro do jogo
    for (int i = 0; i < linhas; ++i) { // Essa fun��o utiliza o I como um indice para as linhas.
        printf("%c ", 'A' + i);
        for (int j = 0; j < colunas; ++j) { // Essa fun��o utiliza o J como um indice para as colunas.
            printf("%c ", tabuleiro[i][j]); // Se printa cada espa�o com o valor que ele tem no Vetor.
        }
        printf("\n"); // Quebra a linha
    }
}



int main(){
	
	char tabuleiro[linhas][colunas];
	int linha, coluna, i, j;
	
	inicializarTabuleiro(tabuleiro);
	exibirTabuleiro(tabuleiro);
}


