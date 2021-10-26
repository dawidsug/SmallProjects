#include "CKuchnia.h"

CKuchnia::CKuchnia()
{
}


CKuchnia::~CKuchnia()
{
}

void CKuchnia::update()
{
	if (Wen->MyStan == 1)
	{
		Mier->MyGaz = Mier->MyGaz + DeltaT6;
	}
	else
	{
		Mier->MyGaz = Mier->MyGaz + DeltaT5;
	}
}
