#include <iostream>
#include <string>
#include "algo_bellman_ford.hpp"


ResultadoBellmanFord bellman_ford(const Grafo& grafo, int origem){
//Primeiramente verifica se a origem é válida antes de prosseguir com o algoritmo
    int vertices = grafo.get_qtd_vertices();
    if (origem < 0 or origem >= vertices){
        std::cout << "\nOrigem inválida. Algoritmo de Bellman-Ford não será executado!" << '\n';
        return {origem, false, false, {}, {}};
    }
//Inicialização da tabela de caminhos
    std::vector<float> distancia(vertices, INFINITO);
    std::vector<int> anterior(vertices, VAZIO);
    distancia[origem] = INICIO;
//Declaração de variáveis internas de controle
    int atual, vizinho;
    float peso , nova_distancia;
    std::vector<int> vizinhos_atual;
//Loop principal do algoritmo
    for (int repeticao = 1; repeticao <= vertices - 1; ++repeticao){
        for (atual = INICIO; atual < vertices; ++atual){
            if (distancia[atual] == INFINITO) continue; //pula iteração do código nos vértices desconexos;

            vizinhos_atual = grafo.vizinhos(atual);
            for (size_t i = 0; i < vizinhos_atual.size(); ++i){
                vizinho = vizinhos_atual[i];
                peso = grafo.get_peso(atual, vizinho);
                nova_distancia = distancia[atual] + peso;

                if (nova_distancia < distancia[vizinho]){
                    distancia[vizinho] = nova_distancia;
                    anterior[vizinho] = atual;
                }
            }
        }

    }
//Verificação de ciclo negativo - gostaria de tentar evitar essa repetição de código futuramente
    for (atual = INICIO; atual < vertices; ++atual){
        if (distancia[atual] == INFINITO) continue; //pula iteração do código nos vértices desconexos;

        vizinhos_atual = grafo.vizinhos(atual);
        for (size_t i = 0; i < vizinhos_atual.size(); ++i){
            vizinho = vizinhos_atual[i];
            peso = grafo.get_peso(atual, vizinho);
            nova_distancia = distancia[atual] + peso;

            if (nova_distancia < distancia[vizinho]){
                std::cout << "\nCiclo negativo detectado! Impossível encontrar menor caminho!" << '\n';
                return {origem, false, true, {}, {}};
            }
        }
    }
    return {origem, true, false, distancia, anterior};
}

/*
Dado um vértice u, um vértice adjacente v e o peso da aresta entre eles w(u, v), a distância atual estimada da origem até v é d[v]. Se descobrirmos que passar por u oferece um caminho mais barato para v, nós "relaxamos" a aresta:
    d[u] + w(u, v) < d[v] =>  d[v] = d[u] + w(u, v)

relaxar todas as arestas um total de V - 1 vezes (sendo V o numero total de arestas)
    1a iteração garante o menor caminho para todos os vértices que estão a 1 aresta de distancia da origem
    2a iteração garante o menor caminho para todos os vértices que estão a até 2 arestas de distancia da origem
    ...
    na "V - 1"-ésima vez você terá garantido o caminho mais curto para vértices que estão a V - 1 arestas de distância (capacidade máxima de um caminho simples)

teste para detectar ciclos negativos:
    após percorrer o loop V - 1 vezes, percorrendo uma vez a mais (a V-ésima vez), aplicar a operação de relaxamento
        se alguma distância d[v] ainda puder ser reduzida, significa que o algoritmo encontrou um poço sem fundo.
        -> existe um ciclo negativo alcançável a partir da origem, e não existe solução de um caminho mínimo.

pseudo-código:
    loop, para cada aresta (u, v) de peso w, V - 1 vezes:
        se d[u] + w < d[v]:
            d[v] = d[u] + w
    se d[u] + w < d[v] for verdadeira para qualquer aresta
        excessão: "Ciclo negativo detectado!"     
*/
    
