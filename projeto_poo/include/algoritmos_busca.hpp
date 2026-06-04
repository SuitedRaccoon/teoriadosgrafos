#ifndef ALGORITMOS_BUSCA_H
#define ALGORITMOS_BUSCA_H

#include "classes.hpp"

void bellman_ford(const Grafo& grafo, int origem);
void a_star(const Grafo& grafo, int origem);
void breadth_first_search(const Grafo& grafo, int origem);
void depth_first_search(const Grafo& grafo, int origem);

#endif