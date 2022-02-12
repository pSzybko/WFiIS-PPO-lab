#pragma once

#include <iostream>

class Prezent{
friend class Worek;
public:
	Prezent(int val);
	Prezent(const Prezent& other);
	void Wypisz() const;
private:
	int _val;
	Prezent* _next=nullptr;
};