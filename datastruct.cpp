/*
 * datastruct.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: Noe de Lima Bezerra
 */


#include <iostream>
using namespace std;

template<typename T, typename Ref>
class database{
private:
	class node{
	public:
		T content;
		Ref key;
		node* ptrnext;
		node* ptrprevious;
		explicit node(){
			content = 0;
			key = 0;
			ptrnext = 0;
			ptrprevious = 0;
		}
		explicit node(T element, Ref value){
			content = element;
			key = value;
			ptrnext = 0;
			ptrprevious = 0;
		}
	};
	int count;
	node* ptractual;
	node* search(Ref find){
		if ((*ptractual).key == find){return ptractual;}
		else{
			node* start = ptractual;
			ptractual = (*ptractual).ptrnext;
			while (ptractual != start){
				if ((*ptractual).key == find){return ptractual;}
				else {ptractual = (*ptractual).ptrnext;}
			}
		}
		return 0;
	}
	void insert(node* newnode){
		if (count == 0){
			count++;
			ptractual = newnode;
			(*ptractual).ptrnext = ptractual;
			(*ptractual).ptrprevious = ptractual;
		}
		else{
			count++;
			node* ptrtemp = (*ptractual).ptrprevious;
			(*newnode).ptrnext = ptractual;
			(*newnode).ptrprevious = ptrtemp;
			(*ptrtemp).ptrnext = newnode;
			(*ptractual).ptrprevious = newnode;
			ptractual = newnode;
		}
	}
	node* remove(Ref key){
		if (count == 0){return 0;}
		else if (count == 1){
			if ((*ptractual).key == key){
				count--;
				node* temp = ptractual;
				ptractual = 0;
				return temp;
			}
		}
		else if (search(key)){
			node* temp = ptractual;
			node* temp2 = (*ptractual).ptrprevious;
			ptractual = (*ptractual).ptrnext;
			(*temp2).ptrnext = ptractual;
			(*ptractual).ptrprevious = (*temp).ptrprevious;
			count--;
			return temp;
		}
		return 0;
	}
public:
	explicit database(){
		count = 0;
		ptractual = 0;
	}
	~database(){
		while(ptractual != 0){
			node* ptrtemp = ptractual;
			ptractual = (*ptractual).ptrnext;
			pop((*ptrtemp).key);
		}
	}
	void push(T element, Ref value){
		node* inserting = new node(element, value);
		insert(inserting);
	}
	T pop(Ref value){
		node* temp = remove(value);
		T output;
		if (temp){output = (*temp).content;}
		else{output = "0";}
		delete temp;
		return output;
	}
	T find(Ref key){
		if(search(key)){
			return (*search(key)).content;
		}
		else{
			return "0";
		}
	}
	T pointer(){
		if(count > 0){
			return (*ptractual).content;
		}
		else{return "0";}
	}
	int size(){return count;}
};

template<typename T>
class queue{
private:
	class node{
	public:
		T content;
		node* ptrnext;
		explicit node(){
			content = "0";
			ptrnext = 0;
		}
		explicit node(T element){
			content = element;
			ptrnext = 0;
		}
	};
	int count;
	node* ptrfirst;
	node* ptrlast;
	node* search(T find){
		if (count == 0){return 0;}
		else if (count == 1){
			if ((*ptrfirst).content == find){return ptrfirst;}
			else{return 0;}
		}
		else{
			node* ptractual = ptrfirst;
			while (ptractual != ptrlast){
				if ((*ptractual).content == find){return ptractual;}
				else{ptractual = (*ptractual).ptrnext;}
			}
			if ((*ptractual).content == find){return ptractual;}
			else{return 0;}
		}
	}
	void insert(node* newelement){
		if (count == 0){
			count++;
			ptrfirst = newelement;
			ptrlast = newelement;
		}
		else{
			count++;
			(*ptrlast).ptrnext = newelement;
			ptrlast = newelement;
		}
	}
	node* remove(){
		if (count == 0){return 0;}
		else if (count == 1){
			count--;
			node* temp = ptrfirst;
			ptrfirst = 0;
			ptrlast = 0;
			return temp;
		}
		else{
			count--;
			node* temp = ptrfirst;
			ptrfirst = (*ptrfirst).ptrnext;
			return temp;
		}
	}
public:
	explicit queue(){
		cout << "\nConstruindo a fila\n";
		count = 0;
		ptrfirst = 0;
		ptrlast = 0;
	}
	~queue(){while (count != 0){pop();}}
	void push(T element){
		node* newnode = new node(element);
		insert(newnode);
	}
	T pop(){
		node* temp = remove();
		if(temp == 0){return "0";}
		T output = (*temp).content;
		delete temp;
		return output;
	}
	T find(T key){
		if (search(key) != 0){return (*search(key)).content;}
		else {return "0";}
	}
	T pointer(){
		if (count == 0){return "0";}
		else{return (*ptrfirst).content;}
	}
	int size(){return count;}
};

template<typename T>
class stack{
private:
	class node{
	public:
		T content;
		node* ptrnext;
		explicit node(){
			content = "0";
			ptrnext = 0;
		}
		explicit node(T element){
			content = element;
			ptrnext = 0;
		}
	};
	int count;
	node* ptrpoint;
	node* search(T find){
		if (count == 0){return 0;}
		else if (count == 1){
			if ((*ptrpoint).content == find){return ptrpoint;}
			else{return 0;}
		}
		else{
			node* ptractual = ptrpoint;
			while ((*ptrpoint).ptrnext != 0){
				if ((*ptractual).content == find){return ptractual;}
				else{ptractual = (*ptractual).ptrnext;}
			}
			if ((*ptractual).content == find){return ptractual;}
			else{return 0;}
		}
	}
	void insert(node* newelement){
		if (count == 0){
			count++;
			ptrpoint = newelement;
		}
		else{
			count++;
			(*newelement).ptrnext = ptrpoint;
			ptrpoint = newelement;
		}
	}
	node* remove(){
		if (count == 0){return 0;}
		else if (count == 1){
			count--;
			node* temp = ptrpoint;
			ptrpoint = 0;
			return temp;
		}
		else{
			count--;
			node* temp = ptrpoint;
			ptrpoint = (*ptrpoint).ptrnext;
			return temp;
		}
	}
public:
	explicit stack(){
		count = 0;
		ptrpoint = 0;
	}
	~stack(){while (count != 0){pop();}}
	void push(T element){
		node* newnode = new node(element);
		insert(newnode);
	}
	T pop(){
		node* temp = remove();
		if(temp == 0){return "0";}
		T output = (*temp).content;
		delete temp;
		return output;
	}
	T find(T key){
		if (search(key) != 0){return (*search(key)).content;}
		else{return "0";}
	}
	T pointer(){
		if (count == 0){return "0";}
		else{return (*ptrpoint).content;}
	}
	int size(){return count;}
};
