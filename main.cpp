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
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "My name is NOAH\n\n" << endl;
	tree<saling, int> vendas = getdata();
	queue<saling> received = vendas.list();
	cout << "Foram listadas " << received.size() << " vendas" << endl;
	while(received.size()){
		saling V = *received.pop();
		cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
	}
	cout << "\n\n\nNormal exiting" << endl;
	return 0;
}
