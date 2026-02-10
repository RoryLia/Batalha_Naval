#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO][TAMANHO];

    //Inicializa todas as posições com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    //Coordenadas iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4; //navio horizontal
    int linhaVertical = 5, colunaVertical = 7; //Navio vertical

    //Posiciona navio horizontal (3 posições)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    //Posiciona navio vertical (3 posições)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
    }

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