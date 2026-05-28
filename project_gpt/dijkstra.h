#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define TAMANHO 6
#define INICIAL 0
#define VAZIO -1
#define INFINITO 1000

extern const int matriz_exemplo[TAMANHO][TAMANHO];
extern const int matriz_teste_1[TAMANHO][TAMANHO];
extern const int matriz_teste_2[TAMANHO][TAMANHO];
extern const int matriz_teste_3[TAMANHO][TAMANHO];
extern const int matriz_teste_4[TAMANHO][TAMANHO];
extern int tabela_caminhos[3][TAMANHO];
extern char indices_grafo[TAMANHO];

int encontrar_maior(int lista[TAMANHO]);
int encontrar_menor(int lista[TAMANHO]);
int ponto_de_partida(const int matriz[TAMANHO][TAMANHO]);
int percorrer_grafo();

void criar_tabela(void);
void iniciar_tabela(const int matriz[TAMANHO][TAMANHO], int tabela[3][TAMANHO]);

#endif