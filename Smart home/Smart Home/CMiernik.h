#pragma once

class CMiernik
{
public:
	CMiernik();
	~CMiernik();
	void PodajTemp();
	void PodajWilOgr();
	void PodajGaz();
	void PodajWilLaz();
	float MyTemp;
	float MyWil;
	float MyGaz;
	float MyWilLaz;
};

