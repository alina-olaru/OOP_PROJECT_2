#pragma once
#include "Object.h"
class Punct:public Object
{
protected:
	int x;
	int y;
public:
	Punct(int x = 0, int y = 0);
	void display();
	void citire_obiecte(int nr_obiecte);

};

