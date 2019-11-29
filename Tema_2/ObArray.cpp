#include "ObArray.h"
#include "Object.h"
#include "Puncte.h"
#include "NrComplexe.h"
#include <random>
using namespace std;
#include <string> 

#include <iostream>
#include <regex> 

//#include<>
//constructorul neparametrizat
ObArray::ObArray() {
	this->size = 0;
	this->dimens = 0;
	this->grows = 0;
}
//constructorul parametrizat
ObArray::ObArray(int grows, int dimens, int size) {
	//Am facut verificari pentru fiecare parametru in parte (cu blocuri throw-catch)
	if(dimens<0 || size<0)
	{
		throw invalid_argument("Parametrii dimens si size trebuie sa fie numere naturale >= 0\n");
	}
	
	if(dimens<size)
	{
		throw invalid_argument("Parametrul size trebuie sa fie un numar intreg mai mare decat parametrul dimens\n");
	}

	if(grows < 1)
	{
		throw invalid_argument("Parametrul grow trebuie sa un numar intreg mai mare sau egal cu 1\n");
	}

	//initializarea valorilor numerice
	this->size = size;
	this->dimens = dimens;
	this->grows = grows;
	//alocare memorie pt vectorul de obiecte
	this->p = new Object * [this->dimens];
	cout << "Constructor arr" << endl;
	//citirea elementelor initiale
	this->insert_initial_elements();
}
//destructorul	
ObArray::~ObArray() {
//Se dezaloca memoria pentru fiecare instanta
	for (int i = 0; i < size; i++) {
		delete this->p[i];
	}
	// si apoi se dezaloca memoria si pt vectorul de obiecte p.
	delete[] p;

	cout << endl << "Desstructor arr" << endl;
}
//metoda de stergere 
void ObArray::RemoveAll() {
	cout << "S-a ales sa se stearga tot vectorul" << endl;
	for (int i = 0; i < this->size; i++) {
		//Se dezaloca memoria pentru fiecare instanta

		delete  this->p[i];
	}
	// si apoi se dezaloca memoria si pt vectorul de obiecte p.
	delete[] p;
	//se actualizeaza campurile
	this->dimens = 0;
	this->size = 0;

}
//getter pentru size
int ObArray::getSize() {
	return this->size;
}
//metoda de adaugare(un obiect nou la array-ul de obiecte)
int ObArray::add(Object* x) {

//daca dimensiunea este 0(adica vectorul este gol fie dintr-o stergere a acestuia ,fie din
	//initializarea lui dimens cu 0

	if (this->dimens == 0)
	{
		try {
			//se incearca alocare de memorie pt vectorul de obiecte
			this->p = new Object * [1];
		}
		catch (std::bad_alloc & alloc_issue)
		{//am folosit bloc try-catch pt eventualele erori de alocare
			std::cerr << alloc_issue.what() << endl;
		}
	}

	
	//daca dimensiunea=size-ul ,inseamna ca vectorul are toate pozitiile alocate pline si
	//va trebui redimensionat cu grows(unitate de incrementare)
	if (this->dimens == this->size) {
		//cout << "inainte de adaugare" << endl;
		//incrementez dimens cu grows
		this->dimens = this->dimens + this->grows;
		//apelez metoda de redimensionare
		this->redimensionare_array(this->dimens);
		//cout << "Deasupra x";
	}

	//pun noul obiect pe pozitia noua din vectorul de obiecte
	this->p[this->size] = x;
	//size-ul array-ului creste cu o unitate
	this->size = this->size + 1;
	return this->size;

}

//metoda de redidimensionare a array-ului
void ObArray::redimensionare_array(int dimensiune) {


	//am folost un bloc try-catch pt eventualele erori ce pot aparea la alocare
	//creez un vector nou de pointeri de dimensiunea primita parametru
	try {
		Object** obj = new Object * [dimensiune];
		//se copiaza toata zona de memorie ocupata de vectorul p ce contine obiectele in noul vector creat.

		memcpy(obj, this->p, this->size * sizeof(Object*));
		//se sterge memoria initiala
		delete[] this->p;
		this->p = obj;
	}
	catch (std::bad_alloc & alloc_issue)
	{
		std::cerr << alloc_issue.what() << endl;
	}
}
//metoda de afisare
void ObArray::display() {
	//daca dimensiunea vectorului in prezent este0 , inseamna ca vectorul este gol si nu are elemente
	if(this->size==0)
	{
		cout << endl << "Nu exista elemente in vector!" << endl;
		return;
	}
	
	//cout << i + 1 << '\t' << this->dimens << '\t' << this->size << '\t' << this->grows << endl;

	//afisare folosind mostenirea din clasa Object (folosind metoda abstracta display din clasa Object)
	//for (int i = 0; i < size; i++) {

	//	this->p[i]->display();
	//	cout << endl;
	//}

	//Afisare folosind dynamic cast si overload pe functia cout
	for(int i=0;i<size;i++)
	{
		cout << endl;
		//verific daca vectorul meu de pointeri este de tip punct sau de tip NrComplexe
		//si in functie de asta fac dynamic_cast pt cout<<(suprascris in fiecare clasa
		//derivata in parte)
		if(typeid(*p[i])==typeid(Punct))
		{
			cout << *dynamic_cast<Punct*>(p[i]);
		}else
		{
			cout << *dynamic_cast<NrComplexe*>(p[i]);
		}
	}
	
}

void ObArray::shift_left(int poz) {
	//se shifteaza la stanga pointerii din vectorul de obiecte,pornind de la pozitia primita ca parametru pana la final

	for (int i = poz; i < this->size - 1; i++) {
		this->p[i] = this->p[i + 1];
	}
}
void ObArray::shift_right(int poz) {
	//se shifteaza la dreapta pointerii din vectorul de obiecte,pornind de la pozitia primita ca parametru pana la final

	for (int i = this->size; i > poz; i--) {
		this->p[i] = this->p[i-1];
	}
}
//metoda de inserare pe o anumita pozitie
///variabila i este pozitia normala din vector cu indecsi de la 1 (nu pozitia memorata = indecsi de la 0)
int ObArray::insertAt(int i, Object* ob) {
	if (i < 1) {
		//daca se introduce un argument <1,atunci se doreste inserarea pe o pozitie inexistenta->invalid
		throw invalid_argument("Argument invalid");
	}
	if (size < i) {
		//daca se insereaza o pozitie>size,inseamna ca se doreste inserarea pe o pozitie libera,dar pana la respectiva
		//pozitie ar mai fi pozitii libere.Pentru a se evita inconsistentele,in situatia aceasta am inserat pe urmatoarea
		////pozitie libera.
		cout << endl << "Ati introdus o pozitie > size-ul actual.Pentru a se evita inconsistentele,in situatia aceasta am inserat pe urmatoarea pozitie libera." << endl;
		add(ob);
	}
	else
	{//daca dimens=0,aceeasi situatie ca in metoda add,trebuie sa aloc memorie pt vectorul de pointeri
		//object
		if (this->dimens == 0)
		{
			try {
				this->p = new Object * [1];
			}
			//am folosit bloc try-catch pt eventualele erori de alocare
			catch (std::bad_alloc& alloc_issue)
			{
				std::cerr << alloc_issue.what() << endl;
			}
		}

		//daca size=dimens inseamna ca nu mai e memorie alocata pt vector (acesta avand toate pozitiile ocupate,deci
		//trebuie redimensionat cu grows)
		if (this->size == this->dimens) {
			this->dimens = this->dimens + this->grows;
			//apelez metoda de redimensionare
			redimensionare_array(this->dimens);

		}
		//shiftez tot vectorul la dreapta
		shift_right(i-1);
		this->p[i - 1] = ob;
		//ii cresc size-ul
		this->size = this->size + 1;
	}
}
//metoda de stergere de pe o pozitie
int ObArray::removeAt(int i) {
	//la fel ca in  metoda de mai sus ,am facut verificarile de rigoare.
	if (i < 1) {
		//inainte de pozitia 1 vectorul nu exista,deci nu am ce sterge.arg este clar invalid
		throw invalid_argument("Argument invalid");
	}
	//daca se da o pozitie > size-ul ,aceea este o pozitie considerata default goala pentru ca vectorul
	//nu are elemente pe pozitiile respective(fie ele alocate sau nu)
	if(i>this->size)
	{
		cout << "Pozitia selectata pentru stergere este mai mare decat numarul elementelor memorate in vector!" << endl;
		return -1;
	}
	
	//am sters elementul si am shiftat tot array-ul la stanga
	delete p[i - 1];
	shift_left(i - 1);
	//am micsocat size-ul array-ului
	this->size = this->size - 1;
	//in cazul in care dimens(adica dimensiunea alocata vectorului) este mai mare decat size-ul(adica nr de elemente
	//in momentul actual) si din meniu s-a ales sa se stearga un obiect,am considerat eficient sa compacted vectorul
	////si sa elimin orice memorie in plus alocata array-ului.Altfel spus,odata aleasa optiunea de stergere,
	///dimensiunea alocata pt array va deveni egala cu nr elementelor in acest moment.
	this->dimens = this->size;
	this->redimensionare_array(this->dimens);
	
	return i;
}

Object* ObArray::getAt(int i) {
	//verificarile ca mai sus
	if (i < 1) {
		throw invalid_argument("Argument invalid");
	}

	if (i > this->size)
	{
		cout << "Pozitia selectata este mai mare decat numarul elementelor memorate in vector!" << endl;
		return NULL;
	}
	//returnez elementul de pe pozitia i-1 din vectorul de obiecte
	return this->p[i-1];
}

void ObArray::citire() {
//	cout << "S-au generat" << endl;
	//Am  facut toata citirea intr-un  while infinit pt a folosi blocuri try-catch pt fiecare camp in parte
	//verificand eligibilitatea acestora.
	while (1)
	{
		try {
			cout << endl << "Dimensiunea alocata in acest moment vectorului este: ";
			cin >> dimens;
			//varianta de mai jos este cea in care campurile sunt randomizate nu citite de la tastatura
		/*	std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 15);
			dimens = distribution(generator);
			cout << "dimens= " << this->dimens;*/

			if (cin.fail())
				//dupa ce cin-ul da fail,trebuie neaparat dat clear
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//dau throw erorii aparute
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}

			if ((dimens < 1)) {
				throw invalid_argument("Dimensiunea nu poate fi mai mica decat 1 si trebuie sa fie reprezentata de un numar INTREG. Va rugam sa reintroduceti datele.\n");
			}

			break;

		}//catch pt erorile de sus
		catch (const std::invalid_argument & arg) {
			cout << arg.what();
		}
	}
	//dupa ce s-a citit(intr-un bun final) un camp dimens valid , aloc memorie pt vectorul de pointeri
	this->p = new Object * [this->dimens];


	//pt fiecare camp am un while infinit care functioneaza pe aceleasi explicatii ca cele de mai sus
	while (1) {
		try {
			cout << endl << "Nr de elemente initial este: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> size;
			//varianta de mai jos este cea in care campurile sunt randomizate nu citite de la tastatura
			/*std::default_random_engine generator1;
			std::uniform_int_distribution<int> distribution1(1, this->dimens);
			size = distribution1(generator1);
			cout << "size= " << this->size;*/

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}

			if ((size < 0) || (size > this->dimens)) {
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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> grows;
			/*std::default_random_engine generator2;
			std::uniform_int_distribution<int> distribution2(1, 5);
			grows = distribution2(generator2);
			cout << "grows= " << this->grows;*/
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Valoarea introduse nu este un numar INTREG.\n");
			}

			if ((grows < 1)) {
				throw invalid_argument("Incrementul de crestere nu poate fi mai mic decat 1 sau mai mare decat dimensiunea vectorului si trebuie sa fie reprezentat de un numar INTREG. Va rugam sa reintroduceti datele.\n");

				//cin.clear();
			}


			break;
		}
		catch (const std::invalid_argument & arg) {
			cout << arg.what();
		}
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	this->insert_initial_elements();
}

//metoda de citire a elementelor initiale(pt cazul in care se introduce un size>0,adica nu se pleaca de la vectorul gol)
void ObArray::insert_initial_elements()
{
	for(int i=0;i<this->size;i++)
	{//se apeleaza pt fiecare pozitie ocupata metoda de creeaza obiect.
		this->p[i] = this->creeaza_obiect();
	}
}


/**/
Object* ObArray::creeaza_obiect()
{
	//userul are posibilitatea de a alege tipul obiectului introdus la fiecare pas
	//fie el nr complex sau punct de forma( x,y)
	int ch;
	Object* ob;
	while (1) {
		//intr-un while infinit verific validitatea optiunii introduse folosind bloc try-catch
		try {
			cout << endl << "Nr complexe-1" << endl;
			cout << "Puncte-2" << endl;
			cin >> ch;
			/*std::default_random_engine generator_optiune;
			std::uniform_int_distribution<int>distribution(1, 2);
			ch = distribution(generator_optiune);*/
			if ((ch != 1) && (ch != 2)) {
				throw invalid_argument("Ati introdus o optiune invalida.Reintroduceti.");


			}
			//in functie de optiunea aleasa(neaparat valida)
			//aloc memorie pt un obiect de felul respectiv si citesc cu cin(operator supraincarcat in
			////ambele clase derivate) ,dar facand dynamic_cast pt clasa respectiva.
			if (ch == 1)
			{
				ob = new NrComplexe();
				cin >> *dynamic_cast<NrComplexe*>(ob);

			}
			else
			{
				ob = new Punct();
				cin >> *dynamic_cast<Punct*>(ob);
			}
			
			break;
		}
		//catch pt eventualele probleme.
		catch (const std::invalid_argument & arg) {
			cout << endl << arg.what();
		}

	}
	//returnez obiectul creat
	return ob;
}

//incercari de supraincarcare pt diferiti operatori

ObArray operator+(Object& ob, ObArray& arr)
{
	arr.add(&ob);
	return arr;
}
ObArray ObArray::operator++()
{
	this->dimens = this->dimens + 1;
	this->redimensionare_array(this->dimens);
	return *this;
}

ObArray ObArray::operator++(int i)
{
	this->dimens = this->dimens + i;
	this->redimensionare_array(this->dimens);
	return *this;
}

ObArray ObArray::operator--()
{
	
	this->dimens = this->dimens - 1;
	return *this;
}

ObArray ObArray::operator--(int i)
{
	
	this->dimens = this->dimens - i;
	return *this;
}


bool ObArray::operator!=(ObArray& ob)
{
	if(ob.getSize()==0)
	{
		return false;
	}
	return true;
}
bool ObArray::operator/=(ObArray& ob)
{
	if(ob.getSize()<ob.getdimens())
	{
		return true;
	}
	return false;
}


ObArray ObArray::operator<<=(ObArray& ob)
{
	ob.shift_left(1);
	return ob;
}

ObArray ObArray::operator>>=(ObArray& ob)
{
	ob.shift_right(1);
	return ob;
}

bool ObArray::operator&=(ObArray& ob)
{

	int nr_c = 0;
	int nr_p = 0;
	for(int i=0;i<ob.getSize();i++)
	{
		if (typeid(*p[i]) == typeid(Punct))
		{
			nr_p = nr_p++;
		}
		if (typeid(*p[i]) == typeid(NrComplexe))
		{
			nr_c = nr_c++;
		}
		if(((nr_c==0)&&(nr_p!=0))||(((nr_p == 0) && (nr_c != 0))))
		{
			return true;
		}
		else if((nr_c!=0)&&(nr_p!=0))
		{
			return false;
		}
	}
}


ObArray ObArray::operator^=(ObArray& ob)
{

	ob.RemoveAll();
	return ob;
}

int ObArray::operator|=(ObArray* ob)
{
	if(ob->size==ob->dimens)
	{
		cout << "Nu mai e nicio pozitie libera";
		return 0;
	}
	else
	{
		return this->dimens - this->size;
	}
}

bool ObArray::operator==(ObArray& ob)
{
	if(this->getSize() != ob.getSize())
	{
		return false;
	}

	else
	{
		for(int i=0; i<this->getSize();i++)
		{
			if (this->p[i] != ob.p[i])
				return false;
		}
	}

	return true;
}

ObArray ObArray::operator+(ObArray a)
{
	ObArray b;
	b.size = a.size + 1;
	return b;
	
}

/*
ObArray& ObArray::operator=(const ObArray& ob)
{
	if(this!=&ob)
	{
		p = new int[2];
		p[0] = ob.p[0];
		p[1] = ob.p[1];
	}
	return *this;
}
*/
/*
ObArray::ObArray(const ObArray& ob)
{
	p = new int[2];
	p[0] = ob.p[0];
	p[1] = ob.p[1];
}
*/
// transmiterea parametrilor catre constructorul din clasa de baza
/*
ObArray::ObArray(const ObArray& ob):Object(ob)
{//apel explicit constructor copiere din baza :B(ob)
	p = new int[2];
	p[0] = ob.p[0];
	p[1] = ob.p[1];
}*/


ObArray ObArray::functie_cu_temp()
{
	ObArray temp(*this);
	return temp;
}

ObArray ObArray::funtie_cu_ref()
{
	return *this;
}

ObArray ObArray::functie_cu_temp_cu_ref()
{
	ObArray temp(*this);
	return temp;
}

void ObArray::f(string c)
{
	cout << "functia f din baza cu paramtrul string= " << c << endl;
}
