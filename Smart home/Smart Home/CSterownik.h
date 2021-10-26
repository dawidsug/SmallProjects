#pragma once
#include <iostream>
#include <locale.h>
#include <string>
#include "CMiernik.h"
#include "CSystemWentylacyjny.h"
#include "CZraszacz.h"
#include "CGrzejnik.h"
using namespace std;

class CSterownik
{
public:
	CSterownik();
	~CSterownik();
	CMiernik *Mier;
	CSystemWentylacyjny *Wen;
	CZraszacz *Zra;
	CGrzejnik *Grze;
	void zalaczanieSystemu();
	void zalaczanieSystemu2();
	void zalaczenieSystemu3();
	void zalaczanieZraszacza();
	void aktualnaTemperatura();
	void aktualnaWilgotnosc();
	void aktualnaWilgotnoscLazienka();
	void aktualnyGaz();
	void podajTempZad();
	void podajWilZad();
	void podajWilLaz();
	void podajGazZad();
	void zmienTempZad();
	void zmienWilZad();
	void zmienGazZad();
	void zmienWilLazZad();
	void odczytTemp(const string sciezka);
private:
	float TempZad;
	float WilZad;
	float GazZad;
	float WilLazZad;
	char tab[100];
	fstream plik;
	bool zapis;
	int tmp;
};

