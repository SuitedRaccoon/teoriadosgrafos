#ifndef TESTES_H
#define TESTES_H
#include "algoritmos_busca.hpp"
#include "algo_dijkstra.hpp"
#include "algo_bellman_ford.hpp"

void imprimir_resultado_dijkstra(const ResultadoDijkstra& resultado);
void imprimir_resultado_bellman_ford(const ResultadoDijkstra& resultado);
void testes_grafos(void);

#endif