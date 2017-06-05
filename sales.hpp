/*
 * sales.hpp
 *
 *  Created on: 3 de jun de 2017
 *      Author: noedelima
 */

#ifndef SALES_HPP_
#define SALES_HPP_

class saling{
public:
	string unity;
	string month;
	string saler;
	int total;
	saling(){
		//cout << "Construindo uma venda vazia" << endl;
		unity = "";
		month = "";
		saler = "";
		total = 0;
	}
	saling(string local, string date, string name, int count){
		//cout << "Construido uma venda normal" << endl;
		unity = local;
		month = date;
		saler = name;
		total = count;
	}
	//~saling(){cout << "Destrindo uma instância de venda" << endl;}
};

#endif /* SALES_HPP_ */
