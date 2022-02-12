#include "FVec.h"

FVec FVec::create(int n){
	FVec w;
	w._dlugosc=n;
	w._arr=new int[n];
	for(int i=0; i<n; i++)
		w._arr[i]=0;
	return w;
}

FVec::FVec(int p, int k){
	_dlugosc=k-p;
	_index=p;
	_arr=new int[_dlugosc];
	for(int i=0; i< _dlugosc; i++)
		_arr[i]=0;
}

FVec::FVec(int f(const int), int n){
	_index=0;
	_dlugosc=n;
	_arr=new int[_dlugosc];
	for(int i=0; i<_dlugosc; i++)
		_arr[i]=f(i);
}

FVec::FVec(const FVec& other){
	_dlugosc=other._dlugosc;
	_index=other._index;
	_arr=new int[_dlugosc];
	for(int i=0; i<_dlugosc; i++)
		_arr[i]=other._arr[i];
}

FVec::FVec(FVec&& other){
	_dlugosc=std::exchange(other._dlugosc, 0);
	_index=std::exchange(other._index, 0);
	_arr=std::exchange(other._arr, nullptr);
}

FVec::~FVec(){
	delete [] _arr;
	_index=0;
	_dlugosc=0;
}	
int FVec::begin(){
	return _index;
}


int FVec::end(){
	return (_index+_dlugosc);
}

int& FVec::operator[](int index) const{
	return _arr[index-_index];
}


int FVec::retDlugosc() const{
	return _dlugosc;
}

int FVec::retIndex() const{
	return _index;
}

int FVec::retWart(int index) const{
	return _arr[index];
}

std::ostream& operator<< (std::ostream& s, const FVec& w) 
{
    s<<"idx["<<w.retIndex()<<","<<w.retDlugosc()+w.retIndex()<<"] ";
    for (int i=0;i<w.retDlugosc();i++)
        s<<w.retWart(i)<<" ";
    return s;
}

FVec& FVec::set(int index, int n){
	_arr[index]=n;
	return *this;
}

FVec& FVec::operator= (const FVec& other)
{
	if (this != &other)
	{
		delete [] _arr;
		_index = other._index;
		_dlugosc = other._dlugosc;
		_arr = new int [_dlugosc];
		for (int i = 0; i < _dlugosc; i++)
			_arr[i] = other._arr[i];
	}

	return *this;
}