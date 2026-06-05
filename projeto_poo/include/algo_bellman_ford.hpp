#ifndef ALGORITMO_BELLMANFORD_H
#define ALGORITMO_BELLMANFORD_H

#include "classes.hpp"

struct ResultadoBellmanFord {
    int origem;
    bool valido;
    bool ciclo_negativo;
    std::vector<float> distancia;
    std::vector<int> anterior;
};

ResultadoBellmanFord bellman_ford(const Grafo& grafo, int origem);

#endif