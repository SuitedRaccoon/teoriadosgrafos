#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicialmente todos os grafos serão de matrizes 6x6
const int tamanho = 6;
const int matriz_exemplo[tamanho][tamanho] = {
    {0,    12,   4,    1000, 1000, 1000}, // A
    {1000, 0,    6,    6,    1000, 1000}, // B
    {1000, 10,   0,    1000, 2,    1000}, // C
    {1000, 1000, 8,    0,    1000, 6},    // D
    {1000, 2,    1000, 1000, 0,    6},    // E
    {1000, 1000, 1000, 1000, 1000, 0}     // F
};

int tabela_caminhos[3][tamanho] = {
    {0, 0, 0, 0, 0, 0}, // Vertices fechados
    {1000, 1000, 1000, 1000, 1000, 1000}, // Distância
    {-1, -1, -1, -1, -1, -1}  // Anterior
};

char indices_grafo[tamanho] = {'A', 'B', 'C', 'D', 'E', 'F'};
char indices_tabela[4][11] = {"INDICE", "FECHADO", "DISTANCIA", "ANTERIOR"};

/* INICIO VIBE CODE */

int largura_numero(int valor) {
    char texto[32];
    return snprintf(texto, sizeof(texto), "%d", valor);
}

int calcular_largura_coluna(const int matriz[tamanho][tamanho]) {
    int largura = 1;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int largura_atual = largura_numero(matriz[i][j]);

            if (largura_atual > largura) {
                largura = largura_atual;
            }
        }
    }

    return largura;
}

void imprimir_separador(int largura_indice, int largura_coluna) {
    printf("|");

    for (int i = 0; i < largura_indice + 2; i++) {
        printf("-");
    }

    printf("|");

    for (int j = 0; j < tamanho; j++) {
        for (int i = 0; i < largura_coluna + 2; i++) {
            printf("-");
        }

        printf("|");
    }

    printf("\n");
}

void imprimir_matriz_gpt(const int matriz[tamanho][tamanho]) {
    int largura_indice = 6; // tamanho de "Indice"
    int largura_coluna = calcular_largura_coluna(matriz);

    printf("\n");

    printf("| %-*s |", largura_indice, "Indice");

    for (int i = 0; i < tamanho; i++) {
        printf(" %*c |", largura_coluna, indices_grafo[i]);
    }

    printf("\n");

    imprimir_separador(largura_indice, largura_coluna);

    for (int i = 0; i < tamanho; i++) {
        printf("| %-*c |", largura_indice, indices_grafo[i]);

        for (int j = 0; j < tamanho; j++) {
            printf(" %*d |", largura_coluna, matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void imprimir_separador_tabela(int largura_indice, int largura_coluna) {
    printf("|");

    for (int i = 0; i < largura_indice + 2; i++) {
        printf("-");
    }

    printf("|");

    for (int j = 0; j < tamanho; j++) {
        for (int i = 0; i < largura_coluna + 2; i++) {
            printf("-");
        }

        printf("|");
    }

    printf("\n");
}

int calcular_largura_tabela_caminhos(int tabela[3][tamanho]) {
    int largura = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < tamanho; j++) {
            int largura_atual;

            if (i == 2) {
                // Linha ANTERIOR
                largura_atual = 1; // '-' ou uma letra: A, B, C...
            } else {
                // Linhas FECHADO e DISTANCIA
                largura_atual = largura_numero(tabela[i][j]);
            }

            if (largura_atual > largura) {
                largura = largura_atual;
            }
        }
    }

    return largura;
}

void imprimir_tabela_caminhos_gpt(int tabela[3][tamanho]) {
    int largura_indice = strlen("DISTANCIA");
    int largura_coluna = calcular_largura_tabela_caminhos(tabela);

    printf("\n");
    printf("| %-*s |", largura_indice, indices_tabela[0]);

    for (int i = 0; i < tamanho; i++) {
        printf(" %*c |", largura_coluna, indices_grafo[i]);
    }

    printf("\n");

    imprimir_separador_tabela(largura_indice, largura_coluna);

    for (int i = 0; i < 3; i++) {
        printf("| %-*s |", largura_indice, indices_tabela[i + 1]);

        for (int j = 0; j < tamanho; j++) {
            if (i == 2) {
                int anterior = tabela[i][j];

                if (anterior == -1) {
                    printf(" %*s |", largura_coluna, "-");
                } else {
                    printf(" %*c |", largura_coluna, indices_grafo[anterior]);
                }
            } else {
                printf(" %*d |", largura_coluna, tabela[i][j]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

/* FIM VIBE CODE */

/* Não ficou bom, vou implementar depois. Testarei com o que o GPT criou

void imprimir_tabela(const int matriz[tamanho][tamanho], char tipo){
    if (tipo == 'g' or tipo == 'G'){
        printf("\n| Índice    |    A |    B |    C |    D |    E |    F |");
        for (int i = 0; i < tamanho; ++i){
            printf("\n| %c         |", indices_grafo[i]);
            for (int j = 0; j < tamanho; ++j){
                printf("    %i |", matriz[i][j]);
            }           
        }
        printf("\n");
    }
    if (tipo == 't' or tipo == 'T'){
        printf("\n| Índice    |    A |    B |    C |    D |    E |    F |");
        for (int i = 0; i < tamanho; ++i){

        }
    }

}

*/

int encontrar_maior(int lista[tamanho]){
    int maior = 0, indice_maior = 0;
    for (int i = 0; i < tamanho; ++i){
        if (lista[i] >= maior){
            maior = lista[i];
            indice_maior = i;
        }
    }
    return indice_maior;
}

int encontrar_menor(int lista[tamanho]){
    int menor = 1000, indice_menor = 0;
    for (int i = 0; i < tamanho; ++i){
        if (lista[i] <= menor){
            menor = lista[i];
            indice_menor = i;
        }
    }
    return indice_menor;
}

int ponto_de_partida(const int matriz[tamanho][tamanho]){
    int numero_infinitos[tamanho] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < tamanho; ++i){
        int contador = 0;
        for (int j = 0; j < tamanho; ++j){
            if (matriz[j][i] >= 1000) ++contador;
        }
        numero_infinitos[i] = contador;
    }
    return encontrar_maior(numero_infinitos);
}

void criar_tabela(){
    for (int i = 0; i < tamanho; ++i) {
        tabela_caminhos[0][i] = 0;     // Vértices fechados
        tabela_caminhos[1][i] = 1000;  // Distância
        tabela_caminhos[2][i] = -1;     // Anterior
    }
}

void iniciar_tabela(const int matriz[tamanho][tamanho], int tabela[3][tamanho] = tabela_caminhos){
    criar_tabela();
    int indice_inicial = ponto_de_partida(matriz);
    int *vertices_visitados = tabela[0];
    int *distancia = tabela[1];
    int *anterior = tabela[2];

    // Fecha o vértice de início
    vertices_visitados[indice_inicial] = 1;
    
    // Atualiza a lista de distâncias com base no vértice de início
    for (int i = 0; i < tamanho; ++i){
        distancia[i] = matriz[indice_inicial][i];
    }
    
    // Atualiza a lista de anteriores para marcar o vértice inicial aos possíveis próximos vértices
    for (int i = 0; i < tamanho; ++i){
        int soma = distancia[indice_inicial] + distancia[i];
        if (soma > 0 and soma < 1000) anterior[i] = indice_inicial;
    }
}

void escolher_proximo_vertice(int lista[tamanho]){
    
}

int main(){
    iniciar_tabela(matriz_exemplo);
    //printf("\n%i\n", ponto_de_partida(matriz_exemplo));
    //imprimir_tabela(matriz_exemplo, 'G');
    imprimir_matriz_gpt(matriz_exemplo);
    imprimir_tabela_caminhos_gpt(tabela_caminhos);
    return 0;
}