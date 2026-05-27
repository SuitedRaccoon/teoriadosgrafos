# Algoritmo de Dijkstra

## Início

1. Ter um grafo representado em uma tabela ou matriz de adjacência;
2. Escolher um ponto de partida;
3. Opcionalmente, escolher um ponto de destino. Se nenhum destino for escolhido, o algoritmo encontrará os menores caminhos do ponto inicial até todos os vértices;
4. Criar uma tabela com:
   - uma linha para Distância;
   - uma linha para Anterior;
   - uma marcação para indicar quais vértices já foram fechados.
5. Inicializar a tabela:
   - a distância do ponto de partida para ele mesmo recebe `0`;
   - todos os demais vértices recebem infinito, neste caso `1000`;
   - todos os valores de Anterior começam como `-`.

## Início do Loop

1. Escolha, entre todos os vértices ainda não fechados, aquele que possui a menor distância registrada na tabela.

2. Feche esse vértice, pois sua menor distância já foi determinada.

3. Se esse vértice for o ponto de destino, o algoritmo pode parar.

4. Observe os vizinhos do vértice atual na tabela do grafo.

5. Para cada vizinho ainda não fechado, calcule:

   ```md
   nova distância = distância do vértice atual + peso da aresta
