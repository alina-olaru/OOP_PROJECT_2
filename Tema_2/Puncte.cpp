#include "Puncte.h"
#include "Object.h"
#include "ObArray.h"

Punct::Punct(int x , int y ) {
	this->x = x;
	this->y = y;
}


void Punct::display() 
{

	cout << "x= " << this->x << '\t' << "y= " << this->y << '\t' << "(" << this->x << "," << this->y << ")" << endl;
}


void Punct::citire_obiecte(int nr_ob) {
	for (int i = 0; i < nr_ob; i++) {
		Object::citire_obiecte(nr_ob);
		cout << endl << "Introdu coordonatele punctului curent.X este proiectia pe axa OX,y este proiectia pe OY";
		cout <<endl<< "x= ";
		cin >> x;
		cout << endl << "y= ";
		cin >> y;
	}
}