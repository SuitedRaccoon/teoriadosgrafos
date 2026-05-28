#include <stdio.h>
#include <string.h>

#include "impressao.h"

static char indices_tabela[4][11] = {
    "INDICE",
    "FECHADO",
    "DISTANCIA",
    "ANTERIOR"
};

static int largura_numero(int valor) {
    char texto[32];
    return snprintf(texto, sizeof(texto), "%d", valor);
}

static int calcular_largura_coluna(const int matriz[TAMANHO][TAMANHO]) {
    int largura = 1;

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int largura_atual = largura_numero(matriz[i][j]);

            if (largura_atual > largura) {
                largura = largura_atual;
            }
        }
    }

    return largura;
}

static void imprimir_separador(int largura_indice, int largura_coluna) {
    printf("|");

    for (int i = 0; i < largura_indice + 2; i++) {
        printf("-");
    }

    printf("|");

    for (int j = 0; j < TAMANHO; j++) {
        for (int i = 0; i < largura_coluna + 2; i++) {
            printf("-");
        }

        printf("|");
    }

    printf("\n");
}

void imprimir_matriz(const int matriz[TAMANHO][TAMANHO]) {
    int largura_indice = 6;
    int largura_coluna = calcular_largura_coluna(matriz);

    printf("\n");

    printf("| %-*s |", largura_indice, "Indice");

    for (int i = 0; i < TAMANHO; i++) {
        printf(" %*c |", largura_coluna, indices_grafo[i]);
    }

    printf("\n");

    imprimir_separador(largura_indice, largura_coluna);

    for (int i = 0; i < TAMANHO; i++) {
        printf("| %-*c |", largura_indice, indices_grafo[i]);

        for (int j = 0; j < TAMANHO; j++) {
            printf(" %*d |", largura_coluna, matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int calcular_largura_tabela_caminhos(int tabela[3][TAMANHO]) {
    int largura = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            int largura_atual;

            if (i == 2) {
                // Linha ANTERIOR
                largura_atual = 1;
            } else if (i == 1 && tabela[i][j] == INFINITO) {
                // Linha DISTANCIA com valor infinito
                largura_atual = strlen("INFINITO");
            } else {
                largura_atual = largura_numero(tabela[i][j]);
            }

            if (largura_atual > largura) {
                largura = largura_atual;
            }
        }
    }

    return largura;
}

void imprimir_tabela_caminhos(int tabela[3][TAMANHO]) {
    int largura_indice = strlen("DISTANCIA");
    int largura_coluna = calcular_largura_tabela_caminhos(tabela);

    printf("\n");

    printf("| %-*s |", largura_indice, indices_tabela[0]);

    for (int i = 0; i < TAMANHO; i++) {
        printf(" %*c |", largura_coluna, indices_grafo[i]);
    }

    printf("\n");

    imprimir_separador(largura_indice, largura_coluna);

    for (int i = 0; i < 3; i++) {
        printf("| %-*s |", largura_indice, indices_tabela[i + 1]);

        for (int j = 0; j < TAMANHO; j++) {
            if (i == 2) {
                int anterior = tabela[i][j];

                if (anterior == VAZIO) {
                    printf(" %*s |", largura_coluna, "-");
                } else {
                    printf(" %*c |", largura_coluna, indices_grafo[anterior]);
                }
            } else {
                if (i == 1 && tabela[i][j] == INFINITO) {
                    printf(" %*s |", largura_coluna, "INFINITO");
                } else {
                    printf(" %*d |", largura_coluna, tabela[i][j]);
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}