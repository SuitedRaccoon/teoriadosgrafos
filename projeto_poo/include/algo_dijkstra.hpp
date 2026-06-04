#ifndef ALGORITMO_DIJKSTRA_H
#define ALGORITMO_DIJKSTRA_H

#include "classes.hpp"

struct ResultadoDijkstra {
    int origem;
    bool valido;
    std::vector<float> distancia;
    std::vector<int> anterior;
};


ResultadoDijkstra dijkstra(const Grafo& grafo, int origem);

#endif