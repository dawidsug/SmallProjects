#include "Meteoryt.h"



Meteoryt::Meteoryt()
{
	srand(time(NULL));
}


Meteoryt::~Meteoryt()
{
}

int Meteoryt::lot(int wysokosc)
{
	return wysokosc;
}

int Meteoryt::losowanie()
{
	pozycjaMet = (rand() % 42 ) + 4;
	if (pozycjaMet < 2 || pozycjaMet > 48)
		pozycjaMet = 2;
	return pozycjaMet;
}
