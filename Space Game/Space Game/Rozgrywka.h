#pragma once
#include "Statek.h"
#include "Obraz.h"
#include "Meteoryt.h"
#include "MeteorytRomb.h"
#include "MeteorytO1.h"
#include "MeteorytO2.h"
#include <locale.h>
#include <conio.h>
#include <fstream>
#include <stack>
#include <windows.h>
using namespace std;

class Rozgrywka
{
public:
	Rozgrywka();
	~Rozgrywka();
	Statek *Sta;
	Obraz *Obr;
	Meteoryt *Met;
	MeteorytRomb *MetR;
	MeteorytO1 *MetO1;
	MeteorytO2 *MetO2;
	void rozpocznijGre();
	Rozgrywka &operator+=(const int wartosc);
private:
	char znak;
	int pozycja;
	int pozycjaMet;
	int pozycjaMet11;
	int pozycjaMet12;
	int pozycjaMet13;
	int pozycjaMet14;
	int wysokosc;
	int pozycjaMet2;
	int wysokosc2;
	int pozycjaMet3;
	int wysokosc3;
	int licznik;
	int licznik1;
	int licznik2;
	int wartosc;
	int licznikZapis;
	void zapisywanie();
	fstream plik;
	bool zapis;
	stack<char> wykonywaneRuchy;
	void statystyki();
	int ilosc;
	int lewo;
	int prawo;
	char odczytana;
};

