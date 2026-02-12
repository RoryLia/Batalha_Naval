#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HAB 5

//Função para iniciar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

//Função para exibir tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for (int i = 0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//Função para sobrepor matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2; //centro da matriz de habilidade
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - offset);
                int colunaTab = origemColuna + (j - offset);
                //validação de limites
                if (linhaTab >= 0 && linhaTab < TAMANHO && colunaTab >= 0 && colunaTab < TAMANHO){
                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

//Construção matriz Cone
void construirCone(int cone[TAM_HAB][TAM_HAB]){
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

//Construção matriz Cruz
void construirCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

//Construção matriz Octaedro
void construirOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    //Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    //Aplicar habilidades em pontos de origem diferentes
    aplicarHabilidade(tabuleiro, cone, 1, 1);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);

    printf("Tabuleiro com habilidades especiais:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}