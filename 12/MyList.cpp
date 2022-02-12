#include <iostream>
#include <utility>
#include "MyList.h"


void MyList::add(int elem){
  if(_tail==nullptr){
    _head=new MyNode(elem);
    _tail=_head;
  }
  else{
    _tail->setNext(new MyNode(elem));
    _tail=_tail->getNext();
  }
  _size++;
}

MyList::MyList(){
  std::cout<<"KONST: Domyslny"<<std::endl;
}

MyList::MyList(int n)
: MyList()
{
  std::cout<<"KONST: Jednoargumentowy"<<std::endl;
  for(int i=0; i<n; i++)
    add(i);
}

MyList::MyList(const MyList& other)
: MyList()
{
  std::cout<<"KONST: kopiujacy"<<std::endl;
  MyNode* ptr = other._head;
  while(ptr != nullptr)
  {
    add(ptr->val());
    ptr = ptr->getNext();
  }
}

MyList::MyList(MyList&& other):
_head(std::exchange(other._head, nullptr)), 
_tail(std::exchange(other._tail, nullptr)),
_size(std::exchange(other._size, 0))
{
  std::cout<<"KONST: przenoszacy"<<std::endl;
}

MyList::MyList(int (*function)(MyNode*), int size){
  std::cout<<"KONST: funkcja generujaca"<<std::endl;

    for(int i = 0; i < size; i++)
  {
    add(function(_tail));
  }
}

MyList::~MyList(){
  std::cout<<"DESTRUKTOR (rozmiar = "<<_size<<")"<<std::endl;
  clear();
}

void MyList::clear()
{
  MyNode* next = _head;
  while(next != nullptr)
  {
    MyNode* temp = next->getNext();
    delete next;
    next = temp;
  }
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

MyList::MyList(std::initializer_list<int> list){
    std::cout<<"KONST: std::initializer_list"<<std::endl;

  std::initializer_list<int>::iterator next = list.begin();
  while(next != list.end())
  {
    add(*next);
    next++;
  }
}

bool MyList::empty() const
{
  return _size == 0;
}

unsigned MyList::size() const
{
  return _size;
}

void MyList::print() const
{
  if(_size == 0)
  {
    std::cout<<"[]"<<std::endl;
    return;
  }

  std::cout<<"["<<_head->val();
  MyNode* next = _head->getNext();
  while(next != nullptr)
  {
    std::cout<<", "<<next->val();
    next = next->getNext();
  }
  std::cout<<"]"<<std::endl;
}