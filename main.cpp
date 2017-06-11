//============================================================================
// Name        : EDA-IC-Uff.cpp
// Author      : Noé de Lima Bezerra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "database.hpp"
#include "IOinterface.hpp"
#include "sales.hpp"
using namespace std;

int main() {
	cout << "Noé de lima Bezerra" << endl << endl;
	cout << "Universidade Federal Fluminense" << endl
			<< "Instituto de Computação" << endl
			<< "Programa de Mestrado" << endl
			<< "Trabalho da disciplina de estrutura de Dados e Algoritmos" << endl << endl;
	cout << "Para mais informações, ver enunciado e outros detalhes no arquivo README.txt" << endl << endl;
	string path, file, extension;
	path = "/home/noedelima/Documentos/11\ -\ Arquivos\ e\ Utilitários\ Diversos/workspace/EDA-IC-Uff/src/";
	cout << "Qual o nome do arquivo com os dados de venda? ";
	cin >> file;
	extension = ".txt";
	tree<tree<saling, int>, int> vendas = getdata(path, file, extension);
	// Aqui estão os resultados:
	// Total importado
	/*cout << endl << endl << endl;
	queue<tree<saling, int> > received = vendas.list();
	cout << "Foram importadas informações de " << received.size() << " filiais" << endl;
	while(received.size()){
		tree<saling, int> T = *received.pop();
		queue<saling> temp = T.list();
		while(temp.size()){
			saling V = *temp.pop();
			cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
		}
	}*/ // Para listar todas as entradas basta descomentar este pedaço de código
	// Primeira questão
	cout << endl << endl << endl;
	cout << "Resultados para a primeira questão:" << endl;
	queue<tree<saling, int> > quest1 = vendas.range(10, 20);
	while(quest1.size()){
		tree<saling, int> T = *quest1.pop();
		queue<saling> temp = T.list();
		while(temp.size()){
			saling V = *temp.pop();
			cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
		}
	}
	// Segunda questão
	cout << endl << endl << endl;
	cout << "Resultados para a segunda questão:" << endl;
	queue<tree<saling, int> > quest2 = vendas.range(10, 20);
	while(quest2.size()){
		tree<saling, int> T = *quest2.pop();
		queue<saling> temp = T.range(201708, 201710);
		while(temp.size()){
			saling V = *temp.pop();
			cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
		}
	}
	// Terceira questão
	cout << endl << endl << endl;
	cout << "Resultados para a terceira questão:" << endl;
	queue<tree<saling, int> > quest3 = vendas.list();
	while(quest3.size()){
		tree<saling, int> T = *quest3.pop();
		queue<saling> temp = T.range(201708, 201710);
		while(temp.size()){
			saling V = *temp.pop();
			cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
		}
	}
	cout << endl << endl << endl << "Saída normal, sem erros..." << endl;
	return 0;
}
