#include "Rozgrywka.h"



Rozgrywka::Rozgrywka()
{
	pozycja = 25;
	wysokosc = 1;
	wysokosc2 = 1;
	wysokosc3 = 1;
	pozycjaMet = NULL;
	pozycjaMet11 = NULL;
	pozycjaMet12 = NULL;
	pozycjaMet13 = NULL;
	pozycjaMet14 = NULL;
	pozycjaMet2 = NULL;
	pozycjaMet3 = NULL;
	licznik = 48;
	licznik1 = 48;
	licznik2 = 48;
	licznikZapis = 0;
	lewo = 0;
	prawo = 0;
}


Rozgrywka::~Rozgrywka()
{
	if (plik.is_open())
		plik.close();
}


void Rozgrywka::rozpocznijGre()
{
	Obr->sterowanie();
	Obr->czyscEkran();
	Obr->tworzenieEkranu();
	Obr->ekran[pozycja][18] = 84;
	Obr->wyswietlEkran();

	for (;;)
	{
		system("cls");
		if (kbhit())
		{
			znak = getch();
		}
		if (znak == 52 || znak == 54)
		{
			Obr->czyscElement(pozycja, 18);
			pozycja = Sta->ruch(znak, pozycja);
			wykonywaneRuchy.push(znak);
			znak = 0;
		}
		if (wysokosc == 18 && pozycjaMet - 1 == pozycja || wysokosc == 18 && pozycjaMet + 1 == pozycja || wysokosc + 1 == 18 && pozycjaMet == pozycja || wysokosc2 == 18 && pozycjaMet2 == pozycja || wysokosc3 == 18 && pozycjaMet3 == pozycja)
		{
			Obr->czyscEkran();
			Obr->przegrana();
			Obr->wyswietlEkran();
			zapisywanie();
			statystyki();
			Sleep(1000);
			exit(0);
		}
		else
		{
			if (wysokosc + 1 == 18)
				Obr->czyscElement(pozycjaMet14, 18);
			if (wysokosc == 18)
			{
				Obr->czyscElement(pozycjaMet, wysokosc);
				Obr->czyscElement(pozycjaMet11, wysokosc);
				Obr->czyscElement(pozycjaMet12, wysokosc);
			}
			if (wysokosc - 1 == 18)
			{
				Obr->czyscElement(pozycjaMet13, 18);
				wysokosc = 2;
				pozycjaMet = NULL;
			}
			if (wysokosc2 >= 18)
			{
				Obr->czyscElement(pozycjaMet2, wysokosc2);
				wysokosc2 = 2;
				pozycjaMet2 = NULL;
			}
			if (wysokosc3 >= 18)
			{
				Obr->czyscElement(pozycjaMet3, wysokosc3);
				wysokosc3 = 2;
				pozycjaMet3 = NULL;
			}

			if (pozycjaMet == NULL)
			{
				pozycjaMet = Met->losowanie();
				pozycjaMet11 = pozycjaMet + 1;
				pozycjaMet12 = pozycjaMet - 1;
				pozycjaMet13 = pozycjaMet;
				pozycjaMet14 = pozycjaMet;

			}
			if (pozycjaMet2 == NULL)
			{
				pozycjaMet2 = Met->losowanie();
			}
			if (pozycjaMet3 == NULL)
			{
				pozycjaMet3 = Met->losowanie();
			}


				Obr->czyscElement(pozycjaMet, wysokosc);
				Obr->czyscElement(pozycjaMet11, wysokosc);
				Obr->czyscElement(pozycjaMet12, wysokosc);
				Obr->czyscElement(pozycjaMet13, wysokosc - 1);
				if (wysokosc + 1 < 18)
				Obr->czyscElement(pozycjaMet14, wysokosc + 1);
				wysokosc = MetR->lot(wysokosc);
				Obr->czyscElement(pozycjaMet2, wysokosc2);
				wysokosc2 = MetO1->lot(wysokosc2);
				Obr->czyscElement(pozycjaMet3, wysokosc3);
				wysokosc3 = MetO2->lot(wysokosc3);
				if (wysokosc < 18)
				{
					Obr->ekran[pozycjaMet][wysokosc] = 79;
					Obr->ekran[pozycjaMet11][wysokosc] = 79;
					Obr->ekran[pozycjaMet12][wysokosc] = 79;
				}
				Obr->ekran[pozycjaMet13][wysokosc - 1] = 79;
				if(wysokosc + 1 < 18)
				Obr->ekran[pozycjaMet14][wysokosc + 1] = 79;
				Obr->ekran[pozycjaMet2][wysokosc2] = 79;
				Obr->ekran[pozycjaMet3][wysokosc3] = 79;
				Obr->ekran[48][1] = licznik;
				Obr->wyswietlEkran();
				licznik += 1;
				if (licznik == 58)
				{
					licznik = 48;
					licznik1 += 1;
					if (licznik1 == 58)
					{
						licznik1 = 48;
						licznik2 += 1;
						Obr->ekran[46][1] = licznik2;
					}
					Obr->ekran[47][1] = licznik1;
				}
				licznikZapis += 1;
		}
		Sleep(200);
	}
}

Rozgrywka &Rozgrywka::operator+=(int wartosc)
{
	licznik + wartosc;
	return (*this);
}

void Rozgrywka::zapisywanie()
{
	try
	{
		zapis = true;
		plik.open("Wyniki.txt", ios::app);
	}
	catch (...)
	{
		zapis = false;
	}
	if (zapis)
		plik << "Czas rozgrywki " << licznikZapis << endl;
}

void Rozgrywka::statystyki()
{
	ilosc = wykonywaneRuchy.size();
	for (int i = 0; i < ilosc; i++)
	{
		odczytana = wykonywaneRuchy.top();
		wykonywaneRuchy.pop();
		if (odczytana == 52)
			lewo = lewo + 1;
		if (odczytana == 54)
			prawo = prawo + 1;
	}
	cout << "Liczba krokow w lewo " << lewo << endl;
	cout << "Liczba krokow w prawo " << prawo << endl;
}