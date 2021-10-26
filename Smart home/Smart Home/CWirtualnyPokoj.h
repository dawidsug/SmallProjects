#pragma once
#include "CMiernik.h"
#include "CSystemWentylacyjny.h"
#include "CZraszacz.h"
#include "CGrzejnik.h"
#include <iostream>
#include <locale.h>
using namespace std;

class CWirtualnyPokoj
{
public:
	CWirtualnyPokoj();
	~CWirtualnyPokoj();
	CMiernik *Mier;
	CSystemWentylacyjny *Wen;
	CZraszacz *Zra;
	CGrzejnik *Grze;
	void update();
protected:
	float DeltaT1;
	float DeltaT2;
	float DeltaT3;
	float DeltaT4;
	float DeltaT5;
	float DeltaT6;
	float DeltaT7;
	float DeltaT8;
};

