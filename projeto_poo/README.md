# Estrutura Inicial para Classes de Grafos

## 1. Informações principais do grafo

Antes de implementar a estrutura, é importante definir algumas características do grafo.

### Direcionado ou não direcionado?

Um grafo pode ser:

```text
A -----> B
```

ou:

```text
A ----- B
```

No caso direcionado, a conexão possui sentido.

Exemplo:

```text
A -----> B
```

significa que existe uma aresta de `A` para `B`, mas não necessariamente de `B` para `A`.

No caso não direcionado, a conexão vale nos dois sentidos.

---

### Ponderado ou não ponderado?

Um grafo pode ter pesos nas arestas:

```text
A ---5--- B
```

ou apenas indicar a existência de conexão:

```text
A ----- B
```

Em grafos não ponderados, o peso pode ser tratado como `1` para padronizar a lógica dos métodos.

---

## 2. Entidades principais

### Grafo

A entidade `Grafo` representa a estrutura principal.

Ela precisa armazenar informações como:

* Quantos vértices existem;
* Quais vértices estão conectados;
* Se o grafo é direcionado ou não;
* Se o grafo é ponderado ou não;

A classe `Grafo` deve ser responsável por operações como:

* Adicionar vértices;
* Remover vértices;
* Adicionar arestas;
* Remover arestas;
* Verificar se existe conexão;
* Listar os vizinhos de um vértice;
* Imprimir o grafo.

---

### Aresta

A entidade `Aresta` representa uma conexão entre dois vértices.

Ela pode armazenar:

* Origem;
* Destino;
* Peso.

Em grafos não ponderados, o peso pode ser tratado como `1`.

Exemplo conceitual:

```text
origem: 0
destino: 2
peso: 5
```

---

## 3. Representação interna do grafo

Existem duas formas principais de representar um grafo internamente:

* Matriz de adjacência;
* Lista de adjacência.

---

## 4. Matriz de adjacência

A matriz de adjacência guarda o grafo como uma matriz:

```text
matriz[i][j]
```

Onde:

* `i` representa o vértice de origem;
* `j` representa o vértice de destino.

Ou seja:

```text
matriz[origem][destino]
```

---

### Sobre `i == j`

Quando `i == j`, estamos olhando a relação de um vértice com ele mesmo.

Normalmente, em algoritmos de caminho mínimo, o valor da diagonal principal é `0`, porque a distância de um vértice até ele mesmo é zero.

Exemplo:

```text
matriz[0][0] = 0
matriz[1][1] = 0
matriz[2][2] = 0
```

Porém, também é possível existir um laço, ou seja, uma aresta que sai de um vértice e volta para ele mesmo.

Exemplo:

```text
0 ----> 0
```

Nesse caso, `matriz[0][0]` poderia ter outro valor, dependendo da regra do programa.

Para uma implementação inicial, é mais simples considerar:

```text
matriz[i][i] = 0
```

---

## Valores da matriz

### Caso ponderado

Se o grafo for ponderado:

* Se não existe aresta, usar `INF`;
* Se existe aresta, usar o peso real da conexão.

Exemplo:

```text
matriz[0][1] = 12
matriz[0][2] = 4
matriz[1][0] = INF
```

---

### Caso não ponderado

Se o grafo não for ponderado:

* Se não existe aresta, pode usar `0` ou `INF`;
* Se existe aresta, usar `1`.

Para padronizar com algoritmos de caminho mínimo, pode ser melhor usar `INF` quando não existe conexão.

---

## 5. Exemplos de matrizes de adjacência

### A) Matriz Grafo ponderado orientado

```text
0   12  4
INF 0   6
INF 10  0
```

Interpretação:

```text
0 -> 1 com peso 12
0 -> 2 com peso 4
1 -> 2 com peso 6
2 -> 1 com peso 10
```

---

### B) Matriz Grafo ponderado não orientado

Como o grafo não é orientado, a matriz é simétrica.

```text
0   4   1
4   0   INF
1   INF 0
```

Interpretação:

```text
0 -- 1 com peso 4
0 -- 2 com peso 1
```

---

### C) Matriz Grafo não ponderado orientado

```text
0   1   1
INF 0   1
INF 1   0
```

Interpretação:

```text
0 -> 1
0 -> 2
1 -> 2
2 -> 1
```

---

### D) Matriz Grafo não ponderado não orientado

Como o grafo não é orientado, a matriz é simétrica.

```text
0   INF 1
INF 0   1
1   1   0
```

Interpretação:

```text
0 -- 2
1 -- 2
```

---

## 6. Lista de adjacência

Na lista de adjacência, cada vértice guarda uma lista com seus vizinhos.

Em vez de armazenar todas as combinações possíveis em uma matriz, a lista guarda apenas as conexões existentes.

---

### Exemplo geral

```text
0: (1, peso 4), (2, peso 1)
1: (0, peso 4)
2: (0, peso 1)
```

Isso significa:

```text
0 está conectado a 1 com peso 4
0 está conectado a 2 com peso 1
1 está conectado a 0 com peso 4
2 está conectado a 0 com peso 1
```

---

## 7. Exemplos de listas de adjacência

A seguir, as listas equivalentes às matrizes anteriores, considerando a convenção:

```text
matriz[i][j] = conexão de i para j
```

Ou seja:

```text
i = origem
j = destino
```

---

### A) Lista Grafo ponderado orientado

Matriz:

```text
0   12  4
INF 0   6
INF 10  0
```

Lista de adjacência:

```text
0: (1, peso 12), (2, peso 4)
1: (2, peso 6)
2: (1, peso 10)
```

---

### B) Lista Grafo ponderado não orientado

Matriz:

```text
0   4   1
4   0   INF
1   INF 0
```

Lista de adjacência:

```text
0: (1, peso 4), (2, peso 1)
1: (0, peso 4)
2: (0, peso 1)
```

---

### C) Lista Grafo não ponderado orientado

Matriz:

```text
0   1   1
INF 0   1
INF 1   0
```

Lista de adjacência:

```text
0: (1), (2)
1: (2)
2: (1)
```

---

### D) Lista Grafo não ponderado não orientado

Matriz:

```text
0   INF 1
INF 0   1
1   1   0
```

Lista de adjacência:

```text
0: (2)
1: (2)
2: (0), (1)
```

---

## 8. Lógica externa

A lógica externa não deve acessar diretamente a estrutura interna do grafo.

Ou seja, em vez de fazer:

```text
matriz[i][j]
```

o ideal é perguntar ao grafo:

```text
existe aresta entre i e j?
qual o peso entre i e j?
quais são os vizinhos de i?
```

Isso deixa o código mais organizado e evita que outras partes do programa dependam diretamente da forma como o grafo foi implementado.

Assim, tanto faz se o grafo usa matriz de adjacência ou lista de adjacência internamente.

A lógica externa apenas usa os métodos públicos da classe `Grafo`.

---

## 9. Métodos da classe Grafo

A classe `Grafo` pode começar com os seguintes métodos:

* Criar grafo com `N` vértices;
* Adicionar aresta;
* Remover aresta;
* Verificar se existe aresta;
* Obter peso de uma aresta;
* Obter vizinhos de um vértice;
* Retornar a quantidade de vértices;
* Imprimir o grafo.

---

## 10. Lógica dos métodos

### Criar grafo

Para criar um grafo, é necessário definir:

* Quantidade de vértices;
* Se é direcionado ou não;
* Se é ponderado ou não.

Exemplo conceitual:

```text
criar_grafo(3, false, true)
```

Significado:

```text
Cria um grafo com 3 vértices, não direcionado e ponderado.
```

---

### Adicionar aresta

Para adicionar uma aresta, o método deve receber:

* Origem;
* Destino;
* Peso, caso o grafo seja ponderado.

A lógica é:

```text
registrar conexão origem -> destino
```

Se o grafo não for direcionado, também é necessário registrar a conexão inversa:

```text
destino -> origem
```

Exemplo conceitual:

```text
adicionar_aresta(0, 2, 5)
```

Se o grafo for não direcionado:

```text
0 -> 2 com peso 5
2 -> 0 com peso 5
```

Se o grafo for direcionado:

```text
0 -> 2 com peso 5
```

---

### Buscar vizinhos

Para buscar os vizinhos de um vértice, o método deve:

1. Receber um vértice;
2. Verificar todos os vértices conectados a ele;
3. Retornar os vizinhos encontrados.

Exemplo conceitual:

```text
vizinhos(0)
```

Resultado esperado:

```text
1, 3, 4
```

Isso significa que o vértice `0` possui conexões com os vértices `1`, `3` e `4`.

---

### Obter peso

Para obter o peso de uma aresta, o método deve responder à pergunta:

```text
qual o peso da aresta entre A e B?
```

Exemplo conceitual:

```text
peso(0, 2)
```

Possíveis retornos:

```text
5
```

caso exista conexão com peso `5`, ou:

```text
INF
```

caso não exista conexão entre `0` e `2`.

---

## 11. Ideia principal

A classe `Grafo` deve esconder os detalhes internos da estrutura.

O restante do programa não precisa saber se o grafo usa matriz ou lista de adjacência.

Ele só precisa saber usar métodos como:

```text
adicionar_aresta()
remover_aresta()
existe_aresta()
peso()
vizinhos()
```

Com isso, a estrutura fica mais flexível, organizada e fácil de reaproveitar em algoritmos como:

* Busca em largura;
* Busca em profundidade;
* Dijkstra;
* Prim;
* Kruskal.
