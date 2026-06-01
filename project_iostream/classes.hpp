#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

constexpr int INFINITO = 1000;
constexpr int PADRAO = 1;
constexpr int INICIO = 0;
constexpr int VAZIO = -1;

class Aresta {
private:
    //atributos
    int origem;
    int destino;
    float peso;
public:
    //construtor
    Aresta(int o, int d, float p);
    //getters
    int get_origem(void) const;
    int get_destino(void) const;
    float get_peso(void) const;
    //interface
    void apresentar(void) const;
};

class Grafo {
private:
    //atributos
    std::string nome;
    int qtd_vertices;
    bool direcionado;
    bool ponderado;
    std::vector<Aresta> arestas;
public:
    //construtor
    Grafo(std::string n, int v, bool dir, bool pond);
    //getters
    std::string get_nome(void) const;
    int get_qtd_vertices(void) const;
    bool get_direcionado(void) const;
    bool get_ponderado(void) const;
    const std::vector<Aresta>& get_arestas(void) const;
    //métodos principais
    int buscar_aresta(int origem, int destino) const;
    bool aresta_existe(int origem, int destino) const;
    void rm_aresta(int origem, int destino);
    void add_aresta(int origem, int destino, float peso);
    float obter_peso(int origem, int destino) const;
    std::vector<int> vizinhos(int origem) const;
    //interface
    void listar_arestas(void) const;
    void apresentar(void) const;
    void listar_vizinhos(int origem) const;
    void imprimir(void) const;
};

#endif