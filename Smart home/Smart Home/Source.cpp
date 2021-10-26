#pragma once
#include <iostream>
#include <locale.h>
#include "CScheduler.h"
#include "CMiernik.h"
#include "CWirtualnyPokoj.h"
#include "CSterownik.h"
#include "CSystemWentylacyjny.h"
#include "CZraszacz.h"
#include "COgrodek.h"
#include "CLazienka.h"
#include "CGrzejnik.h"
#include "CMain.h"
#include "CPokoje.h"
#include <windows.h>
#include <conio.h>
using namespace std;

int main()
{
	CSterownik Ster;
	CMiernik Mier;
	CScheduler<char> Szed;
	CWirtualnyPokoj CWP;
	CSystemWentylacyjny Wen;
	CZraszacz Zra;
	COgrodek Ogr;
	CKuchnia Kuch;
	CMain<void, char> main;
	CLazienka Laz;
	CGrzejnik Grze;
	CPokoje Pok;

	Szed.sterownik = &Ster;
	Szed.Pok = &Pok;
	Szed.Ogr = &Ogr;
	Szed.Kuch = &Kuch;
	Szed.Laz = &Laz;
	CWP.Grze = &Grze;
	CWP.Wen = &Wen;
	CWP.Zra = &Zra;
	CWP.Mier = &Mier;
	Ogr.Zra = &Zra;
	Ogr.Mier = &Mier;
	Kuch.Wen = &Wen;
	Kuch.Mier = &Mier;
	Ster.Wen = &Wen;
	Ster.Zra = &Zra;
	Ster.Mier = &Mier;
	Ster.Grze = &Grze;
	main.Wen = &Wen;
	main.Zra = &Zra;
	main.Mier = &Mier;
	main.Ster = &Ster;
	main.Szed = &Szed;
	main.CWP = &CWP;
	main.Kuch = &Kuch;
	main.Ogr = &Ogr;
	main.Grze = &Grze;
	main.Pok = &Pok;
	Laz.Mier = &Mier;
	Laz.Wen = &Wen;
	Pok.Mier = &Mier;
	Pok.Grze = &Grze;

	main.petlaGlowna();

	return 0;
}
