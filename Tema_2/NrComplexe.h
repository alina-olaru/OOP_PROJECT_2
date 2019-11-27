#pragma once
#include "Object.h"
#include "Puncte.h"
//clasa NrComplex folosita pentru tabloul de numere complexe
class NrComplexe:public Object
{
	int real;
	int imaginar;
public:
	//constructor
	NrComplexe(int real = 0, int imagina = 0);
	void display();
	//supraincarcarile pt cin si cout
	friend istream & operator>>(istream&, NrComplexe&);
	friend ostream & operator<<(ostream&, NrComplexe&);
	NrComplexe operator+=(NrComplexe& ob);

};

