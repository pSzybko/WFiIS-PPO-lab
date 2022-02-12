#pragma once

#include <iostream>
#include <cstring>

class MyString{
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	~MyString();
	friend std::ostream& operator<<(std::ostream& s, const MyString& ms);
	MyString operator+(const MyString& ms);
	friend MyString operator*(int n, MyString& ms);
	friend MyString operator*(MyString& ms, int n);
	bool operator==(const char* str);
	MyString operator=(const MyString& other);
private:
	char* _str;
};

std::ostream& operator<<(std::ostream& s, const MyString& ms){
	s<<ms._str;
	return s;
}