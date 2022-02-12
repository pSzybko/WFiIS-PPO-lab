#pragma once

class MyNode
{
public:
	MyNode(int value);
  	MyNode* getNext() const;
  	int val() const;
  	void setNext(MyNode* next);
private:
	MyNode* _next=nullptr;
	int _value=0;
};
