#include <iostream>

using namespace std;

/*
informações dos grafos
    direcionado ou não direcionado?     (A ------> B ou A ----- B?)
    ponderado ou não ponderado?         (A ---5--- B ou A ----- B?)

entidades principais
    Grafo
        -quantos vértices existem
        -quais vértices estão conectados
        -se o grafo é direcionado ou não
        -se as arestas tem peso

        classe Grafo 
            adiciona vértices
            remove vértice
            adiciona aresta
            remove aresta
            verifica se existe conexão
            lista vizinhos de um vértice
            imprime o grafo

    Aresta
        -origem
        -destino
        -peso (pode sempre ser tratado como 1 em grafos não ponderados)

representação interna
    Matriz de adjacência
        -guarda o grafo como uma matriz[i][j] sendo i a origem e j o destino das conexões
            . i == j seria sempre válido?
        -arestas recebem pesos
            -caso ponderado: 
                -se não existe recebe INF
                -se existe recebe um valor real
            -caso não ponderado:
                -se não existe recebe 0 (ou INF para padronizar código)
                -se existe recebe 1
        -exemplos 3x3:
            -ponderada orientada            (A):
                0   12  4
                INF 0   6
                INF 10  0

            -ponderada não orientada        (B): (matriz simétrica)
                0   4   1
                4   0   INF
                1   INF 0
            -não ponderada orientada        (C):
                0   1   1
                INF 0   1
                INF 1   0
            -não ponderada não orientada    (D): (matriz simétrica)
                0   INF 1
                INF 0   1
                1   1   0
        
    Lista de adjacência
        -guarda, para cada vértice, uma lista de vizinhos
        -exemplo com matrizes anteriores:
            -A:
                0: (em branco)
                1: (0, peso 12), (2, peso 10)
                2: (0, peso 4), (1, peso 6)
            -B:
                0: (1, peso 4), (2, peso 1)
                1: (0, peso 4)
                2: (0, peso 1)
            -C:
                0: (em branco)
                1: (0), (2)
                2: (0), (1)
            -D:
                0: (2)
                1: (2)
                2: (0), (1)
            
lógica externa:
    não acessar diretamente matriz[i][j]
    mas perguntar:
        existe aresta entre i e j?
        qual o peso entre i e j?
        quais são os vizinhos de i?

métodos da classe Grafo:
    criar grafo com N vertices
    adicionar aresta
    remover aresta
    verificar se existe aresta
    obter peso de uma aresta
    obter vizinhos de um vertice
    retornar quantidade de vertices

    lógica:
        -Criar Grafo:
            quantidade de vertices
            se é direcionado ou não
            se é ponderado ou não
            exemplo:
                criar_grafo(3, false, true)
                └── retorna grafo de 3 vértices, não direcionado e ponderado

        -Adicionar Aresta:
            recebe origem e destino
            recebe peso (se ponderado)
            registra conexão origem --> destino
            (se não direcionado) registra destino --> origem
            exemplo:
                adicionar_aresta(0, 2, 5)
                |--se for não direcionado: retorna (0 --> 2 peso 5) e (2 --> 0 peso 5)
                └──se for direcionado: retorna (0 --> 2 peso 5)

        -Buscar Vizinhos:
            recebe um vertice
            verifica todos os vértices conectados a ele
            retorna os vizinhos encontrados
            exemplo:
                vizinhos(0)
                └──retorna 1, 3, 4

        -Obter Peso:
            qual o peso da aresta entre A e B?
            exemplo:
                peso(0, 2)
                └──retorna INF (ou o valor adequado caso exista conexão)
*/