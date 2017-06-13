Noé de Lima Bezerra
noe_lima@id.uff.br
03 de junho de 2017

Universidade Federal Fluminense
Instituto de Computação
Programa de Mestrado
Trabalho da disciplina de estrutura de Dados e Algoritmos
Professor Luiz André Portes Paes Leme

ENUNCIADO
**************************************************************************************
Trabalho de Implementação

Os dados de venda da equipe de vendas de uma empresa estão armazenados em um arquivo txt que obedece ao seguinte formato: filial, ano_mês, cod_vendedor, total_vendido.

Faça um programa que carregue os dados do arquivo em estruturas de dados e que permita responder expressões como:

1) total de vendas das filiais com códigos entre 10 e 20
2) total de vendas das filiais com códigos entre 10 e 20 nos meses de Jan/17 até Jun/17
3) total de vendas de todas as filiais nos meses de Ago/17 até Out/17

As estruturas de dados devem permitir acesso eficiente para todos os tipos de expressões e a conjunção de condições sobre filiais e datas devem ser realizadas por meio de operação de interseção de conjuntos. Cada resumo de venda (linha) do arquivo deve dar origem a somente uma instância (objeto) no programa. Utilize as estruturas de dados mais eficientes para cada tipo de pergunta.
**************************************************************************************

Para solucionar esta questão foi adotada a seguinte estratégia:
* Elaboração de um arquivo vendas.txt com a estrutura apresentada
* Elaboração de uma classe para armazenar as linhas deste arquivo como instâncias de venda
* -> filial é um número inteiro
* -> ano_mês é um número inteiro composto por anomês (junto)
* -> código do vendedor é um número inteiro
* -> total vendido é um número número em ponto flutuante
* Elaboração de templates com estruturas de dados genéricas a serem utilizadas conforme a necessidade
* Elaboração de uma função para efetuar a leitura do  arquivo, criar as instâncias de venda e armazenar em uma estrutura de dados

Para compilar o conteúdo, é necessário instalar a biblioteca Boost, disponível no endereço:
http://www.boost.org
Todas as demais bibliotecas utilizadas fazem parte do padrão C++11
Compilado na seguinte versão:
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4)

A biblioteca boost foi utilizada na função de aquisição de dados a partir do arquivo txt, para auxiliar nas devidas conversões
foi utilizado um script em Python para gerar um arquivo de vendas para teste.

Apesar de haver mais estruturas de dados no arquivo database.hpp, apenas duas foram utilizadas:
* Arvore binária AVL (tree)
* fila (queue)

Os dados lidos na lista foram armazenados em uma árvore de árvores com a seguinte estrutura:
* Uma árvore com os dados de cada filial
* Uma árvore com as árvores de filiais

Além de métodos de busca de elementos individuais na árvore, tem método de busca por intervalo (range) e de busca por todos os elementos (list).
as buscas que retornam múltiplos elementos (range e list) retornam os resultados em uma fila (queue.

A questão 1) e 2), tem nessa estrutura uma forma de busca otimizada.
A questão 3) lista as árvores de todas as filiais, mas a busca em cada uma atende a otimização do intervalo
Uma implementação alternativa para a questão 3) seria implementar outra árvore classificada por ano_mes, mas isso duplicaria os dados na memória. Apenas por essa razão não foi implementada aqui, mas todos os códigos aqui permitem que isso seja facilmente implementado.

Também foi mantido uma busca por todos os elementos, apenas para demonstração, mas não faz parte do escopo do trabalho.


Finalmente, cabe observar que, há uma variável path cujo valor toma como referência o endereço utilizado no computador do autor.
Tanto no arquivo main.cpp quanto no arquivo gerarq.py, ela deve ser substituida pelos dados do computador onde este programa está sendo compilado.
