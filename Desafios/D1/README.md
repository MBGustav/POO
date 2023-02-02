Implemente a classe Pilha com as seguintes operações:

* Pilha (int capacidade)  - Construtor que cria uma pilha  com capacidade máxima
(parâmetro capacidade).

* Pilha ()  - Construtor. Se parâmetro  não for passado, considere  a capacidade
máxima = 10.

* ~Pilha() - Destrutor

* bool empilha(int x) - Insere o item  x no topo da pilha (push). Retorna "true"
em caso de sucesso e falso, caso contrário

* bool desempilha(int& x) - Desempilha o item x no topo da pilha. Retorna "true"
em caso de sucesso e falso, caso contrário

* int tamanho() const - retorna o número de itens presentes na pilha

* void  imprime() const  -  método  auxiliar para  impressão  da  pilha na  tela (console)

Utilize o arquivo main.cpp (anexo) para testar a classe criada.

---


Dicas:

Utilize 3 atributos em sua classe:

- int* valores  => array  alocado dinamicamente que  armazenará os  elementos da
pilha.  Esse array  deveria ser alocado no construtor e  desalocado no destrutor
da classes.

- int  topo =>  que indica  a posição  (indice  no array)  do topo  da pilha.  A
inserção e remoção dos elementos da pilha são realizados no topo da pilha.

- int capacidade => capacidade (número máximo de elementos) da pilha