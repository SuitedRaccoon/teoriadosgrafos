#include <iostream>
#include <string>
#include "algo_dijkstra.hpp"


ResultadoDijkstra dijkstra(const Grafo& grafo, int origem){
//Primeiramente verifica se a origem é válida antes de prosseguir com o algoritmo
    int vertices = grafo.get_qtd_vertices();
    if (origem < 0 or origem >= vertices){
        std::cout << "\nOrigem inválida. Algoritmo de Dijkstra não será executado!" << '\n';
        return {origem, false, {}, {}};
    }
//Inicialização da tabela de caminhos
    std::vector<bool> fechamento(vertices, ABERTO);
    std::vector<float> distancia(vertices, INFINITO);
    std::vector<int> anterior(vertices, VAZIO);
    distancia[origem] = INICIO;
//Declaração de variáveis internas de controle
    int atual, vizinho;
    float peso , nova_distancia;
    std::vector<int> vizinhos_atual;
    //(*)Função Lambda que verifical qual é o vértice aberto com a menor distância
    auto menor_aberto = [&fechamento, &distancia, vertices] (){
        float menor_distancia = INFINITO;
        int menor_vertice = VAZIO;
        for (int i = 0; i < vertices; ++i){
            if (fechamento[i] == ABERTO and distancia[i] < menor_distancia){
                menor_distancia = distancia[i];
                menor_vertice = i;
            }
        }
        return menor_vertice;
    };
//Loop principal do algoritmo
    while((atual = menor_aberto()) != VAZIO){
        fechamento[atual] = FECHADO;
        vizinhos_atual = grafo.vizinhos(atual);
        for (size_t i = 0; i < vizinhos_atual.size(); ++i){
            vizinho = vizinhos_atual[i];
            if (fechamento[vizinho] == ABERTO){
                peso = grafo.get_peso(atual, vizinho);
                nova_distancia = distancia[atual] + peso;
                if (nova_distancia < distancia[vizinho]){
                    distancia[vizinho] = nova_distancia;
                    anterior[vizinho] = atual;
                }
            }
        }
    }
    return {origem, true, distancia, anterior};
}


// (*) Estrutura de uma função lambda em C++:
//          tipo nome = [captura](parametros) {corpo da função};
//     1. tipo       => costuma ser gerado pelo compilador, normalmente usamos o tipo auto
//     2. nome       => nome da função, ela será futuramente chamada usando nome(parametros)
//     3. captura    => variável local da função principal que será referenciada pela lambda
//     4. parametros => parâmetros da função
