#include "Obraz.h"



Obraz::Obraz()
{
	wartosc = 0;
	wartosc1 = 0;
	licznik = 0;
}


Obraz::~Obraz()
{
}

void Obraz::tworzenieEkranu()
{
	for (j = 0; j < 20; j++)
	{
		for (int i = 0; i < 50; i++)
		{
			ekran[i][j] = 32;
		}
	}

	for (i = 0; i < 50; i++)
	{
		ekran[i][0] = 95;
		ekran[i][19] = 95;
	}

	for (j = 1; j < 19; j++)
	{
		ekran[0][j] = 124;
		ekran[49][j] = 124;
	}
}

void Obraz::menu()
{
	ekran[17][8] = 49;
	ekran[18][8] = 46;
	ekran[19][8] = 82;
	ekran[20][8] = 111;
	ekran[21][8] = 122;
	ekran[22][8] = 112;
	ekran[23][8] = 111;
	ekran[24][8] = 99;
	ekran[25][8] = 122;
	ekran[26][8] = 110;
	ekran[27][8] = 105;
	ekran[28][8] = 106;
	ekran[30][8] = 103;
	ekran[31][8] = 114;
	ekran[32][8] = 101;


	ekran[17][9] = 50;
	ekran[18][9] = 46;
	ekran[19][9] = 87;
	ekran[20][9] = 121;
	ekran[21][9] = 106;
	ekran[22][9] = 100;
	ekran[23][9] = 122;
	ekran[25][9] = 122;
	ekran[27][9] = 103;
	ekran[28][9] = 114;
	ekran[29][9] = 121;

	ekran[17][10] = 51;
	ekran[18][10] = 46;
	ekran[19][10] = 78;
	ekran[20][10] = 97;
	ekran[21][10] = 106;
	ekran[22][10] = 119;
	ekran[23][10] = 121;
	ekran[24][10] = 122;
	ekran[25][10] = 115;
	ekran[26][10] = 122;
	ekran[27][10] = 121;

	ekran[29][10] = 119;
	ekran[30][10] = 121;
	ekran[31][10] = 110;
	ekran[32][10] = 105;
	ekran[33][10] = 107;

}

void Obraz::wyswietlEkran()
{
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 50; i++)
		{
			cout << ekran[i][j];
		}
		cout << "\n" << endl;
	}
}

void Obraz::koniec()
{
	ekran[22][8] = 75;
	ekran[23][8] = 79;
	ekran[24][8] = 78;
	ekran[25][8] = 73;
	ekran[26][8] = 69;
	ekran[27][8] = 67;
}

void Obraz::czyscEkran()
{
	system("cls");

	for (int j = 1; j < 19; j++)
	{
		for (int i = 1; i < 49; i++)
		{
			ekran[i][j] = 32;
		}
	}
}

void Obraz::czyscElement(int x, int y)
{
	ekran[x][y] = 32;
}

void Obraz::przegrana()
{
	ekran[22][8] = 80;
	ekran[23][8] = 82;
	ekran[24][8] = 90;
	ekran[25][8] = 69;
	ekran[26][8] = 71;
	ekran[27][8] = 82;
	ekran[28][8] = 65;
	ekran[29][8] = 78;
	ekran[30][8] = 65;
}

void Obraz::wczytywanieNajWyn()
{
	plik1.open("Wyniki.txt");

	try {
		if (!plik1.is_open()) throw 1;
		

			while (!plik1.eof()) {
				getline(plik1, linia);
				StringStream.str(linia);
				while (true) {
					StringStream >> wartosc;
					if (StringStream.fail()) {
						StringStream.clear();
						StringStream >> znak;
						licznik = licznik + 1;
						if (licznik == 3) {
							break;
						}
					}
					else break;
				}
				licznik = 0;
				if (wartosc >= wartosc1)
					wartosc1 = wartosc;
			}
			cout << "Najwyzszy wynik " << wartosc1 << endl;
			Sleep(1000);
	
	}
	catch (int nr)
	{
		cout << "Blad nr" << nr << endl;
		cout << "Nie znaleziono pliku" << endl;
		Sleep(2000);
	}

	if (plik1.is_open())
		plik1.close();
}

void Obraz::sterowanie()
{
	czyscEkran();
	tworzenieEkranu();

	ekran[17][8] = 83;
	ekran[18][8] = 116;
	ekran[19][8] = 101;
	ekran[20][8] = 114;
	ekran[21][8] = 111;
	ekran[22][8] = 119;
	ekran[23][8] = 97;
	ekran[24][8] = 110;
	ekran[25][8] = 105;
	ekran[26][8] = 101;
	ekran[27][8] = 58;


	ekran[17][9] = 52;
	ekran[19][9] = 76;
	ekran[20][9] = 101;
	ekran[21][9] = 119;
	ekran[22][9] = 111;

	ekran[17][10] = 54;
	ekran[19][10] = 80;
	ekran[20][10] = 114;
	ekran[21][10] = 97;
	ekran[22][10] = 119;
	ekran[23][10] = 111;

	wyswietlEkran();

	Sleep(4000);

}