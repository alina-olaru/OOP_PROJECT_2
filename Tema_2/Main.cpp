#include "ObArray.h"
#include <random>
using namespace std;
#include "NrComplexe.h" 
#include <iostream>
#include "Puncte.h"
#include <string>

//metoda de afisare a meniului(am facut-o separat pt lizibilitate in main)
void afis_meniu() {
	cout << endl<< "--------------------------------------------------------------" << endl;
	cout << "OPTIUNI POSIBILE" << endl;
	cout << "1)\tAfisare obiecte " << endl;
	cout << "2)\tElimina toate obiectele din vector" << endl;
	cout << "3)\tIntoarce numarul de elemente din vector" << endl;
	cout << "4)\tAdauga un element la vector." << endl;
	cout << "5)\tInsereaza un element pe  o pozitie data" << endl;
	cout << "6)\tElimina elementul de pe pozitia i(citita)" << endl;
	cout << "7)\t/Intoarce elementul de la pozitia i" << endl;
	cout << "8)\tIesire din program" << endl;
}
int main() {

	//fac un obiect de tip ObArray si apelez metoda de citire pt a completa campurile necesare clasei.
	ObArray* test = new ObArray();
	test->citire();
	int var;
	//creez obiectul de lucru , acesta e de tip object ,dar nu aloc memorie de tip NrComplex sau Punct,
	//aici,ci astept sa introduce userul o varianta.
	Object* ob;
	while (1)
	{
		afis_meniu();
		//intr-un while infinit,cu bloc try-catch am citit optiunea(pt a fi valida tb sa fie
		//intre 1-8 (meniu))
		while (1) {
			try {
				cout << "Introdu optiunea: ";
				cin >> var;
				if ((var < 1) || (var > 9)) {
					throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");

				}
				break;
			}
			catch (const std::invalid_argument & arg) {
				cout << endl << arg.what() << endl;
			}
		}

		try
		{//folosind un switch am apelat metodele aferente fiecarei optiuni
			switch (var)
			{
			case 1:
				test->display();
				break;
			case 2:
				test->RemoveAll();
				test->display();
				break;
			case 3:
			{
				int rez = test->getSize();
				cout << "Nr de elemente din vector in acest moment este " << rez << endl;
				break;
			}
			case 4:
			{
				ob = test->creeaza_obiect();
				test->add(ob);
				break;
			}
			case 5:
			{
				int poz;
				while (1) {
					cout << endl << "Pe ce pozitie doriti sa inserati?" << endl;

					try {
						//try-catch pt a nu aparea inconsistente sau a introduce erori 
						cin >> poz;
						if (poz < 0) {
							throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
						}
						break;
					}
					catch (const std::invalid_argument & arg) {
						cout << endl << arg.what();
					}
				}
				ob = test->creeaza_obiect();
				test->insertAt(poz, ob);
				cout << endl << "S-a adaugat elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
				test->display();
				break;
			}
			case 6:
			{
				int del;
				while (1) {
					cout << endl << "De pe ce pozitie vrei sa elimini elementul?" << endl;

					try {
						//try-catch pt a nu aparea inconsistente sau a introduce erori 

						cin >> del;
						if (del < 0) {
							throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
						}
						
						if (del > test->getSize()) {
							throw invalid_argument("Nu se pot introduce pozitii mai mari decat dimensiunea vectorului.Doar pozitii pozitive");
						}
						break;

					}
					catch (const std::invalid_argument & arg) {
						cout << endl << arg.what();
					}
				}
				test->removeAt(del);
				cout << endl << "S-a sters elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
				test->display();
				break;
			}
			case 7:
			{

				int poz;
				while (1) {
					cout << endl << "De pe ce pozitie vrei sa obtii elementul?" << endl;
					try {
						cin >> poz;
						if (poz < 0) {
							//try-catch pt a nu aparea inconsistente sau a introduce erori 

							throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
						}
						break;

					}
					catch (const std::invalid_argument & arg) {
						cout << endl << arg.what();
					}
				}

				Object* rez = test->getAt(poz);
				if (rez == NULL)
				{
					cout << "Nu exista element pe pozitia respectiva!" << endl;
				}
				else
				{
					cout << endl << "S-a intors elementul urmator: " << endl;
					rez->display();
				}

				break;
			}
			case 8:
				exit(0);

			}
		}
		catch (const std::invalid_argument & arg)
		{
			cout << endl << arg.what() << endl;
		}
		//catch-ul de mai jos are rolul de a prinde ABSOLUT ORICE EROARE apare.
		catch (...)
		{
			cout << endl << "A aparut o eroare!" << endl;
		}



	}

	
	//varianta de mai jos este cea in care nu se citeste nimic de la tastatura,toate campurile
	//optiunile si valorile fiind randomizate folosind biblioteca <random>



	/*
ObArray* test = new ObArray();
test->citire();


int var;
Object* ob;
while (1)
{
	afis_meniu();
	while (1) {
		try {
		//	cout << "Introdu optiunea: ";
			//cin >> var;
			std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 8);
			var = distribution(generator);
			cout << "S-a ales varianta " << var << '\t' << "din meniu" << endl;
			afis_meniu();
			if ((var < 1) || (var > 9)) {
				throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");

			}
			break;
		}
		catch (const std::invalid_argument & arg) {
			cout << endl << arg.what() << endl;
		}
	}

	try
	{
		switch (var)
		{
		case 1:
			test->display();
			break;
		case 2:
			test->RemoveAll();
			test->display();
			break;
		case 3:
		{
			int rez = test->getSize();
			cout << "Nr de elemente din vector in acest moment este " << rez << endl;
			break;
		}
		case 4:
		{
			ob = test->creeaza_obiect();
			test->add(ob);
			break;
		}
		case 5:
		{
			int poz;
			while (1) {
				cout << endl << "Pe ce pozitie doriti sa inserati?" << endl;

				try {
					//cin >> poz;
					std::default_random_engine generator_pozitie;
					std::uniform_int_distribution<int> distributie_pozitie(1,test->getSize());
					poz = distributie_pozitie(generator_pozitie);
					cout << endl << "Pozitia generata este " << poz << endl;
					if (poz < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					break;
				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}
			}
			ob = test->creeaza_obiect();
			test->insertAt(poz, ob);
			cout << endl << "S-a adaugat elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
			test->display();
			break;
		}
		case 6:
		{
			int del;
			while (1) {
				cout << endl << "De pe ce pozitie vrei sa elimini elementul?" << endl;

				try {
					//cin >> del;
					std::default_random_engine generator_pozitie;
					std::uniform_int_distribution<int> distributie_pozitie(1, test->getSize());
					del = distributie_pozitie(generator_pozitie);
					cout << endl << "Pozitia generata este " << del << endl;
					if (del < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					break;

				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}
			}
			test->removeAt(del);
			cout << endl << "S-a sters elementul introdus de dvs ,iar acum vectorul arata asa: " << endl;
			test->display();
			break;
		}
		case 7:
		{

			int poz;
			while (1) {
				cout << endl << "De pe ce pozitie vrei sa obtii elementul?" << endl;
				try {
				//	cin >> poz;
					std::default_random_engine generator_pozitie;
					std::uniform_int_distribution<int> distributie_pozitie(1, test->getSize());
					poz = distributie_pozitie(generator_pozitie);
					cout << endl << "Pozitia generata este " << poz << endl;
					if (poz < 0) {
						throw invalid_argument("Nu se pot introduce pozitii negative.Doar pozitii pozitive");
					}
					break;

				}
				catch (const std::invalid_argument & arg) {
					cout << endl << arg.what();
				}
			}

			Object* rez = test->getAt(poz);
			if (rez == NULL)
			{
				cout << "Nu exista element pe pozitia respectiva!" << endl;
			}
			else
			{
				cout << endl << "S-a intors elementul urmator: " << endl;
				rez->display();
			}

			break;
		}
		case 8:
			exit(0);

		}
	}
	catch (const std::invalid_argument & arg)
	{
		cout << endl << arg.what() << endl;
	}
	catch (...)
	{
		cout << endl << "A aparut o eroare!" << endl;
	}



}

*/
}

