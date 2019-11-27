#include "Puncte.h"
#include "Object.h"
#include "ObArray.h"
#include "NrComplexe.h"
#include <random>
//constructor parametrizat
Punct::Punct(int x , int y ) {
	this->x = x;
	this->y = y;
}

//supraincare pt metoda de afisare din clasa Object(base class)
void Punct::display() 
{

	cout << "x= " << this->x << '\t' << "y= " << this->y << '\t' << "(" << this->x << "," << this->y << ")" << endl;
}


//supraincarcare pentru cin
istream& operator >>(istream& in, Punct& ob) {
	in >> ob.x >> ob.y;
	//varianta in care cele 2 campuri sunt randomizate , nu citite de la tastatura
	/*std::default_random_engine generator_x;
	std::uniform_int_distribution < int > distributie_x(1, 1000);
	ob.x = distributie_x(generator_x);*/



	/*std::default_random_engine generator_y;
	std::uniform_int_distribution < int > distributie_y(1, 1000);
	ob.y = distributie_y(generator_y);*/
	return in;

}
//supraincarcare pentru cout
ostream& operator <<(ostream& out, Punct& ob)
{
	out << "x= " << ob.x << '\t' << "y= " <<ob.y << '\t' << "(" <<ob.x << "," <<ob.y<< ")" << endl;
	return out;
}

Punct Punct::operator+=(Punct& ob)
{
	ob.x = ob.x + 1;
	ob.y = ob.y + 1;
	return ob;
}