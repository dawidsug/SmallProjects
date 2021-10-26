#pragma once
#include "CWirtualnyPokoj.h"
#include "CSterownik.h"
#include "COgrodek.h"
#include "CKuchnia.h"
#include "CLazienka.h"
#include "CPokoje.h"
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
using namespace std;

template <class Typ>
class CScheduler
{
public:
	CScheduler();
	~CScheduler();
	const int operator++(int);
	CSterownik *sterownik;
	COgrodek *Ogr;
	CKuchnia *Kuch;
	CLazienka *Laz;
	CPokoje *Pok;
	void run();
	Typ znak;
private:
	int wartosc;

};


template <class Typ>
CScheduler<Typ>::CScheduler()
{
	znak = 0;
	wartosc = 0;
}

template <class Typ>
CScheduler<Typ>::~CScheduler()
{
}

template <class Typ>
const int CScheduler<Typ>::operator++(int wartosc)
{
	wartosc = wartosc + 1.0;
	return wartosc;
}

template <class Typ>
void CScheduler<Typ> ::run()
{
	sterownik->zalaczanieSystemu();
	Pok->update();
	if (znak == 53)
	{
		sterownik->zalaczanieZraszacza();
		Ogr->update2();
	}
	else
	{
		sterownik->zalaczanieZraszacza();
		Ogr->update();
	}
	sterownik->zalaczanieSystemu2();
	Kuch->update();
	sterownik->zalaczenieSystemu3();
	Laz->update();
}
