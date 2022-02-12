#include "MyString.h"

int MyString::id=0;

MyString::MyString(const char* str){
	_str=new char[strlen(str)+1];
	strcpy(_str, str);
	_id=++id;
}

MyString::~MyString(){
	//- deleting jest
	std::cout<<"- deleting "<<_str<<std::endl;
	delete [] _str;
}

void MyString::print() const{
	std::cout<<"ID: "<<_id<<"str: "<<_str<<std::endl;
}

MyString MyString::create(const char* str){
	MyString tmp(str);
	return tmp;
}

void MyString::join(const MyString& ms){
	char* str=_str;
	_str=new char [strlen(str)+strlen(ms._str)+1];
	strcpy(_str, str);
	strcat(_str, ms._str);
	delete [] str;
}

void MyString::replace(const char* str){
	delete [] _str;
	_str = new char[strlen(str)+1];
	strcpy(_str, str);
}

void swap(MyString& ms1, MyString& ms2){
	char* tmp=ms1._str;
	ms1._str=ms2._str;
	ms2._str=tmp;
}