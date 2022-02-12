#pragma once

#include <iostream>
#include <cstring>

class MyString{
public:
	MyString(const char* str);
	~MyString();
	void print() const;
	static MyString create(const char* str);
	void join(const MyString& ms);
	void replace(const char* str);
	friend void swap(MyString& ms1, MyString& ms2);
private:
	char* _str;
	int _id;
	static int id;
};

