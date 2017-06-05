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
	tree<tree<saling, int>, int> vendas = getdata();
	queue<tree<saling, int> > received = vendas.list();
	cout << "Foram listadas " << received.size() << " filiais" << endl;
	while(received.size()){
		tree<saling, int> T = *received.pop();
		queue<saling> temp = T.list();
		while(temp.size()){
			saling V = *temp.pop();
			cout << "Na filial " << V.unity << ", em " << V.month << ", o vendedor " << V.saler << " vendeu " << V.total << endl;
		}
	}
	cout << "\n\n\nNormal exiting" << endl;
	return 0;
}
