#include <iostream>
#include "classes.hpp"

//------------------------Métodos de Aresta------------------------
//construtor
Aresta::Aresta(int o, int d, float p): origem(o), destino(d), peso(p) {}
//getters
int Aresta::get_origem(void) const {return origem;}
int Aresta::get_destino(void) const {return destino;}
float Aresta::get_peso(void) const {return peso;}
//interface
void Aresta::apresentar(void) const {
    if (peso > INICIO && peso < INFINITO) {
        std::cout << origem << " ---> " << destino << "  Peso: " << peso << '\n';
    }
}

//------------------------Métodos de Grafo------------------------
//construtor
Grafo::Grafo(std::string n, int v, bool dir, bool pond) : nome(n), qtd_vertices(v), direcionado(dir), ponderado(pond) {}
//getters
std::string Grafo::get_nome(void) const {return nome;}
int Grafo::get_qtd_vertices(void) const {return qtd_vertices;}
bool Grafo::get_direcionado(void) const {return direcionado;}
bool Grafo::get_ponderado(void) const {return ponderado;}
const std::vector<Aresta>& Grafo::get_arestas(void) const {return arestas;}
//métodos principais
int Grafo::buscar_aresta(int origem, int destino) const {
    int resposta = VAZIO;
    for (size_t i = 0; i < arestas.size(); ++i) {
        if (arestas[i].get_origem() == origem &&
            arestas[i].get_destino() == destino) {
            resposta = static_cast<int>(i);
            break;
        }
    }
    return resposta;
}
bool Grafo::aresta_existe(int origem, int destino) const {
    return buscar_aresta(origem, destino) != VAZIO;
}
void Grafo::rm_aresta(int origem, int destino) {
    int indice = buscar_aresta(origem, destino);
    if (indice == VAZIO) {
        std::cout << "\nAresta não encontrada!\n";
        return;
    }
    auto posicao = arestas.begin() + indice;
    arestas.erase(posicao);
    if (!direcionado) {
        int indice_inverso = buscar_aresta(destino, origem);
        if (indice_inverso != VAZIO) {
            auto posicao_inverso = arestas.begin() + indice_inverso;
            arestas.erase(posicao_inverso);
        }
    }
}
void Grafo::add_aresta(int origem, int destino, float peso) {
    if (origem < 0 || origem >= qtd_vertices) {
        std::cout << "\nOrigem Inválida - tente novamente com outro valor!";
        return;
    }
    if (destino < 0 || destino >= qtd_vertices || destino == origem) {
        std::cout << "\nDestino Inválido - tente novamente com outro valor!";
        return;
    }
    if (!ponderado) {
        peso = PADRAO;
    }
    if (buscar_aresta(origem, destino) == VAZIO) {
        Aresta aresta1(origem, destino, peso);
        arestas.push_back(aresta1);
    }
    if (!direcionado) {
        if (buscar_aresta(destino, origem) == VAZIO) {
            Aresta aresta2(destino, origem, peso);
            arestas.push_back(aresta2);
        }
    }
}
float Grafo::obter_peso(int origem, int destino) const {
    float peso = INFINITO;
    int indice = buscar_aresta(origem, destino);

    if (indice != VAZIO) {
        peso = arestas[indice].get_peso();
    }

    return peso;
}
std::vector<int> Grafo::vizinhos(int origem) const {
    std::vector<int> vizinhanca;

    for (size_t i = 0; i < arestas.size(); ++i) {
        if (arestas[i].get_origem() == origem) {
            vizinhanca.push_back(arestas[i].get_destino());
        }
    }

    return vizinhanca;
}
//interface
void Grafo::listar_arestas(void) const {
    for (size_t i = 0; i < arestas.size(); ++i) {
        arestas[i].apresentar();
    }
}
void Grafo::apresentar(void) const {
    std::cout << "\n\nApresentando Grafo: " << nome << '\n';
    std::cout << "    Quantidade de Vértices: " << qtd_vertices << '\n';
    std::cout << "    " << (direcionado ? "" : "Não ") << "Direcionado" << '\n';
    std::cout << "    " << (ponderado ? "" : "Não ") << "Ponderado" << '\n';
}
void Grafo::listar_vizinhos(int origem) const {
    std::vector<int> vizinhanca = vizinhos(origem);

    std::cout << "Vizinhança de " << origem << '\n';

    for (size_t i = 0; i < vizinhanca.size(); ++i) {
        std::cout << "  - " << vizinhanca[i] << '\n';
    }
}
void Grafo::imprimir(void) const {
    std::cout << "\n\nImprimindo Grafo: " << nome << '\n';
    listar_arestas();
    std::cout << '\n';
}