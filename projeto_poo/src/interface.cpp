#include <iostream>
#include <cstdlib>
#include <limits>
#include "interface.hpp"

void menu_inicial(void){
    int escolha = 0;
    system("clear");
    std::cout   << "Boas vindas ao construtor e operador de grafos !\n\n"
                << "    1. Criar novo grafo\n"
                << "    2. Visualizar grafo salvo\n"
                //<< "    3. Percorrer grafo salvo\n"
                //<< "    4. Editar grafo salvo\n"
                //<< "    5. Excluir grafo salvo\n"
                << "    3. Fechar programa\n\n\n";
    escolher(escolha);
}

void criar_novo_grafo(void){}

void visualizar_grafo(void){}

void saida(void){
    system("clear");
    std::cout   << "Obrigado por utilizar este construtor e operador de grafos!\n"
                << "Pressione ENTER para fechar o programa.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    exit(0);
}

void menu_inicial_opcoes(int i){
    switch (i){
        case 1:     criar_novo_grafo(); break;
        case 2:     visualizar_grafo(); break;
        case 3:     saida(); break;
        default:    menu_inicial();
    }
}

void escolher(int a){
    int escolha = a;
    if (escolha == 0){
        std::cout   << "    Informe a opção desejada: ";
        std::cin    >> escolha;
    }
    if (escolha <= 0 or escolha > 3){
        system("clear");
        std::cout   << "    Por favor informe uma opção válida [1 - 3]\n\n"
                    << "    Pressione ENTER para prosseguir...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        menu_inicial();
    }
    menu_inicial_opcoes(escolha);
}