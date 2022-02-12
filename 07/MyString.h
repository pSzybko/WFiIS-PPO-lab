#pragma once

#include <iostream>
#include <cstring>

struct MyString{
	char* str=nullptr;
};

void init(MyString& ms, const char* str);

MyString join(const MyString& ms1, const MyString& ms2);

void swap(MyString& ms1, MyString& ms2);

void swap(MyString*& ms1, MyString*& ms2);

void del(MyString& ms1, MyString& ms2, MyString& ms3, MyString& ms4);

void del(MyString& ms);