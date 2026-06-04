#include <iostream>
#include <string>
#include "classes.hpp"
#include "testes.hpp"
#include "algoritmos_busca.hpp"
#include "algo_dijkstra.hpp"

void imprimir_resultado_dijkstra(const ResultadoDijkstra& resultado) {
    if (!resultado.valido) {
        std::cout << "\nResultado inválido. Dijkstra não foi executado.\n";
        return;
    }

    std::cout << "\nResultado do Dijkstra a partir do vértice "
              << resultado.origem << "\n\n";

    std::cout << "Vértice\tDistância\tAnterior\n";

    for (size_t i = 0; i < resultado.distancia.size(); ++i) {
        std::cout << i << "\t";

        if (resultado.distancia[i] == INFINITO) {
            std::cout << "INF";
        } else {
            std::cout << resultado.distancia[i];
        }

        std::cout << "\t\t";

        if (resultado.anterior[i] == VAZIO) {
            std::cout << "-";
        } else {
            std::cout << resultado.anterior[i];
        }

        std::cout << '\n';
    }
}

void testes_grafos(void){
    Grafo g1("Modelo 1", 4, true, true);
    Grafo g2("Modelo 2", 4, false, true);
    Grafo g3("Modelo 3", 4, true, false);
    Grafo g4("Teste Remoção", 3, false, true);
    Grafo g5("Teste Entradas Inválidas", 3, true, true);
    Grafo g6("Teste Arestas Duplicadas", 3, true, true);

    std::cout << std::boolalpha;

    //teste grafo direcionado e ponderado
    std::cout << '\n' << std::string(10, '-') << "Teste 01: Grafo Direcionado e Ponderado" << std::string(10, '-') << '\n';
    g1.add_aresta(0, 1, 5);
    g1.add_aresta(0, 2, 3);
    g1.add_aresta(1, 3, 2);
    g1.add_aresta(2, 3, 7);
    g1.apresentar();
    g1.imprimir();
    g1.listar_vizinhos(0);
    std::cout << "\nPeso 0 -> 2: " << g1.get_peso(0, 2) << '\n';
    std::cout << "Existe 1 -> 3? " << g1.aresta_existe(1, 3) << '\n';
    std::cout << "Existe 3 -> 1? " << g1.aresta_existe(3, 1) << '\n';
    
    //teste grafo não direcionado e ponderado
    std::cout << '\n' << std::string(10, '-') << "Teste 02: Grafo Não Direcionado e Ponderado" << std::string(10, '-') << '\n';
    g2.add_aresta(0, 1, 4);
    g2.add_aresta(0, 2, 8);
    g2.add_aresta(2, 3, 6);
    g2.apresentar();
    g2.imprimir();
    g2.listar_vizinhos(0);
    g2.listar_vizinhos(2);
    std::cout << "\nExiste 0 -> 1? " << g2.aresta_existe(0, 1) << '\n';
    std::cout << "Existe 1 -> 0? " << g2.aresta_existe(1, 0) << '\n';
    std::cout << "Peso 3 -> 2: " << g2.get_peso(3, 2) << '\n';

    //teste grafo direcionado não ponderado
    std::cout << '\n' << std::string(10, '-') << "Teste 03: Grafo Direcionado e Não Ponderado" << std::string(10, '-') << '\n';
    g3.add_aresta(0, 1, 99);
    g3.add_aresta(1, 2, 50);
    g3.add_aresta(2, 3, 20);
    g3.apresentar();
    g3.imprimir();
    std::cout << "\nPeso 0 -> 1: " << g3.get_peso(0, 1) << '\n';
    std::cout << "Peso 1 -> 2: " << g3.get_peso(1, 2) << '\n';
    std::cout << "Existe 3 -> 2? " << g3.aresta_existe(3, 2) << '\n';
    
    //teste remoção de aresta em grafo não direcionado
    std::cout << '\n' << std::string(10, '-') << "Teste 04: Remoção de Aresta em Grafo Não Direcionado" << std::string(10, '-') << '\n';
    g4.add_aresta(0, 1, 10);
    g4.add_aresta(1, 2, 20);
    std::cout << "\nAntes de remover:\n";
    g4.imprimir();
    g4.rm_aresta(0, 1);
    std::cout << "\nDepois de remover 0 -> 1:\n";
    g4.imprimir();
    std::cout << "\nExiste 0 -> 1? " << g4.aresta_existe(0, 1) << '\n';
    std::cout << "Existe 1 -> 0? " << g4.aresta_existe(1, 0) << '\n';

    // teste de entradas inválidas
    std::cout << '\n' << std::string(10, '-') << "Teste 05: Entradas Inválidas" << std::string(10, '-') << '\n';
    g5.add_aresta(-1, 2, 5);
    g5.add_aresta(0, 5, 5);
    g5.add_aresta(1, 1, 5);
    g5.imprimir();

    // teste de aresta duplicada
    std::cout << '\n' << std::string(10, '-') << "Teste 06: Arestas Duplicadas" << std::string(10, '-') << '\n';
    g6.add_aresta(0, 1, 5);
    g6.add_aresta(0, 1, 5);
    g6.add_aresta(0, 1, 9);
    g6.imprimir();

    // testes de Dijkstra
    std::cout << '\n' << std::string(10, '-') 
              << "Teste 07: Dijkstra no Grafo 1 a partir do vértice 0" 
              << std::string(10, '-') << '\n';
    ResultadoDijkstra resultado_g1 = dijkstra(g1, 0);
    imprimir_resultado_dijkstra(resultado_g1);

    std::cout << '\n' << std::string(10, '-') 
              << "Teste 08: Dijkstra no Grafo 2 a partir do vértice 0" 
              << std::string(10, '-') << '\n';
    ResultadoDijkstra resultado_g2 = dijkstra(g2, 0);
    imprimir_resultado_dijkstra(resultado_g2);

    std::cout << '\n' << std::string(10, '-') 
              << "Teste 09: Dijkstra no Grafo 3 a partir do vértice 0" 
              << std::string(10, '-') << '\n';
    ResultadoDijkstra resultado_g3 = dijkstra(g3, 0);
    imprimir_resultado_dijkstra(resultado_g3);
}