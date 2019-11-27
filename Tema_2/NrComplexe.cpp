#include "NrComplexe.h"

NrComplexe::NrComplexe(int real, int imaginar) {
	this->real = real;
	this->imaginar = imaginar;
}

void NrComplexe::display() {
	cout << this->real << "+" << this->imaginar << "i" << endl;
}

void NrComplexe::citire_obiecte(int nr_ob) {
	for (int i = 0; i < nr_ob; i++) {
		Object::citire_obiecte(nr_ob);
		cout << endl<<"Introdu coeficientii pentru numarul complex(este de forma a+bi unde a este partea reala,b partea imaginara" << endl;
		cout << "a= ";
		cin >> real;
		cout << endl << "b= ";
		cin >> imaginar;
	}
}