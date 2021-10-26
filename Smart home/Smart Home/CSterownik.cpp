#include "CSterownik.h"
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#pragma once

CSterownik::CSterownik()
{
	TempZad = 20;
	WilZad = 50;
	GazZad = 4;
	WilLazZad = 8;
	try
	{
		zapis = true;
		plik.open("C:\\Users\\Student237530\\Desktop\\log_systemwentylacja.txt", ios::app);
	}
	catch (...)
	{
		zapis = false;
	}
}


CSterownik::~CSterownik()
{
	if (plik.is_open())
		plik.close();
}

void CSterownik::zalaczanieSystemu()
{
	if (Mier->MyTemp < TempZad)
	{
		Grze->MyStan = 1;
	}
	else Grze->MyStan = 0;
}

void CSterownik::zalaczanieSystemu2()
{
	if (Mier->MyGaz > GazZad)
	{
		Wen->MyStan = 1;
	}
	else Wen->MyStan = 0;
}

void CSterownik::zalaczenieSystemu3()
{
	if (Mier->MyWilLaz > WilLazZad)
	{
		Wen->MyStan2 = 1;
	}
	else Wen->MyStan2 = 0;
}

void CSterownik::zalaczanieZraszacza()
{
	if (Mier->MyWil < WilZad)
	{
		Zra->MyStan = 1;
	}
	else Zra->MyStan = 0;
}

void CSterownik::aktualnaTemperatura()
{
	cout << "\nAktualna temperatura" << endl;
	cout << Mier->MyTemp << endl;
	if (zapis)
		plik << "Aktualna temperatura " << Mier->MyTemp << endl;
}

void CSterownik::aktualnyGaz()
{
	cout << "\nAktualny poziom gazu" << endl;
	cout << Mier->MyGaz << endl;
	if (zapis)
		plik << "Aktualny poziom gazu " << Mier->MyGaz << endl;
}

void CSterownik::aktualnaWilgotnosc()
{
	cout << "\nAktualna wilgotnosc w ogrodku" << endl;
	cout << Mier->MyWil << endl;
	if (zapis)
		plik << "Aktualna wilgotnosc w ogrodku " << Mier->MyWil << endl;
}

void CSterownik::aktualnaWilgotnoscLazienka()
{
	cout << "\nAktualna wilgotnosc w lazience" << endl;
	cout << Mier->MyWilLaz << endl;
	if (zapis)
		plik << "Aktualna wilgotnosc w lazience " << Mier->MyWilLaz << endl;
}

void CSterownik::podajTempZad()
{
	cout << "Nastawa temperatury:" << endl;
	cout << TempZad << endl;
}

void CSterownik::podajWilZad()
{
	cout << "Nastawa wilgotnosci - ogrod:" << endl;
	cout << WilZad << endl;
}

void CSterownik::podajWilLaz()
{
	cout << "Nastawa wilgotnosci - lazienka:" << endl;
	cout << WilLazZad << endl;
}

void CSterownik::podajGazZad()
{
	cout << "Nastawa gazu:" << endl;
	cout << GazZad << endl;
}

void CSterownik::zmienTempZad()
{
	cout << "Podaj oczekiwana temperature mieszkania" << endl;
	tmp = TempZad;
	try {
		cin >> TempZad;
		if (TempZad < 0 || TempZad > 100) throw "To nie jest wlasciwa liczba, zakres od 0 do 100!";
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		TempZad = tmp;
		system("pause");
	}
	catch (...)
	{
		TempZad = tmp;
		cout << "Wystapil inny blad\n" << endl;
	}
	cout << "Wcisnij enter." << endl;
}

void CSterownik::zmienWilZad()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj oczekiwana wilgotnosc ogrodka" << endl;
	tmp = WilZad;
	try {
		cin >> WilZad;
		if (WilZad < 0 || WilZad > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		WilZad = tmp;
		system("pause");
	}
	catch (...)
	{
		WilZad = tmp;
		cout << "Wystapil inny blad\n" << endl;
	}
	cout << "Wcisnij enter." << endl;
}

void CSterownik::zmienWilLazZad()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj oczekiwana wilgotnosc lazienki" << endl;
	tmp = WilLazZad;
	try {
		cin >> WilLazZad;
		if (WilLazZad < 0 || WilLazZad > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		WilLazZad = tmp;
		system("pause");
	}
	catch (...)
	{
		WilLazZad = tmp;
		cout << "Wystapil inny blad\n" << endl;
	}
	cout << "Wcisnij enter." << endl;
}

void CSterownik::zmienGazZad()
{
	string error = "To nie jest wlasciwa liczba, zakres od 0 do 100!";
	cout << "Podaj oczekiwane stezenie gazu w kuchni" << endl;
	tmp = GazZad;
	try {
		cin >> GazZad;
		if (GazZad < 0 || GazZad > 100) throw error;
		if (cin.fail()) throw 0;
	}
	catch (string info) {
		cout << info << endl;
		GazZad = tmp;
		system("pause");
	}
	catch (...)
	{
		GazZad = tmp;
		cout << "Wystapil inny blad\n" << endl;
		throw;
	}
	cout << "Wcisnij enter." << endl;
}

void CSterownik::odczytTemp(const string sciezka)
{
	system("cls");

	ifstream plik;
	string linia;
	istringstream StringStream;
	int wartosc;
	string znak;

	plik.open(sciezka);

	if (plik.is_open()) {
		cout << "Otwarto pomyslnie" << endl;
		
		for (int i = 0; i < 4; i++) {
			getline(plik, linia);
			StringStream.str(linia);
			while (true) {
				StringStream >> wartosc;
				if (StringStream.fail()) {
					StringStream.clear();
					StringStream >> znak;
				}
				else break;
			}
			if (i == 0) TempZad = wartosc;
			else if (i == 1) WilZad = wartosc;
			else if (i == 2) GazZad = wartosc;
			else WilLazZad = wartosc;
		}
		cout << "Wcisnij enter." << endl;
	}
	else {
		cout << "Nie znaleziono pliku" << endl;
		cout << "Wcisnij enter." << endl;
		cin.get();
	}
}