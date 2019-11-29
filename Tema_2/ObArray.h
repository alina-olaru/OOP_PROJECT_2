#pragma once
#include "Object.h"
//clasa ObArray contine un vector de pointeri catre clasa de baza Object
//si datele despre acesta
class ObArray:public Object
{
private:
	Object** p; // vector de pointeri
	int size; // numar de elemente la un moment dat
	int grows; // increment de creştere a dimensiunii
	int dimens; // dimensiune vector
	void insert_initial_elements();
public:
	//metodele
	ObArray();
	void redimensionare_array(int dimensiune);
	void shift_left(int pozitie);
	ObArray(int grows,int dimens,int size=0);//Constructor
	  ~ObArray();//Destructor
	  void RemoveAll();//Elimina toate obiectele din vector
	  int getSize(); // Intoarce numarul de elemente din vector.
	  int add(Object* x); //Adauga un element la vector.
	  int insertAt(int i, Object* x);//Insereaza un element pe // o pozitie data
	  int removeAt(int i); //Elimina elementul de pe pozitia i
	  Object* getAt(int i); //Intoarce elementul de la pozitia i
	  void display();// Afisare elementelor din tablou.
	  void shift_right(int);
	  void citire();
	  int getdimens()
	  {
		  return this->dimens;
	  }
	  Object* creeaza_obiect();
	//supraincarcari
	  friend ObArray operator+(Object& ob,ObArray& arr);
	//postix Increment 
	  ObArray operator++(int nr);
	//prefix Increment 
	  ObArray operator++();
	//postfix decrement
	  ObArray operator--(int nr);
	  //prefix decrement
	  ObArray operator--();
	//!= returneaza false daca vectorul e gol,true daca nu
	  bool operator!=(ObArray& ob);
	//returneaza daca in momentul actual mai e loc in vector(adica am mai putine elemente decat
	//dimensiunea totala.
	  bool operator/=(ObArray& ob);
	//shifteaza tot vectorul de obiecte la stanga cu o pozitie
	  ObArray operator<<=(ObArray& ob);
	//shifteaza tot vectorul de obiecte la dreapta cu o pozitie
	  ObArray operator>>=(ObArray& ob);
	//returneaza daca in momentul de fata toate elementele vectorului sunt de tip
	//Puncte sau de tip NrComplex (true) sau sunt combinate(false)
	  bool operator&=(ObArray& ob);
	//sterge toate elementele din vector
	  ObArray operator^=(ObArray& ob);
	//returneaza cate pozitii libere mai sunt in vector(alocate deja)
	  int operator|=(ObArray* ob);
	  //returneaza daca Array ul curent are aceeasi referinta (si dim) cu un alt array(parametru)
	  bool operator==(ObArray& ob);
	  ObArray operator+(ObArray);
	  ObArray& operator = (const ObArray&);
	  ObArray funtie_cu_ref();
	  ObArray functie_cu_temp();
	  ObArray functie_cu_temp_cu_ref();
	 // ObArray(const ObArray&);
	  void f(string c);
};
