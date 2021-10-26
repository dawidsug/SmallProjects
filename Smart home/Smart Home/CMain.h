#pragma once
#include "CScheduler.h"
#include "CMiernik.h"
#include "CWirtualnyPokoj.h"
#include "CSterownik.h"
#include "CSystemWentylacyjny.h"
#include "CZraszacz.h"
#include "COgrodek.h"
#include "CGrzejnik.h"
#include "CPokoje.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <windows.h>
using namespace std;


template <class Typ, class Typ1>
class CMain
{
public:
	CMain();
	~CMain();
	CSterownik *Ster;
	CMiernik *Mier;
	CScheduler<char> *Szed;
	CWirtualnyPokoj *CWP;
	CSystemWentylacyjny *Wen;
	CZraszacz *Zra;
	COgrodek *Ogr;
	CKuchnia *Kuch;
	CGrzejnik *Grze;
	CPokoje *Pok;
	Typ stronaGlowna();
	Typ wstep();
	Typ petlaGlowna();
	Typ1 znak;
	int licznik;
};

template <class Typ, class Typ1>
CMain<Typ, Typ1>::CMain()
{
	znak = 0;
	licznik = 0;
}

template <class Typ, class Typ1>
CMain<Typ, Typ1>::~CMain()
{
}

template <class Typ, class Typ1>
Typ CMain<Typ, Typ1>::petlaGlowna()
{
	wstep();

	for (;;)
	{
		Szed->run();

		if (znak != 52)
			stronaGlowna();

		licznik = Szed->operator++(licznik);
		cout << "Timer: " << licznik << endl;

		if (kbhit())
		{
			znak = getch();
		}
		if (znak == 48)
		{
			system("cls");
			cout << "Koniec programu\nWcisnij enter." << endl;
			exit(0);
		}
		if (znak == 49)
		{
			system("cls");
			Ster->zmienTempZad();
		}
		if (znak == 50)
		{
			system("cls");
			Ster->zmienWilZad();
		}
		if (znak == 51)
		{
			system("cls");
			Ster->zmienWilLazZad();
		}
		if (znak == 52)
		{
			system("cls");
			Ster->zmienGazZad();
		}
		if (znak == 53)
		{
			Szed->znak = 53;
			znak = 53;
		}
		if (znak == 54)
		{
			Szed->znak = 0;
			znak = 0;
		}
		if (znak == 55)
		{
			system("cls");
			Ster->odczytTemp("C:\\Users\\Student237530\\Desktop\\wczytywanie.txt");
		}
		Sleep(500);
	}
}

template <class Typ, class Typ1>
Typ CMain<Typ, Typ1>::wstep()
{
	cout << "\tWITAJ! \nSYSTEM STEROWANIA TWOIM DOMEM\n" << endl;
	Sleep(3000);
	system("cls");
	cout << "Ustawienia wstepne" << endl;
	Mier->PodajTemp();
	system("cls");
	cout << "Ustawienia wstepne" << endl;
	Mier->PodajWilOgr();
	system("cls");
	cout << "Ustawienia wstepne" << endl;
	Mier->PodajGaz();
	system("cls");
	cout << "Ustawienia wstepne" << endl;
	Mier->PodajWilLaz();
	system("cls");
}

template <class Typ, class Typ1>
Typ CMain<Typ, Typ1>::stronaGlowna()
{
	system("cls");
	cout << "\t\tMENU" << endl;
	cout << "1. Zmien temperature w mieszkaniu." << endl;
	cout << "2. Zmien wilgotnosc ogrodka." << endl;
	cout << "3. Zmien wilgotnosc lazienki." << endl;
	cout << "4. Zmien dopuszczalny poziom gazu w kuchni." << endl;
	cout << "5. Symuluj deszcz." << endl;
	cout << "6. Wylacz deszcz." << endl;
	cout << "7. Wczytaj z pliku." << endl;
	Ster->podajTempZad();
	Ster->podajWilZad();
	Ster->podajGazZad();
	Ster->podajWilLaz();
	Ster->aktualnaTemperatura();
	if (Grze->MyStan == 1)
	{
		cout << "WLACZONY GRZEJNIK" << endl;
	}
	else
	{
		cout << "WYLACZONY GRZEJNIK" << endl;
	}
	Ster->aktualnaWilgotnosc();
	if (znak == 53)
	{
		cout << "PADA DESZCZ" << endl;
	}
	else
	{
		if (Zra->MyStan == 1)
		{
			cout << "WLACZONY ZRASZACZ" << endl;
		}
		else
		{
			cout << "WYLACZONY ZRASZACZ" << endl;
		}
	}
	Ster->aktualnyGaz();
	if (Wen->MyStan == 1)
	{
		cout << "WLACZONY WENTYLATOR W KUCHNI" << endl;
	}
	else
	{
		cout << "WYLACZONY WENTYLATOR W KUCHNI" << endl;
	}
	Ster->aktualnaWilgotnoscLazienka();
	if (Wen->MyStan2 == 1)
	{
		cout << "WLACZONY WENTYLATOR W LAZIENCE" << endl;
	}
	else
	{
		cout << "WYLACZONY WENTYLATOR W LAZIENCE" << endl;
	}

	cout << "\n0. Wyjdz z programu." << endl;
}