#include "Statek.h"



Statek::Statek()
{
}


Statek::~Statek()
{
}


int Statek::ruch(char znak, int pozycja)
{
	if (znak == 52) {
		Obr->ekran[pozycja][18] = 32;
		Obr->ekran[pozycja - 1][18] = 84;
		pozycja = pozycja - 1;
	}

	if (znak == 54)
	{
		Obr->ekran[pozycja][18] = 32;
		Obr->ekran[pozycja + 1][18] = 84;
		pozycja = pozycja + 1;
	}
	return pozycja;
}