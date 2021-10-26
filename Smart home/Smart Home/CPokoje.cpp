#include "CPokoje.h"

CPokoje::CPokoje()
{
}


CPokoje::~CPokoje()
{
}


void CPokoje::update()
{
	if (Grze->MyStan == 1)
	{
		Mier->MyTemp = Mier->MyTemp + DeltaT2;
	}
	else
	{
		Mier->MyTemp = Mier->MyTemp + DeltaT1;
	}
}
