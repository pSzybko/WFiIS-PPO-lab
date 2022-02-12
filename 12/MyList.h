#pragma once
#include <initializer_list>
#include "MyNode.h"

class MyList{
public:
  MyList();
  MyList(int n);
  MyList(std::initializer_list<int> list);
  MyList(const MyList& other);
  MyList(MyList&& other);
  MyList(int (*function)(MyNode*), int size);
  ~MyList();
  void add(int elem);
  void clear();
  bool empty() const;
  unsigned size() const;
  void print() const;
private:
  MyNode* _head=nullptr;
  MyNode* _tail=nullptr;
  unsigned _size=0;
};
