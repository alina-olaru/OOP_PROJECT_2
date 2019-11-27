#pragma once
#include "Object.h"
class ObArray:public Object
{
private:
	Object** p; // vector de pointeri
	int size; // numar de elemente la un moment dat
	int grows; // increment de creştere a dimensiunii
	int dimens; // dimensiune vector
public:
	ObArray();
	void redimensionare_array(int dimensiune);
	void shift_left(int pozitie);
	ObArray(int grows,int dimens,int size=0);//Constructor
	  ~ObArray();//Destructor
	  void RemoveAll();//Elimina toate obiectele din vector
	  int getSize(); // Intoarce numarul de elemente din vector.
	  int getdimens();
	  int add(Object* x); //Adauga un element la vector.
	  int insertAt(int i, Object* x);//Insereaza un element pe // o pozitie data
	  int removeAt(int i); //Elimina elementul de pe pozitia i
	  Object* getAt(int i); //Intoarce elementul de la pozitia i
	  void display();// Afisare elementelor din tablou.
	  void shift(int);
	  void citire();
	  bool has_only_digits(const string s);
};
