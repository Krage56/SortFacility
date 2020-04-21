#include "VectorStack.h"
#include <iostream>
using namespace std;
VectorStack::VectorStack():MyVector(0, ResizeStrategy::Multiplicative, 2){}

VectorStack::~VectorStack() {}

VectorStack::VectorStack(const VectorStack &copyVec):MyVector(copyVec){}

VectorStack &VectorStack::operator=(const VectorStack &copyVec){
    if(this == &copyVec){
        return *this;
    }
    MyVector::operator=(copyVec);
    return *this;
}

VectorStack::VectorStack(VectorStack &&moveVec) noexcept :MyVector(std::move(moveVec)){}

VectorStack &VectorStack::operator=(VectorStack &&moveVec) noexcept {
    if(this == &moveVec){
        return *this;
    }
    MyVector::operator=(std::move(moveVec));
    return *this;
}

void VectorStack::push(const ValueType &value) {
    (*this).pushBack(value);
}

void VectorStack::pop() {
    if(this->size()){
        (*this).popBack();
    }
}

const ValueType &VectorStack::top() const {
    if(this->MyVector::size()){
        return (*this)[this->MyVector::size() - 1];
    }
}

bool VectorStack::isEmpty() const {
    return this->MyVector::size() == 0;
}

size_t VectorStack::size() const {
    return MyVector::size();
}



