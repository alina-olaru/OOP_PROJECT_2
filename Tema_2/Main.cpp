#include "ObArray.h"
using namespace std;
#include "NrComplexe.h"

#include <iostream>
//#include<>
#include "Puncte.h"
#include <string>


void afis_meniu() {
	cout << "OPTIUNI POSIBILE" << endl;
	cout << "1)\tAfisare obiecte " << endl;
	cout << "2)\tElimina toate obiectele din vector" << endl;
	cout << "3)\t/ Intoarce numarul de elemente din vector" << endl;
	cout << "4)\tAdauga un element la vector." << endl;
	cout << "5)\tInsereaza un element pe  o pozitie data" << endl;
	cout << "6)\tElimina elementul de pe pozitia i(citita)" << endl;
	cout << "7)\t/Intoarce elementul de la pozitia i" << endl;
	cout << "8)\tAfisare elementelor din tablou." << endl;
	cout << "9)\tIesire din program" << endl;
}
int main() {

	ObArray* test = new ObArray();
	Object* deriv;
	test->citire();
	int ch;
	while (1) {
		try {
			cout << endl<<"Nr complexe-1" << endl;
			cout << "Puncte-2" << endl;
			cin >> ch;
			if ((ch != 1) && (ch != 2)) {
				throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");


			}
			break;
		}
		catch (const std::invalid_argument & arg) {
			cout<<endl<< arg.what();
		}

	}
	switch (ch) {
	case 1: {
		deriv = new NrComplexe();
		deriv->citire_obiecte(test->getSize());
		cout << endl;
		///test->display();
		while (1) {
			afis_meniu();
			int var;
			try {
				cin >> var;
				if ((var < 1) || (var > 9)) {
					throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");
				
				}
				break;
			}
			catch (const std::invalid_argument & arg) {
				cout << endl << arg.what();
			}

			switch (var) {
			case 1: {
				cout << endl;
				test->display();
				break;
			}
			case 2: {
				test->RemoveAll();
				test->display();
				break;
			}
			case 3: {
				int rez = test->getSize();
				cout << "Nr de elemente din vector in acest moment este " << rez << endl;
				break;
			}
			case 4: {
				NrComplexe* local = new NrComplexe();
				local->citire_obiecte(1);
				test->add(local);
				cout << endl << "S-a adaugat elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
				test->display();
				break;
			}

			case 5: {
				NrComplexe* local = new NrComplexe();
				local->citire_obiecte(1);
				cout << "Pe ce pozitie doriti?" << endl;
				int poz;
				try {
					cin >> poz;
					if (poz < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					/*if (poz > test->getdimens()) {
						cout << endl << "";

					}*/
					if (poz > test->getSize()) {
						throw invalid_argument("Nu se poate insera pe pozitia introdusa pentru ca vectorul nu are destule elemente");
					}
					break;
				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}
				test->insertAt(poz, local);
				cout << endl << "S-a adaugat elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
				test->display();
				break;
				
			}
			case 6: {
				cout << endl << "De pe ce pozitie vrei sa elimini elementul?" << endl;
				int del;
				try {
					cin >> del;
					if (del < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					if (del > test->getSize()) {
						throw invalid_argument("Nu poti sterge elementul de pe pozitia respectiva pentru ca vectorul nu are destule valori(nu se ajunge cu elemente pe pozitia introdusa");

					}
					break;
					
				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}
				test->removeAt(del);
				cout << endl << "S-a sters elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
				test->display();
				break;
			}
			case 7: {
				cout << endl << "De pe ce pozitie vrei sa obtii elementul?" << endl;
				int del;
				try {
					cin >> del;
					if (del < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					if (del > test->getSize()) {
						throw invalid_argument("Nu poti obtine elementul de pe pozitia respectiva pentru ca vectorul nu are destule valori(nu se ajunge cu elemente pe pozitia introdusa");

					}
					break;

				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}

				test->getAt(del);
				break;
			}
			case 8: {
				test->display();
				break;
			}
			case 9: {
				break;
			}
			}
		}
		
		break;
	}
	case 2: {
		deriv = new Punct();
		deriv->citire_obiecte(test->getSize());
		cout << endl;
		

		while (1) {
			afis_meniu();
			int var;
			try {
				cin >> var;
				if ((var < 1) || (var > 9)) {
					throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");

				}
				break;
			}
			catch (const std::invalid_argument & arg) {
				cout << endl << arg.what();
			}

			switch (var) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}

			case 5: {
				break;
			}
			case 6: {
				break;
			}
			case 7: {
				break;
			}
			case 8: {
				break;
			}
			case 9: {
				break;
			}
			}
		}

		break;
	}

	}

		
}


/*

la stergere vreau redimensionare si sa mi dezaloce meoria(plus scade size-ul initial pt obiectul respectiv)






*/