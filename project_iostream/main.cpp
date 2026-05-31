#include <iostream>
#include <vector>

#define INF 1000

// Neste modelo usaremos matrizes de adjacência!

class Aresta{
    private:
        //variaveis
        int origem;
        int destino;
        float peso;

    public:
        //construtor
        Aresta(int o, int d, float p): origem(o), destino(d), peso(p){}

        //getters
        int get_origem(){return origem;}
        int get_destino(){return destino;}
        float get_peso(){return peso;}

        //utils
        void apresentar(){
            std::cout   << '\n' << origem << " ---" 
                        << ((peso != 0 and peso != INF) ? std::to_string(peso) : "")
                        << "--> " << destino << '\n';
        }
};

class Grafo{
    private:
        //variaveis
        std::string nome;
        int qtd_vertices;
        bool direcionado;
        bool ponderado;
        std::vector<Aresta> arestas;

    public:
        //construtor
        Grafo(std::string n, int v, bool dir, bool pond, std::vector<Aresta> a): nome(n), qtd_vertices(v), direcionado(dir), ponderado(pond), arestas(a){}

        //getters
        std::string get_nome(){return nome;}
        int get_qtd_vertices(){return qtd_vertices;}
        bool get_direcionado(){return direcionado;}
        bool get_ponderado(){return ponderado;}
        std::vector<Aresta> get_arestas(){return arestas;}
        
        //utils
        void apresentar(){
            std::cout << "\nGrafo: " << nome << '\n';
            std::cout << "    Quantidade de Vértices: " << qtd_vertices << '\n';
            std::cout << "    " << (direcionado   ? "    " : "    Não ") << "Direcionado" << '\n';
            std::cout << "    " << (ponderado     ? "    " : "    Não ") << "Ponderado"   << '\n';
        }
};
