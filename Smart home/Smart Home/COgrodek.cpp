#include "COgrodek.h"

COgrodek::COgrodek()
{
}


COgrodek::~COgrodek()
{
}

void COgrodek::update()
{
	if (Zra->MyStan == 1)
	{
		Mier->MyWil = Mier->MyWil + DeltaT4;
	}
	else
	{
		Mier->MyWil = Mier->MyWil + DeltaT3;
	}
}

void COgrodek::update2()
{
	if (Mier->MyWil < 99)
	{
		Mier->MyWil = Mier->MyWil + DeltaT8;
		cout << "PADA DESZCZ\n" << endl;
	}
}