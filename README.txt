Noé de Lima Bezerra
noe_lima@id.uff.br
03 de junho de 2017

Universidade Federal Fluminense
Instituto de Computação
Programa de Mestrado
Trabalho da disciplina de estrutura de Dados e Algoritmos

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
* Elaboração de templates com estruturas de dados genéricas pra serem utilizadas conforme a necessidade
* Elaboração de uma função para efetuar a leitura do  arquivo, criar as instâncias de venda e armazenar em uma estrutura de dados

Para compilar o conteúdo, é necessário instalar a biblioteca Boost, disponível no endereço:
http://www.boost.org
Todas as demais bibliotecas utilizadas fazem parte do padrão C++11
Compilado na seguinte versão:
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4)

