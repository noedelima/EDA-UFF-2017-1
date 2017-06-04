/*
 * IOinterface.cpp
 *
 *  Created on: 19 de mai de 2017
 *      Author: noedelima
 */

#include <iostream>
#include <fstream>
#include <string>
#include "database.hpp" // Data Structs to input data
#include "sales.hpp" // Class saling
#include <boost/algorithm/string.hpp> // Split line
#include <boost/lexical_cast.hpp> // Convert string to int
#include <vector> // To use a vector to receive fields in split
using namespace std;
using namespace boost;

/*********************************************************************
 *This function open a txt or csv file, get and split lines
 *Then, use it to create objects in saling class
 *So, set all objects in a Data Struct
 *********************************************************************/
queue<saling> getdata(){
	queue<saling> data;
	string salesname, path, extension, content, output="";
	path = "/home/noedelima/Documentos/11\ -\ Arquivos\ e\ Utilitários\ Diversos/workspace/EDA-IC-Uff/src/";
	extension = ".txt";
	ifstream sales;
	while (!sales.is_open()){
		cout << "Qual o nome do arquivo? " << endl;
		cin >> salesname;
		sales.open(path+salesname+extension);
		if (!sales){cout << "Falha na abertura do arquivo " << path+salesname+extension << endl;}
	}
	cout << "Documento "<< path+salesname+extension << " aberto com sucesso!" << endl;
	int i=100, line=0; // Max char to read in each line, and a line counter
	while(!sales.eof()){
		line++;
		output = "";
		char buffer[i];
		vector<string> vecsplit;
		sales.getline(buffer, i);
		if (line==1 || sales.eof()){continue;}
		output += buffer;
		split(vecsplit, output, is_any_of(","));
		string unity = vecsplit[0];
		string month = vecsplit[1];
		string saler = vecsplit[2];
		int total = lexical_cast<int>(vecsplit[3]);
		//cout << "Unidade " << unity
		//		<< ", em " << month
		//		<< ", Vendedor " << saler
		//		<< " vendeu "
		//		<< total << " unidades!" << endl;
		saling* sale = new saling(unity, month, saler, total);
		data.push(sale);
	}
	sales.close();
	return data;
}
