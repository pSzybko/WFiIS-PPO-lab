#include "MyNode.h"

MyNode::MyNode(int value){
	_value=value;
}

MyNode* MyNode::getNext() const{
  return _next;
}

void MyNode::setNext(MyNode* next){
  _next = next;
}

int MyNode::val() const{
  return _value;
}