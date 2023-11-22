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
	// Exibir os números das colunas
    printf("  ");
    for (int i = 0; i < colunas; ++i) { // Essa função utiliza o I como um indice para as colunas.
        printf("%d ", i + 1); // Se printa cada espaço com o valor que ele tem no Vetor.
    }
    printf("\n"); // Quebra a linha
    
	// Exibir o tabuleiro do jogo
    for (int i = 0; i < linhas; ++i) { // Essa função utiliza o I como um indice para as linhas.
        printf("%c ", 'A' + i);
        for (int j = 0; j < colunas; ++j) { // Essa função utiliza o J como um indice para as colunas.
            printf("%c ", tabuleiro[i][j]); // Se printa cada espaço com o valor que ele tem no Vetor.
        }
        printf("\n"); // Quebra a linha
    }
}

void vezPreto(char tabuleiro[linhas][colunas]) {
    int linha, coluna, linha_antiga, coluna_antiga;
    char c;{
   	
    printf("Digite qual linha e coluna que quer mover: ");
    scanf(" %c %d", &c, &coluna);
    linha = c - 'A';
    coluna--;
    linha_antiga = linha;
    coluna_antiga = coluna;

    if (tabuleiro[linha][coluna] == 'C') {
        printf("Você quer mover o Cavalo para que posição? ");
        scanf(" %c %d", &c, &coluna);
        linha = c - 'A';
        coluna--;
        if ((linha == linha_antiga + 2 && coluna == coluna_antiga + 1) || (linha == linha_antiga + 1 && coluna == coluna_antiga + 2) ||
            (linha == linha_antiga - 1 && coluna == coluna_antiga + 2) || (linha == linha_antiga - 2 && coluna == coluna_antiga + 1) ||
            (linha == linha_antiga - 2 && coluna == coluna_antiga - 1) || (linha == linha_antiga - 1 && coluna == coluna_antiga - 2) ||
            (linha == linha_antiga + 1 && coluna == coluna_antiga - 2) || (linha == linha_antiga + 2 && coluna == coluna_antiga - 1)) {
            if (tabuleiro[linha][coluna] != 'P' && tabuleiro[linha][coluna] != 'T' && tabuleiro[linha][coluna] != 'C' && tabuleiro[linha][coluna] != 'B' && tabuleiro[linha][coluna] != 'R' && tabuleiro[linha][coluna] != 'K') {
                if (tabuleiro[linha][coluna] == '-') {
                    printf("Peça movida com sucesso.\n");
                    tabuleiro[linha][coluna] = 'C';
                    tabuleiro[linha_antiga][coluna_antiga] = '-';
                } else {
                    printf("Posição inexistente ou ocupada.\n");
                }
            }
        } else {
            printf("Movimento inválido para o Cavalo.\n");
        }
    }
}
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char tabuleiro[linhas][colunas];
	int linha, coluna, i, j, linha_antes, coluna_antes;
	
	inicializarTabuleiro(tabuleiro);
	exibirTabuleiro(tabuleiro);
	vezPreto(tabuleiro);
	exibirTabuleiro(tabuleiro);
	
}


