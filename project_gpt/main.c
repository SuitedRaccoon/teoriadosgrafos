#include "dijkstra.h"
#include "impressao.h"

int main(void) {

    iniciar_tabela(matriz_teste_2, tabela_caminhos);

    imprimir_matriz(matriz_teste_2);
    imprimir_tabela_caminhos(tabela_caminhos);
    percorrer_grafo(2);
    imprimir_tabela_caminhos(tabela_caminhos);

    return 0;
}