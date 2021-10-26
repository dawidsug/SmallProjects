#pragma once
#include "Obraz.h"
class Statek
{
public:
	Statek();
	~Statek();
	Obraz *Obr;
	int ruch(const char,const int);
private:
	char znak;
	int pozycja;
};

