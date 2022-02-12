#include "lab05.h"

void prepare(List* l){
	l->head=nullptr;
}

void add(List* l, const char* val){
	node* tmp=new node;
	tmp->data=new char[strlen(val)+1];
	strcpy(tmp->data, val);
	tmp->next=nullptr;
	node* ptr=l->head;
	if(l->head==nullptr){
		l->head=tmp;
		return;
	}
	while(ptr->next!=nullptr)
		ptr=ptr->next;
	ptr->next=tmp;
}

int empty(const List* l){
	return ((l->head==nullptr) ? 1 : 0);
}

void dump(const List* l){
	if(empty(l))
		return;
	node* ptr=l->head;
	while(ptr->next!=nullptr){
		std::cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	std::cout<<ptr->data;
}

void clear(List* l){
	if(empty(l))
		return;
	node* ptr1=l->head;
	node* ptr2=l->head;
	while(ptr1->next!=nullptr){
		ptr2=ptr1->next;
		delete [] ptr1->data;
		delete ptr1;
		ptr1=ptr2;
	}
	delete [] ptr1->data;
	delete ptr1;
	l->head=nullptr;
}