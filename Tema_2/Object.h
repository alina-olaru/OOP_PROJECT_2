#pragma once
using namespace std;
#include <iostream>

class Object
{
public:
	Object() {
		cout << "constructor" << endl;
	}
	virtual ~Object() {
		cout << "destructor";
	}
	virtual void display() = 0;
	virtual void citire_obiecte(int nr_obiecte);

};
