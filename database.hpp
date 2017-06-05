/*
 * database.hpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: noedelima
 */

#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <iostream>
using namespace std;

#define null nullptr;

/*******************************************************************
 * Este template é uma estrutura de dados circular duplamente
 * encadeada que serve para armazenar objetos de tipo genérico
 * Internamente ela utiliza nós (classe node) para armazenar
 * esses objetos do tipo T. Eles são indexados por uma referência
 * de classe Key (que pode ser, por exemplo, um inteiro).
 * Dentro desta estrutura tem os métodos de manipulação, que
 * cria nós, busca elementos, elimina nós, etc...
 *******************************************************************/
template<typename T, typename Ref>
class database{
private:
	class node{ // Célula para armazenar um elemento
	public:
		T* content; //Elemento armazenado do tipo T
		Ref key; // Chave de indexação para referência e busca
		node* ptrnext; // Ponteiro para o próximo elemento da lista
		node* ptrprevious; // Ponteiro para o elemento anterior da lista
		explicit node(){
			content = 0;
			key = 0;
			ptrnext = nullptr;
			ptrprevious = nullptr;
		}
		explicit node(T* element, Ref value){
			content = element;
			key = value;
			ptrnext = nullptr;
			ptrprevious = nullptr;
		}
	};
	int count; // Contador para o número de elementos na lista
	node* ptractual; // Ponteiro para um nó de referênica da lista circular
	node* search(Ref find){ // Busca o nó que contém a referência find
		if (count == 0){return nullptr;}
		if ((*ptractual).key == find){return ptractual;}
		else{
			node* start = ptractual;
			ptractual = (*ptractual).ptrnext;
			while (ptractual != start){
				if ((*ptractual).key == find){return ptractual;}
				else {ptractual = (*ptractual).ptrnext;}
			}
		}
		return nullptr;
	}
	void insert(node* newnode){ // Insere encadeia um novo nó na lista
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
	node* remove(Ref key){ // desencadeia e retorna um nó com referência key da lista
		if (count == 0){return nullptr;}
		else if (count == 1){
			if ((*ptractual).key == key){
				count--;
				node* temp = ptractual;
				ptractual = nullptr;
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
		return nullptr;
	}
public:
	explicit database(){ // Constrói uma estrutura vazia
		count = 0;
		ptractual = nullptr;
	}
	~database(){ // Destrói uma estrutura desalocando da memória todos os nós da lista
		while(ptractual != nullptr){
			node* ptrtemp = ptractual;
			ptractual = (*ptractual).ptrnext;
			pop((*ptrtemp).key);
		}
	}
	void push(T* element, Ref value){ // Cria um novo nó a partir de um elemento e uma chave e insere na lista
		node* inserting = new node(element, value);
		insert(inserting);
	}
	T* pop(Ref value){ // Busca um nó por uma chave key, deleta o nó e retorna o conteúdo
		node* temp = remove(value);
		T* output;
		if (temp){output = (*temp).content;}
		//else{output = null;}
		delete temp;
		return output;
	}
	T* find(Ref key){ // Busca o conteúdo de um nó através da referência key
		if(search(key)){
			return (*search(key)).content;
		}
		else{
			return null;
		}
	}
	T* pointer(){ // Informa o elemento atual da referência
		if(count > 0){
			return (*ptractual).content;
		}
		else{return null;}
	}
	T* pointernext(){ // Informa o próximo elemento da lista a partir da referência atual
		if(count > 0){
			return (*(*ptractual).ptrprevious).content;
		}
		else{return null;}
	}
	int size(){return count;} // Informa o número de elementos armazenados
};

/*******************************************************************
 * Este template é uma estrutura de dados simplesmente
 * encadeada que serve para armazenar objetos de tipo genérico
 * Internamente ela utiliza nós (classe node) para armazenar
 * esses objetos do tipo T.
 * Dentro desta estrutura tem os métodos de manipulação, que
 * cria nós, busca elementos, elimina nós, etc...
 * Esta estrutura é implementada como uma fila, o primeiro
 * que entra é o primeiro que sai
 *******************************************************************/
template<typename T>
class queue{
private:
	class node{
	public:
		T* content;
		node* ptrnext;
		explicit node(){
			content = null;
			ptrnext = nullptr;
		}
		explicit node(T* element){
			content = element;
			ptrnext = nullptr;
		}
	};
	int count;
	node* ptrfirst;
	node* ptrlast;
	node* search(T* find){
		if (count == 0){return nullptr;}
		else if (count == 1){
			if ((*ptrfirst).content == find){return ptrfirst;}
			else{return nullptr;}
		}
		else{
			node* ptractual = ptrfirst;
			while (ptractual != ptrlast){
				if ((*ptractual).content == find){return ptractual;}
				else{ptractual = (*ptractual).ptrnext;}
			}
			if ((*ptractual).content == find){return ptractual;}
			else{return nullptr;}
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
		if (count == 0){return nullptr;}
		else if (count == 1){
			count--;
			node* temp = ptrfirst;
			ptrfirst = nullptr;
			ptrlast = nullptr;
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
		count = 0;
		ptrfirst = nullptr;
		ptrlast = nullptr;
	}
	~queue(){while (count != 0){pop();}}
	void push(T* element){
		node* newnode = new node(element);
		insert(newnode);
	}
	T* pop(){
		node* temp = remove();
		if(temp){
			T* output = (*temp).content;
			delete temp;
			return output;
		}
		else {return null;}
	}
	T* find(T* key){
		if (search(key) != nullptr){return (*search(key)).content;}
		else {return null;}
	}
	T* pointer(){
		if (count != 0){
			return (*ptrfirst).content;
		}
		else {return null;}
	}
	T* last(){
		if (count != 0){
			return (*ptrlast).content;
		}
		else {return null;}
	}
	int size(){return count;}
};

/*******************************************************************
 * Este template é uma estrutura de dados simplesmente
 * encadeada que serve para armazenar objetos de tipo genérico
 * Internamente ela utiliza nós (classe node) para armazenar
 * esses objetos do tipo T.
 * Dentro desta estrutura tem os métodos de manipulação, que
 * cria nós, busca elementos, elimina nós, etc...
 * Esta estrutura é implementada como uma pilha, o último
 * que entra é o primeiro que sai
 *******************************************************************/
template<typename T>
class stack{
private:
	class node{
	public:
		T* content;
		node* ptrnext;
		explicit node(){
			content = null;
			ptrnext = nullptr;
		}
		explicit node(T* element){
			content = element;
			ptrnext = nullptr;
		}
	};
	int count;
	node* ptrpoint;
	node* search(T* find){
		if (count == 0){return nullptr;}
		else if (count == 1){
			if ((*ptrpoint).content == find){return ptrpoint;}
			else{return nullptr;}
		}
		else{
			node* ptractual = ptrpoint;
			while ((*ptrpoint).ptrnext != nullptr){
				if ((*ptractual).content == find){return ptractual;}
				else{ptractual = (*ptractual).ptrnext;}
			}
			if ((*ptractual).content == find){return ptractual;}
			else{return nullptr;}
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
		if (count == 0){return nullptr;}
		else if (count == 1){
			count--;
			node* temp = ptrpoint;
			ptrpoint = nullptr;
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
		ptrpoint = nullptr;
	}
	~stack(){while (count != 0){pop();}}
	void push(T* element){
		node* newnode = new node(element);
		insert(newnode);
	}
	T* pop(){
		node* temp = remove();
		if(temp == nullptr){return null;}
		T* output = (*temp).content;
		delete temp;
		return output;
	}
	T* find(T* key){
		if (search(key) != nullptr){return (*search(key)).content;}
		else{return null;}
	}
	T* pointer(){
		if (count == 0){return null;}
		else{return (*ptrpoint).content;}
	}
	int size(){return count;}
};

/*******************************************************************
 * Este template é uma estrutura de dados em Árvore Balanceada AVL
 * que serve para armazenar objetos de tipo genérico
 * Internamente ela utiliza nós (classe node) para armazenar
 * esses objetos do tipo T. Eles são indexados por uma referência
 * de classe Key (que pode ser, por exemplo, um inteiro).
 * Dentro desta estrutura tem os métodos de manipulação, que
 * cria nós, busca elementos, elimina nós, etc...
 * Esta estrutura é implementada como uma pilha, o último
 * que entra é o primeiro que sai
 *******************************************************************/
template<typename T, typename Ref>
class tree{
private:
	class node{
	public:
		T* content;
		Ref key;
		node* ptrtop;
		node* ptrleft;
		int level_left;
		node* ptrright;
		int level_right;
		node(){
			content = null;
			key = 0;
			ptrtop = nullptr;
			ptrleft = nullptr;
			level_left = 0;
			ptrright = nullptr;
			level_right = 0;
		}
		node(T* ptrelement, Ref index){
			content = ptrelement;
			key = index;
			ptrtop = nullptr;
			ptrleft = nullptr;
			level_left = 0;
			ptrright = nullptr;
			level_right = 0;
		}
		int height(){
			if(level_left > level_right){
				return level_left;
			}
			else{
				return level_right;
			}
		}
		int inserting(node* element){
			if(element->key <= this->key){
				if(ptrleft){
					level_left = 1 + (*ptrleft).inserting(element);
				}
				else{
					ptrleft = element;
					(*element).ptrtop = this;
					level_left = 1;
				}
			}
			else{
				if(ptrright){
					level_right = 1 + (*ptrright).inserting(element);
				}
				else{
					ptrright = element;
					(*element).ptrtop = this;
					level_right = 1;
				}
			}
			if (level_right > level_left){return level_right;}
			else {return level_left;}
		}
		void getdata(queue<T>* listing){
			if(ptrleft){(*ptrleft).getdata(listing);}
			T* data = new T;
			*data = *this->content;
			(*listing).push(data);
			if(ptrright){(*ptrright).getdata(listing);}
		}
		T* search(Ref KEY){
			if(this->key == KEY){return this->content;}
			else if(ptrleft && this->key > KEY){return (*this->ptrleft).search(KEY);}
			else if(ptrright && this->key < KEY){return (*this->ptrright).search(KEY);}
			else {return nullptr;}
		}
	};
	node* ptrfather;
	int count;
public:
	tree(){
		ptrfather = nullptr;
		count = 0;
	}
	int size(){return count;}
	void push(T* element, Ref index){
		node* newelement = new node(element, index);
		if (ptrfather){
			(*ptrfather).inserting(newelement);
			count += 1;
		}
		else{
			ptrfather = newelement;
			count = 1;
		}
	}
	queue<T> list(){
		queue<T> lista;
		if(ptrfather){(*ptrfather).getdata(&lista);}
		return lista;
	}
	T* find(Ref value){
		if(ptrfather){return (*ptrfather).search(value);}
		else {return null;}
	}
};

#endif /* DATABASE_HPP_ */
