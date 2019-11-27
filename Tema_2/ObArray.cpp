#include "ObArray.h"
#include "Object.h"
using namespace std;
#include <string> 

#include <iostream>
#include <regex> 

//#include<>
ObArray::ObArray() {
	this->size = 0;
	this->dimens = 0;
	this->grows = 0;
	this->p = new Object* ();
}

ObArray::ObArray(int grows, int dimens, int size) {
	this->size = size;
	this->dimens = dimens;
	this->grows = grows;
	this->p = new Object * [this->dimens];
	cout << "Constructor arr" << endl;
	//Object::citire_obiecte(size);
}

ObArray::~ObArray() {

	for (int i = 0; i < size; i++) {
		delete this->p[i];
	}
	delete[] p;
	//this->size = 0;

	cout << endl << "Desstructor arr" << endl;
}

void ObArray::RemoveAll() {
	cout << "S-a ales sa se stearga tot vectorul" << endl;
	for (int i = 0; i < this->size; i++) {
		delete  this->p[i];
	}
	delete[] p;
	this->size = 0;


}

int ObArray::getSize() {
	return this->size;
}

int ObArray::add(Object* x) {//Adauga un element la vector.


	if (this->dimens == this->size) {
		cout << "inainte de adaugare" << endl;
		this->dimens = this->dimens + this->grows;
		this->redimensionare_array(this->dimens);
		cout << "Deasupra x";
	}


	this->p[this->size] = x;
	cout << "Sub x";
	this->size = this->size + 1;
	cout << this->dimens << "dim";
	return this->size;

}


void ObArray::redimensionare_array(int dimensiune) {
	Object** obj = new Object * [dimensiune];
	cout << "red";

	memcpy(obj, this->p, dimensiune * sizeof(Object*));
	cout << "red";

	delete[] this->p;
	cout << "red";

	this->p = obj;
	cout << "red";
}

void ObArray::display() {
	//cout << i + 1 << '\t' << this->dimens << '\t' << this->size << '\t' << this->grows << endl;
	for (int i = 0; i < size; i++) {
		
		this->p[i]->display();
		cout << endl;
	}
}

void ObArray::shift_left(int poz) {
	for (int i = poz; i < this->size-1; i++) {
		this->p[i] = this->p[i + 1];
	}
}
void ObArray::shift(int poz) {
	for (int i = this->size; i >= poz; i--) {
		this->p[i + 1] = this->p[i];
	}
}


int ObArray::insertAt(int i, Object* ob) {
	if (i < 1) {
		throw invalid_argument("Argument invalid");
	}
	if (size < i) {
		add(ob);
	}
	else
	{
		if (this->size == this->dimens) {
			this->dimens = this->dimens + this->grows;
			redimensionare_array(this->dimens);

		}
		shift(i);
		this->p[i - 1] = ob;
	}
}

int ObArray::removeAt(int i) {
	delete p[i - 1];
	shift_left(i-1);
	this->size = this->size - 1;
	return i;
}

Object* ObArray::getAt(int i) {
	return this->p[i];
}


bool ObArray::has_only_digits(const string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

void ObArray::citire() {
	while (1)
	{
		try {
			cout << "dimensiunea vectorului este: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> dimens;

			if (cin.fail()) {
				throw invalid_argument("Dimensiunea vectorului trebuie sa fie un numar intreg!");
				
			}
				


				if ((dimens < 1)){
					throw invalid_argument("Dimensiunea nu poate fi mai mica decat 1 si trebuie sa fie reprezentata de un numar INTREG. Va rugam sa reintroduceti datele.\n");
				
					//cin.clear();
				}

				
				break;
			
					
		}
		catch (const std::invalid_argument& arg) {
			cout << arg.what();
		}
	}
	while (1) {
		try {
			cout << endl << "Nr de elemente initial este: ";
			cin >> size;
			if ((size <1)||(size>this->dimens)) {
				throw invalid_argument("Nr de elemente initial trebuie sa fie pozitiv (sau 0).In mod evident,nr actual de elemente nu poate depasi nr de elemente alocate(dimens). Va rugam sa reintroduceti datele.\n");

				//cin.clear();
			}


			break;
		}
		catch (const std::invalid_argument & arg) {
			cout << arg.what();
		}
	}
	while (1) {
		try {
			cout << endl << "Incrementul de crestere este ";
			cin >> grows;
			if ((grows < 1) || (grows > this->dimens)) {
				throw invalid_argument("Incrementul de crestere nu poate fi mai mic decat 1 sau mai mare decat dimensiunea vectorului si trebuie sa fie reprezentat de un numar INTREG. Va rugam sa reintroduceti datele.\n");

				//cin.clear();
			}


			break;
		}
		catch (const std::invalid_argument & arg) {
			cout << arg.what();
		}
		}
	}




int ObArray::getdimens() {
	return this->getdimens();
}