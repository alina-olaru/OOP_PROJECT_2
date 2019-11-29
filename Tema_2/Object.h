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
	void f()
	{
		cout << "functia f din baza";
	}
	void f(int a)
	{
		cout << "functia f din baza cu paramtrul int= " << a << endl;
	}
	Object(const Object& ob) {};
	

};
