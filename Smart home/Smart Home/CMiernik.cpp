#include "CMiernik.h"
#pragma once
#include <iostream>
#include <locale.h>
#include "CSterownik.h"
#include "CSystemWentylacyjny.h"
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;


CMiernik::CMiernik()
{
	float MyTemp = 0;
	float MyWil = 0;
	float MyGaz = 0;
	float MyWilLaz = 0;
}


CMiernik::~CMiernik()
{
}

void CMiernik::PodajTemp()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj aktualna temperature mieszkania" << endl;
	try {
		cin >> MyTemp;
		if (MyTemp < 0 || MyTemp > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		cout << "Wartosc ustawiona na 0" << endl;
		MyTemp = 0;
		cin.clear();
		Sleep(1500);
	}
}

void CMiernik::PodajWilOgr()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj aktualna wilgotnosc ogrodka" << endl;
	try {
		cin >> MyWil;
		if (MyWil < 0 || MyWil > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		cout << "Wartosc ustawiona na 0" << endl;
		MyWil = 0;
		Sleep(1500);
	}
}

void CMiernik::PodajGaz()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout <<"Podaj aktualny poziom gazu w kuchni" << endl;
	try {
		cin >> MyGaz;
		if (MyGaz < 0 || MyGaz > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		cout << "Wartosc ustawiona na 0" << endl;
		MyGaz = 0;
		Sleep(1500);
	}
}

void CMiernik::PodajWilLaz()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj aktualna wilgotnosc w lazience" << endl;
	try {
		cin >> MyWilLaz;
		if (MyWilLaz < 0 || MyWilLaz > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		cout << "Wartosc ustawiona na 0" << endl;
		MyWilLaz = 0;
		Sleep(1500);
	}
}