#pragma once

#include <iostream>
#include <cstring>

struct node{
	char* data;
	node* next;
};

struct List{
	node* head;
};

void prepare(List* l);

void add(List* l, const char* val);

int empty(const List* l);

void dump(const List* l);

void clear(List* l);