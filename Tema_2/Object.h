#pragma once
using namespace std;
#include <iostream>
//clasa de baza
class Object
{
public:
	Object() {
		//cout << "constructor" << endl;
	}
	virtual ~Object() {
		//cout << "destructor";
	}
	virtual void display() = 0;
	

};
