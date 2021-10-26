#include "CLazienka.h"

CLazienka::CLazienka()
{
}


CLazienka::~CLazienka()
{
}

void CLazienka::update()
{
	if (Wen->MyStan2 == 1)
	{
		Mier->MyWilLaz = Mier->MyWilLaz + DeltaT6;
	}
	else
	{
		Mier->MyWilLaz = Mier->MyWilLaz + DeltaT7;
	}
}