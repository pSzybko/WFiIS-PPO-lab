#include "MyString.h"

MyString::MyString(){
	_str=nullptr;
}

MyString::MyString(const char* str){
	_str=new char[strlen(str)+1];
	strcpy(_str, str);
}

MyString::MyString(const MyString& other){
	_str=new char[strlen(other._str)+1];
	strcpy(_str, other._str);
}

MyString::~MyString(){
	delete [] _str;
}

MyString MyString::operator+(const MyString& ms){
	MyString tmp;
	tmp._str=new char[strlen(_str)+strlen(ms._str)+1];
	strcpy(tmp._str, _str);
	strcat(tmp._str, ms._str);
	return tmp;
}

MyString operator*(MyString& ms, int n){
	MyString tmp;
	tmp._str=new char[n*strlen(ms._str)+1];
	strcpy(tmp._str, ms._str);
	for(int i=0; i<n-1; i++)
		strcat(tmp._str, ms._str);
	ms=tmp;
	return tmp;
}

MyString operator*(int n, MyString& ms){
	MyString tmp;
	tmp._str=new char[n*strlen(ms._str)+1];
	strcpy(tmp._str, ms._str);
	for(int i=0; i<n-1; i++)
		strcat(tmp._str, ms._str);
	return tmp;
}

bool MyString::operator==(const char* str){
	 if(strcmp(_str, str))
	 	return false;
	 return true;
}

MyString MyString::operator=(const MyString& other){
	delete [] _str;
	_str=new char[strlen(other._str)+1];
	strcpy(_str, other._str);
	return *this;
}