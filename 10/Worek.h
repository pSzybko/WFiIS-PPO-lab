#pragma once

#include "Prezent.h"

class Worek{
public:
	void Wloz(Prezent p);
	void WypiszZawartosc() const;
	void UsunPrezentNumer(int index);
private:
	Prezent* _head=nullptr;
	Prezent* _tail=nullptr;
};