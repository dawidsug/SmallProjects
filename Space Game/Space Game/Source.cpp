#include <windows.h>
#include <conio.h>
#include <iostream>
#include "Rozgrywka.h"
#include "Obraz.h"
#include "Statek.h"
#include "Meteoryt.h"
#include "MeteorytRomb.h"
#include "MeteorytO1.h"
#include "MeteorytO2.h"
using namespace std;

int main()
{
	Rozgrywka Roz;
	Obraz Obr;
	Statek Sta;
	Meteoryt Met;
	MeteorytRomb MetR;
	MeteorytO1 MetO1;
	MeteorytO2 MetO2;

	Sta.Obr = &Obr;
	Roz.Obr = &Obr;
	Roz.Sta = &Sta;
	Roz.Met = &Met;
	Roz.MetR = &MetR;
	Roz.MetO1 = &MetO1;
	Roz.MetO2 = &MetO2;

	int wybor = 0;

	Obr.tworzenieEkranu();


	do {
		system("cls");

		Obr.menu();
		Obr.wyswietlEkran();
		cin >> wybor;

		switch (wybor)
		{
		case 1:
			Roz.rozpocznijGre();
			break;
		case 2:

			Obr.czyscEkran();
			Obr.koniec();
			Obr.wyswietlEkran();
			exit(0);
			break;
		case 3:
			Obr.wczytywanieNajWyn();
			break;
		default:
			break;
		}
	} while (wybor != 1);

}