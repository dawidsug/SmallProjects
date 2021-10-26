#pragma once
#include "CWirtualnyPokoj.h"

class COgrodek :
	public CWirtualnyPokoj
{
public:
	COgrodek();
	~COgrodek();
	virtual void update();
	virtual void update2();
};

