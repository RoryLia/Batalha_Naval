#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

//Função para auxiliar a verificação de uma posição livre
int posicaoLivre(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

//Função para posicionar navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna){
    for (int i = 0; i < TAM_NAVIO; i++){
        if (coluna + i < TAMANHO && posicaoLivre(tabuleiro, linha, coluna + i)) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

//Função para posicionar navio vertical
void posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna){
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i < TAMANHO && posicaoLivre(tabuleiro, linha + i, coluna)) {
            tabuleiro[linha +i][coluna] = NAVIO;
        }
    }
}

//Funções para posicionar navio nas diagonais
void posicionarDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna){
    for (int i = 0; i < TAM_NAVIO; i++){
        if (linha + i < TAMANHO && coluna + i < TAMANHO && posicaoLivre(tabuleiro, linha + i, coluna + i)) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    }
}

void posicionarDiagonalSegundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++){
        if (linha + i < TAMANHO && coluna - i >= 0 && posicaoLivre(tabuleiro, linha + i, coluna - i)){
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    //Inicializa tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    //Posiciona os quatro navios
    posicionarHorizontal(tabuleiro, 2, 1);
    posicionarVertical(tabuleiro, 5, 4);
    posicionarDiagonalPrincipal(tabuleiro, 0, 0);
    posicionarDiagonalSegundaria(tabuleiro, 3, 8);

    //Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}