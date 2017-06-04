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
		unity = "";
		month = "";
		saler = "";
		total = 0;
	}
	saling(string local, string date, string name, int count){
		unity = local;
		month = date;
		saler = name;
		total = count;
	}
};

#endif /* SALES_HPP_ */
