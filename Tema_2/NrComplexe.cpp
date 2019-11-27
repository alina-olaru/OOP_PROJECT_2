#include "NrComplexe.h"
#include <random>

NrComplexe::NrComplexe(int real, int imaginar) {
	//consructor parametrizat
	this->real = real;
	this->imaginar = imaginar;
}

void NrComplexe::display() {
	cout << this->real << "+" << this->imaginar << "i" << endl;
}
//supraincarcare citire cu cin
istream& operator >>(istream& in,NrComplexe& ob){
	in >> ob.real >> ob.imaginar;
	//varianta in care cele 2 campuri sunt randomizate , nu citite de la tastatura
	/*std::default_random_engine generator_reale;
	std::uniform_int_distribution < int > distributie_reale(1, 1000);
	ob.real = distributie_reale(generator_reale);
	*/

	//varianta in care cele 2 campuri sunt randomizate , nu citite de la tastatura
	/*std::default_random_engine generator_im;
	std::uniform_int_distribution < int > distributie_im(1, 1000);
	ob.imaginar = distributie_reale(generator_reale);*/
	return in;
}
//supraincarcare afisare cu cout
ostream& operator <<(ostream& out , NrComplexe& ob)
{
	out << ob.real << "+" << ob.imaginar << "i" << endl;
	return out;
}

NrComplexe NrComplexe::operator+=(NrComplexe& ob)
{
	ob.real = ob.real + 1;
	ob.imaginar = ob.imaginar + 1;
	return ob;
}