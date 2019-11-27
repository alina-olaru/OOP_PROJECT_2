#pragma once
#include "Object.h"
//clasa Punct folosita pentru tabloul de numere complexe

class Punct:public Object
{
protected:
	int x;
	int y;
public:
	//constructor
	Punct(int x = 0, int y = 0);
	void display();
	//supraincarcarile pt cin si cout
	friend istream & operator>>(istream&, Punct&);
	friend ostream & operator<<(ostream&, Punct&);
	 Punct operator+=(Punct& ob);
	
};

