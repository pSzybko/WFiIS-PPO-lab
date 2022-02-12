#include "Prezent.h"

Prezent::Prezent(int val):_val(val), _next(nullptr)
{}

Prezent::Prezent(const Prezent& other): _val(other._val), _next(other._next)
{}

void Prezent::Wypisz() const{
	std::cout<<"Prezent o wartosci: "<<_val<<std::endl;
}

