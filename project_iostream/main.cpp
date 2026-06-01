#include <iostream>
#include <string>
#include <vector>

#define INFINITO    1000
#define PADRAO      1
#define INICIO      0
#define VAZIO       -1

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
        int get_origem(void) const {return origem;}
        int get_destino(void) const {return destino;}
        float get_peso(void) const {return peso;}

        //utils
        void apresentar(void) const {
            if(peso > INICIO and peso < INFINITO){
                std::cout << origem << "--->" << destino << "  Peso: " << peso << '\n';
            }
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
        Grafo(std::string n, int v, bool dir, bool pond): nome(n), qtd_vertices(v), direcionado(dir), ponderado(pond){}

        //getters
        std::string get_nome(void) const {return nome;}
        int get_qtd_vertices(void) const {return qtd_vertices;}
        bool get_direcionado(void) const {return direcionado;}
        bool get_ponderado(void) const {return ponderado;}
        const std::vector<Aresta>& get_arestas(void) const {return arestas;}
        
        //principais
        int buscar_aresta(int origem, int destino) const {
            int resposta = VAZIO;
            for (size_t i = 0; i < arestas.size(); ++i){
                if(arestas[i].get_origem() == origem and arestas[i].get_destino() == destino) resposta = static_cast<int>(i);
                break;
            }
            return resposta;
        }

        bool aresta_existe(int origem, int destino) const {
            int indice = buscar_aresta(origem, destino);
            bool resposta = false;
            if (indice != VAZIO) resposta = true;
            return resposta;
        }

        void rm_aresta(int origem, int destino){
            int indice = buscar_aresta(origem, destino);
            if (indice == VAZIO){
                std::cout << "\n Aresta não encontrada!" << '\n';
                return;
            }
            auto posicao = arestas.begin() + indice;
            arestas.erase(posicao);

            if (!direcionado){
                int indice_inverso = buscar_aresta(destino, origem);
                if (indice_inverso != VAZIO){
                    auto posicao_inverso = arestas.begin() + indice_inverso;
                    arestas.erase(posicao_inverso);
                }
            }
        }

        void add_aresta(int origem, int destino, float peso){
            if((origem < 0) or (origem >= qtd_vertices)){
                std::cout << "\n Origem Inválida - tente novamente com outro valor!";
                return;
            }
            if((destino < 0) or (destino >= qtd_vertices) or (destino == origem)){
                std::cout << "\n Destino Inválido - tente novamente com outro valor!";
                return;
            }
            if(!ponderado) peso = PADRAO;
            if(buscar_aresta(origem, destino) == VAZIO){
                Aresta aresta1(origem, destino, peso);
                arestas.push_back(aresta1);
            }            
            if(!direcionado){
                if(buscar_aresta(destino, origem) == VAZIO){
                    Aresta aresta2(destino, origem, peso);
                    arestas.push_back(aresta2);
                }
            }
        }

        float obter_peso(int origem, int destino) const {
            float peso = INFINITO;
            int indice = buscar_aresta(origem, destino);
            if (indice != VAZIO) peso = arestas[indice].get_peso();
            return peso;
        }

        std::vector<int> vizinhos(int origem) const {
            std::vector<int> vizinhanca;
            for (size_t i = 0; i < arestas.size(); ++i){
                if (arestas[i].get_origem() == origem){
                    vizinhanca.push_back(arestas[i].get_destino());
                }
            }
            return vizinhanca;
        }

        //utils
        void listar_arestas(void) const {
            for (size_t i = 0; i < arestas.size(); ++i){
                arestas[i].apresentar();
            }
        }

        void apresentar(void) const {
            std::cout << "\nGrafo: " << nome << '\n';
            std::cout << "    Quantidade de Vértices: " << qtd_vertices << '\n';
            std::cout << "    " << (direcionado   ? "    " : "    Não ") << "Direcionado" << '\n';
            std::cout << "    " << (ponderado     ? "    " : "    Não ") << "Ponderado"   << '\n';
            listar_arestas();
        }

        void listar_vizinhos(int origem) const {
            std::vector<int> vizinhanca = vizinhos(origem);

            std::cout << "Vizinhança de " << origem << '\n';
            for (size_t i = 0; i < vizinhanca.size(); ++i){
                std::cout << "  - " << vizinhanca[i] << '\n';
            }
        }

        void imprimir(void) const {

        }
};
