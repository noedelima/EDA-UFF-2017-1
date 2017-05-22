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
using namespace std;

/*
template<typename T, typename Ref>
class node2{
public:
	T content;
	Ref key;
	node2* ptrnext;
	node2* ptrprevious;
	explicit node2(T element, Ref value){
		cout << "Contruindo nó fictício" << endl;
		content = element;
		key = value;
		ptrnext = NULL;
		ptrprevious = NULL;
	}
	~node2(){cout << "Destruindo nó fictício" << endl;}
	void hello(){cout << "Método de nó fictício" << endl;}
};
*/

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "My name is NOAH\n\n" << endl;
	int choice=1;
	while (choice != 0){
		cout << "\n\n\n" << endl;
		cout << "Choose what to do next:\n";
		cout << "1 - database" << endl;
		cout << "2 - queue" << endl;
		cout << "3 - stack" << endl;
		cout << "0 - quit" << endl;
		cout << "Type your choice: ";
		cin >> choice;
		switch (choice){
			case 1:
				database<string, int> estrutura1;
				int option1;
				string value1;
				cout << "\nType an integer to insert in database or 0 to exit: ";
				cin >> option1;
				cout << "Type a value to this entry: ";
				if(option1 != 0){cin >> value1;}
				while (option1 != 0){
					estrutura1.push(value1, option1);
					cout << "\nInserting " << option1 << " in database." << endl;
					cout << "\nType an integer to insert in database or 0 to exit: ";
					cin >> option1;
					cout << "Type a value to this entry: ";
					if(option1 != 0){cin >> value1;}
				}
				cout << "\nTotal size is: " << estrutura1.size() << endl;
				cout << "\nType an integer to remove from database or 0 to exit: ";
				cin >> option1;
				while (option1 != 0){
					cout << "\nRemoving " << estrutura1.pop(option1) << " from database." << endl;
					cout << "\nType an integer to remove from database or 0 to exit: ";
					cin >> option1;
				}
				cout << "\nThe new size of database is: " << estrutura1.size() << endl;
				cout << "\nType an integer to search in database or 0 to exit: ";
				cin >> option1;
				while (option1 != 0){
					string FIND = estrutura1.find(option1);
					if(FIND != "0"){cout << "Was found " << FIND << " in database" << endl;}
					else{cout << option1 << " was not found in database" << endl;}
					cout << "\nType an integer to search in database or 0 to exit: ";
					cin >> option1;
				}
				cout << "\nThe current value in database is: " << estrutura1.pointer() << endl;
				break;
			/*case 2:
				queue<string> estrutura2;
				int option2;
				string value2;
				cout << "\nType an integer to insert in queue or 0 to exit: ";
				cin >> option2;
				cout << "Type a value to this entry: ";
				if(option2 != 0){cin >> value2;}
				while (option2 != 0){
					estrutura2.push(value2);
					cout << "\nInserting value " << value2 << endl;
					cout << "Now, it's " << estrutura2.size() << " elements in queue." << endl;
					cin >> option2;
					cout << "Type a value to this entry: ";
					if(option2 != 0){cin >> value2;}
				}
				cout << endl;
				cout << "Type 1 to remove from queue or anything else to see it (0 to exit): ";
				cin >> option2;
				string actual2;
				while (option2 != 0){
					if (option2 == 1){
						actual2 = estrutura2.pop();
						cout << "The value " << actual2 << " was removed!" << endl;
					}
					else{
						actual2 = estrutura2.pointer();
						cout << "The actual value is " << actual2 << endl;
					}
					cout << "Type 1 to remove from queue or anything else to see it: ";
					cin >> option2;
				}
				cout << "\nTotal size is " << estrutura2.size() << " and the actual content is: ";
				cout << estrutura2.pointer() << endl;
				break;
			default:
				stack<string> estrutura3;
				int option3;
				string value3;
				cout << "\nType an integer to insert in stack or 0 to exit: ";
				cin >> option3;
				cout << "Type a value to this entry: ";
				if(option3 != 0){cin >> value3;}
				while (option3 != 0){
					estrutura3.push(value3);
					cout << "\nInserting value " << value3 << endl;
					cout << "Now, it's " << estrutura3.size() << " elements in stack." << endl;
					cin >> option3;
					cout << "Type a value to this entry: ";
					if(option3 != 0){cin >> value3;}
				}
				cout << endl;
				cout << "Type 1 to remove from stack or anything else to see it (0 to exit): ";
				cin >> option3;
				string actual3;
				while (option3 != 0){
					if (option3 == 1){
						actual3 = estrutura3.pop();
						cout << "The value " << actual3 << " was removed!" << endl;
					}
					else{
						actual3 = estrutura3.pointer();
						cout << "The actual value is " << actual3 << endl;
					}
					cout << "Type 1 to remove from stack or anything else to see it: ";
					cin >> option3;
				}
				cout << "\nTotal size is " << estrutura3.size() << " and the actual content is: ";
				cout << estrutura3.pointer() << endl;*/
		}
	}
	cout << "\n\n\nNormal exiting" << endl;
	return 0;
}
