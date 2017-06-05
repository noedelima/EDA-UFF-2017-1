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
	int unity;
	int month;
	int saler;
	float total;
	saling(){
		unity = 0;
		month = 0;
		saler = 0;
		total = 0;
	}
	saling(int local, int date, int code, float value){
		unity = local;
		month = date;
		saler = code;
		total = value;
	}
};

#endif /* SALES_HPP_ */
