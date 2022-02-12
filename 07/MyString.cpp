#include "MyString.h"

void init(MyString& ms, const char* str){
	ms.str=new char[strlen(str)+1];
	strcpy(ms.str, str);
}

MyString join(const MyString& ms1, const MyString& ms2){
	MyString tmp;
	tmp.str=new char[strlen(ms1.str)+strlen(ms2.str)+1];
	strcpy(tmp.str, ms1.str);
	strcat(tmp.str, ms2.str);
	return tmp;
}

void swap(MyString& ms1, MyString& ms2){
	MyString tmp=ms1;
	ms1=ms2;
	ms2=tmp;
}

void swap(MyString*& ms1, MyString*& ms2){
	MyString* tmp=ms1;
	ms1=ms2;
	ms2=tmp;
}

void del(MyString& ms){
	if(ms.str!=nullptr){delete [] ms.str; ms.str=nullptr;}
}

void del(MyString& ms1, MyString& ms2, MyString& ms3, MyString& ms4){
	del(ms1);
	del(ms2);
	del(ms3);
	del(ms4);
}