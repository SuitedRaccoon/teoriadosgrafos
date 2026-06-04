#ifndef ALGORITMOS_BUSCA_H
#define ALGORITMOS_BUSCA_H

#include "classes.hpp"

struct ResultadoDijkstra {
    int origem;
    bool valido;
    std::vector<float> distancia;
    std::vector<int> anterior;
};


ResultadoDijkstra dijkstra(const Grafo& grafo, int origem);
void bellman_ford(const Grafo& grafo, int origem);
void a_star(const Grafo& grafo, int origem);
void breadth_first_search(const Grafo& grafo, int origem);
void depth_first_search(const Grafo& grafo, int origem);

#endif