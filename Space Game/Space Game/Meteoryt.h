#pragma once
#include <cstdlib>
#include <ctime>
using namespace std;
class Meteoryt
{
public:
	Meteoryt();
	~Meteoryt();
	int losowanie();
protected:
	virtual int lot(int);
	int pozycjaMet;
};

