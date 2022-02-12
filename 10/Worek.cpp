#include "Worek.h"

void Worek::Wloz(Prezent p){
	if(_head==nullptr){
		_tail=_head=&p;
		return;
	}
	_tail->_next=&p;
	_tail=_tail->_next;
}

void Worek::WypiszZawartosc() const{
	std::cout<<"=== Zawartosc worka ==="<<std::endl;
	Prezent* ptr=_head;
	int i=0;
	while(ptr!=_tail){
		std::cout<<++i<<". ";
		ptr->Wypisz();
		ptr=ptr->_next;
	}
	std::cout<<++i<<". ";
	ptr->Wypisz();
}

void Worek::UsunPrezentNumer(int index){
	if(index==1){
		_head=_head->_next;
		return;
	}
	if(index==2){
		_head->_next=_head->_next->_next;
		return;
	}
	Prezent* ptr=_head;
	for(int i=0; i<index-2; i++)
		ptr=ptr->_next;
	if(ptr->_next==_tail){
		_tail=ptr;
		return;
	}
	ptr->_next=ptr->_next->_next;	
}
