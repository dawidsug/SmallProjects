#pragma once
#include "CWirtualnyPokoj.h"

class CKuchnia :
	public CWirtualnyPokoj
{
public:
	CKuchnia();
	~CKuchnia();
	virtual void update();
};

