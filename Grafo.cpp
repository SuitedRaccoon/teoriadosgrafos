#include <stdio.h>


int Ordem, Matriz[100][100];

bool inicializarMatriz(int qtdVertices){
	for (int linhas=0; linhas <=qtdVertices; linhas++){
		for (int colunas=0;colunas<=qtdVertices; colunas++){
			Matriz[linhas][colunas] = 0;
		}
	}
	return(true);
}
bool not_in(int x, int lista[],int tamanho){
	for(int i=0; i<tamanho; i++){
		if(lista[i]==x){
			return false;
		}
	}
	return true;
}
int imprimirMenu(){
	int Resposta;
	printf("\n Programa para percorrer GRAFOS ");
	printf("\n 1: Inicializar matriz");
	printf("\n 2: Inserir valor na matriz");
	printf("\n 3: Imprimir a matriz");
	printf("\n 4: Identificar caminho");
	printf("\n 5: Carregar vlores de teste");
	printf("\n 6: Sair do programa");
	printf("Informe a opcao desejada: ");
	scanf("%i", &Resposta);
	return(Resposta);
}

int inserirValor(int origem, int destino, int valor){
	
	if(origem<0 || origem> Ordem){
		printf("Origem nao existe na matriz!");
		return 0;
	}
	else if(destino<0 || destino> Ordem){
		printf("Destino nao existe na matriz!");
		return 0;
	}
	else if(destino == origem){
		printf("Este grafo nao permite lacos");
		return 0;
	}
	else if(valor<0 || valor>99){
		printf("Valor invalido");
		return 0;
	}
	else if(Matriz[origem][destino]!=0){
		int pergunta;
		printf("A aresta ja possui o valor: %d", Matriz[origem][destino]);
		printf("Deseja substituir pelo valor: %d?  sim[1] | nao[0]: ",valor);
		scanf("%d", &pergunta);
		if(pergunta == 1){
			Matriz[origem][destino]= valor;
			printf("O valor foi trocado!");
			return 0;
		}
		printf("Nenhuma alteraçao foi feita!");
	}
	else{
		Matriz[origem][destino] = valor;
		printf("O valor foi inserido!");
		return 0;
	}
}

int Percorrer(int origem, int destino,int Total, int visitados[30], int tam_visitados=0){
    int col;
    visitados[tam_visitados] = origem;
	tam_visitados+=1;
    if (origem==destino) {
		for (int j=0; j<tam_visitados; j++){
			printf("%i -> ", visitados[j]);
			int O= visitados[j];
			int D = visitados[j+1];
			printf("%i ->",Matriz[O][D]);
		}
			
        printf(" : %i Sucesso! \n", Total);
        visitados = 0;
        tam_visitados = 0;
    	return(0);
    }
    else {
      for (col=1; col<=Ordem; col++) {
            if(Matriz[origem][col] > 0 && not_in(col,visitados, tam_visitados)){
            	Total+=Matriz[origem][col];
            	printf(" Total=%i coluna=%i \n", Total, col);
            	Percorrer(col, destino,Total, visitados, tam_visitados);
            	Total=0;
            }
      	}
    }
}
int main(){
	int Opcao;
	do{
		Opcao = imprimirMenu();
		if(Opcao == 1){
			printf("Qual e a quatidade de vertices: ");
			scanf("%d", &Ordem);
			if(inicializarMatriz(Ordem)){
				printf("Matriz inicializada com sucesso!");
			}else{
				printf("A matriz nao foi inicializada");
			}
			
		}else if(Opcao == 2){
			// se origem e destino existem na matriz
			// vertice de destino e origem iguais
			// verificar se o valor está dentro do intervalo 0 - 99
			int Origem, Destino,Valor;
			printf("Informe o VERTICE de origem: ");
			scanf("%d", &Origem);
			
			printf("Informe o VERTICE de destino: ");
			scanf("%d", &Destino);
			
			printf("Digite o valor da aresta: ");
			scanf("%d", &Valor);
			
			inserirValor(Origem, Destino, Valor);	
			
		}
		else if(Opcao == 3){
			printf("   ");
			for(int c=0;c<=Ordem;c++){
				printf("%d   ",c);
			}
			printf("\n");
			for (int linhas=0; linhas <=Ordem; linhas++){
				printf("%d ",linhas );
				
				for (int colunas=0;colunas<=Ordem; colunas++){
					printf("[%d] ", Matriz[linhas][colunas]);
					
				}printf("\n");
			}
		}else if(Opcao == 4){
			int Origem, Destino, visitados[30];
			
			printf("Informe o VERTICE de origem: ");
			scanf("%d", &Origem);
			
			printf("Informe o VERTICE de destino: ");
			scanf("%d", &Destino);
			
			Percorrer(Origem, Destino,0,visitados, 0);
			
		}else if(Opcao == 5){
			Ordem=8;
			inicializarMatriz(Ordem);
			Matriz[1][2] = 12;
			Matriz[1][3] = 4;
			Matriz[2][3] = 6;
			Matriz[2][4] = 6;
			Matriz[3][2] = 10;
			Matriz[3][5] = 2;
			Matriz[4][6] = 6;
			Matriz[4][3] = 8;
			Matriz[5][2] = 2;
			Matriz[5][6] = 6;
			
			
		}else{
			break;
		}
		
	}while (Opcao <= 5 && Opcao >= 1);
}
