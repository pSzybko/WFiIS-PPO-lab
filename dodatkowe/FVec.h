#pragma once

#include <initializer_list>
#include <iostream>
#include <functional>

class FVec{
public:
	static FVec create(int n);
	FVec(int p, int k);
	FVec(int f(const int), int n);
	FVec(const FVec& other);
	FVec(FVec&& other);
	~FVec();
	int begin();
	int end();
	int& operator[](int index) const;
	int retDlugosc() const;
	int retIndex() const;
	int retWart(int index) const;
	friend std::ostream& operator<< (std::ostream& s, const FVec &w);
	FVec& operator= (const FVec& other);
	FVec& set(int index, int n);
private:
	FVec()=default;
	int* _arr=nullptr;
	int _dlugosc=0;
	int _index=0;
};


