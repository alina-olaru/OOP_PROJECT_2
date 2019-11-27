#pragma once
#include "Object.h"
class NrComplexe:public Object
{
	int real;
	int imaginar;
public:
	NrComplexe(int real = 0, int imagina = 0);
	void display();
	void citire_obiecte(int nr_obiecte);

};

