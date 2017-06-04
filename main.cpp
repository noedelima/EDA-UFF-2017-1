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
	queue<saling> vendas = getdata();
	while(vendas.size()){
		saling V = *vendas.pop();
		cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
	}
	cout << "\n\n\nNormal exiting" << endl;
	return 0;
}
