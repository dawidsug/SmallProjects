#pragma once
#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Obraz
{
public:
	Obraz();
	~Obraz();
	char ekran[50][20];
	void tworzenieEkranu();
	void menu();
	void wyswietlEkran();
	void koniec();
	void czyscEkran();
	void czyscElement(const int,const int);
	void przegrana();
	void wczytywanieNajWyn();
	void sterowanie();
private:
	int i;
	int j;
	ifstream plik1;
	string linia;
	istringstream StringStream;
	int wartosc;
	int wartosc1;
	string znak;
	int licznik;
};

