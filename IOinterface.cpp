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
tree<tree<saling, int>, int> getdata(string path, string file, string extension){
	tree<tree<saling, int>, int> data;
	string content, output="";
	ifstream sales(path+file+extension);
	if(!sales){
		cout << "Falha na abertura do arquivo " << path+file+extension << endl;
		return data;
	}
	cout << "Documento "<< path+file+extension << " aberto com sucesso!" << endl;
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
		int unity = lexical_cast<int>(vecsplit[0]);
		int month = lexical_cast<int>(vecsplit[1]);
		int saler = lexical_cast<int>(vecsplit[2]);
		float total = lexical_cast<float>(vecsplit[3]);
		saling* sale = new saling(unity, month, saler, total);
		if(data.find(unity)){
			tree<saling, int>* T = data.find(unity);
			(*T).push(sale, month);
		}
		else{
			tree<saling, int>* T = new tree<saling, int>;
			(*T).push(sale, month);
			data.push(T, unity);
		}
	}
	sales.close();
	return data;
}
