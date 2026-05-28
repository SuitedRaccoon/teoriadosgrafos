#include "dijkstra.h"

const int matriz_exemplo[TAMANHO][TAMANHO] = {
    {0,        12,       4,        INFINITO, INFINITO, INFINITO},
    {INFINITO, 0,        6,        6,        INFINITO, INFINITO},
    {INFINITO, 10,       0,        INFINITO, 2,        INFINITO},
    {INFINITO, INFINITO, 8,        0,        INFINITO, 6       },
    {INFINITO, 2,        INFINITO, INFINITO, 0,        6       },
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, 0       }
};

const int matriz_teste_1[TAMANHO][TAMANHO] = {
    {0,        2,        5,        INFINITO, INFINITO, INFINITO}, // A
    {INFINITO, 0,        1,        2,        INFINITO, INFINITO}, // B
    {INFINITO, INFINITO, 0,        INFINITO, 3,        10},       // C
    {INFINITO, INFINITO, INFINITO, 0,        1,        INFINITO}, // D
    {INFINITO, INFINITO, INFINITO, INFINITO, 0,        2},        // E
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, 0}         // F
};

const int matriz_teste_2[TAMANHO][TAMANHO] = {
    {0,        7,        2,        INFINITO, INFINITO, INFINITO}, // A
    {INFINITO, 0,        INFINITO, 3,        INFINITO, INFINITO}, // B
    {INFINITO, INFINITO, 0,        4,        20,       INFINITO}, // C
    {INFINITO, INFINITO, INFINITO, 0,        5,        INFINITO}, // D
    {INFINITO, INFINITO, INFINITO, INFINITO, 0,        INFINITO}, // E
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, 0}         // F
};

const int matriz_teste_3[TAMANHO][TAMANHO] = {
    {0,        10,       3,        INFINITO, INFINITO, INFINITO}, // A
    {INFINITO, 0,        INFINITO, 2,        INFINITO, INFINITO}, // B
    {INFINITO, 1,        0,        8,        2,        INFINITO}, // C
    {INFINITO, INFINITO, INFINITO, 0,        INFINITO, 2},        // D
    {INFINITO, INFINITO, INFINITO, 4,        0,        10},       // E
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, 0}         // F
};

const int matriz_teste_4[TAMANHO][TAMANHO] = {
    {0,        1,        INFINITO, INFINITO, INFINITO, INFINITO}, // A
    {INFINITO, 0,        2,        INFINITO, INFINITO, INFINITO}, // B
    {INFINITO, INFINITO, 0,        3,        INFINITO, INFINITO}, // C
    {INFINITO, INFINITO, INFINITO, 0,        4,        INFINITO}, // D
    {INFINITO, INFINITO, INFINITO, INFINITO, 0,        5},        // E
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, 0}         // F
};

int tabela_caminhos[3][TAMANHO] = {
    {0, 0, 0, 0, 0, 0},
    {INFINITO, INFINITO, INFINITO, INFINITO, INFINITO, INFINITO},
    {VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO}
};

char indices_grafo[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F'};

int encontrar_maior(int lista[TAMANHO]) {
    int maior = 0;
    int indice_maior = 0;

    for (int i = 0; i < TAMANHO; ++i) {
        if (lista[i] >= maior) {
            maior = lista[i];
            indice_maior = i;
        }
    }

    return indice_maior;
}

int encontrar_menor(int lista[TAMANHO]) {
    int menor = INFINITO;
    int indice_menor = 0;

    for (int i = 0; i < TAMANHO; ++i) {
        if (lista[i] <= menor) {
            menor = lista[i];
            indice_menor = i;
        }
    }

    return indice_menor;
}

int ponto_de_partida(const int matriz[TAMANHO][TAMANHO]) {
    int numero_infinitos[TAMANHO] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < TAMANHO; ++i) {
        int contador = 0;

        for (int j = 0; j < TAMANHO; ++j) {
            if (matriz[j][i] >= INFINITO) {
                ++contador;
            }
        }

        numero_infinitos[i] = contador;
    }

    return encontrar_maior(numero_infinitos);
}

void criar_tabela(void) {
    for (int i = 0; i < TAMANHO; ++i) {
        tabela_caminhos[0][i] = 0;
        tabela_caminhos[1][i] = INFINITO;
        tabela_caminhos[2][i] = VAZIO;
    }
}

void iniciar_tabela(const int matriz[TAMANHO][TAMANHO], int tabela[3][TAMANHO]) {
    criar_tabela();

    //int indice_inicial = ponto_de_partida(matriz);
    int indice_inicial = INICIAL;

    int *vertices_visitados = tabela[0];
    int *distancia = tabela[1];
    int *anterior = tabela[2];

    vertices_visitados[indice_inicial] = 1;

    for (int i = 0; i < TAMANHO; ++i) {
        distancia[i] = matriz[indice_inicial][i];
    }

    for (int i = 0; i < TAMANHO; ++i) {
        int soma = distancia[indice_inicial] + distancia[i];

        if (soma > 0 && soma < INFINITO) {
            anterior[i] = indice_inicial;
        }
    }
}

/*

anoto distancia atual (começando em 0)
olho tabela distancia
    procuro o menor valor diferente de 0 e pego o vertice
    olho pro grafo na linha do vertice e procuro os valores d 0 < d < 1000
    havendo d validos 
        excluo os vertices ja visitados e o atual (ficam com 1000)
        para cada vertice restante somo distancia e anoto os valores
        comparo a soma de cada indice ao respectivo na tabela distancia
            se um valor for menor
                troco distancia pelo valor novo
                troco anterior pelo vertice atual


*/

int percorrer_grafo(int matriz){

    const int (*grafo)[TAMANHO];

    switch (matriz){
        case 1: grafo = matriz_teste_1; break;
        case 2: grafo = matriz_teste_2; break;
        case 3: grafo = matriz_teste_3; break;
        case 4: grafo = matriz_teste_4; break;
        default: grafo = matriz_exemplo; break;
    }

    int *fechado = tabela_caminhos[0], *distancia = tabela_caminhos[1], *anterior = tabela_caminhos[2], valores[TAMANHO] = {0, 0, 0, 0, 0, 0}, valor_menor = INFINITO, indice_menor = -1, soma = 0;

    //checo se todos os vértices estão fechados
    for (int i = 0; i < TAMANHO; ++i){
        soma += fechado[i];
    }
    if (soma == TAMANHO) return 0;

    //olho tabela distancia
    for (int i = 0; i < TAMANHO; ++i){
        //procuro o menor valor diferente de 0 e pego o vertice
        if (distancia[i] < valor_menor && fechado[i] != 1){
            valor_menor = distancia[i];
            indice_menor = i;
        }
    }

    // Se não encontrou nenhum vértice válido, para
    if (indice_menor == -1 || valor_menor >= INFINITO) {
        return 0;
    }

    // Agora sim fecha apenas o menor encontrado
    fechado[indice_menor] = 1;

    //olho pro grafo na linha do vertice = grafo[indice_menor]
    for (int i = 0; i < TAMANHO; ++i){
        //excluo os vertices ja visitados e o atual (ficam com 1000 ou maior) e para cada vertice restante somo distancia e anoto os valores
        soma = grafo[indice_menor][i] + valor_menor;
        if (grafo[indice_menor][i] == 0) soma = INFINITO; 
        valores[i] = soma;
    }

    //comparo a soma de cada indice ao respectivo na tabela distancia
    for (int i = 0; i < TAMANHO; ++i){
        //se um valor for menor
        if (valores[i] < distancia[i]){
            //troco distancia pelo valor novo
            distancia[i] = valores[i];
            //troco anterior pelo vertice atual
            anterior[i] = indice_menor;
        }

    }

    return percorrer_grafo(matriz);
}

