#include "ListStack.h"
#include <iostream>
using namespace std;
ListStack::ListStack():
 LinkedList(){}

ListStack::~ListStack() {}

ListStack::ListStack(const ListStack &copyList):LinkedList(copyList){}

ListStack &ListStack::operator=(const ListStack &copyList) {
    if(this == &copyList){
        return *this;
    }
    LinkedList::operator=(copyList);
    return *this;
}

ListStack::ListStack(ListStack &&moveList) noexcept:LinkedList(std::move(moveList)){}

ListStack &ListStack::operator=(ListStack &&moveList) noexcept {
    if(this == &moveList){
        return *this;
    }
    LinkedList::operator=(std::move(moveList));
    return *this;
}

void ListStack::push(const ValueType &value) {
    (*this).pushBack(value);
}

void ListStack::pop() {
    this->removeBack();
}

const ValueType &ListStack::top() const {
    return (*this)[this->size() - 1];
}

bool ListStack::isEmpty() const {
    return this->LinkedList::size() == 0;
}

size_t ListStack::size() const {
    return LinkedList::size();
}




