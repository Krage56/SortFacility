//
// Created by krage56 on 18.04.2020.
//

#include <algorithm>
#include "QueueTwoLinkedList.h"

QueueTwoLinkedList::QueueTwoLinkedList():TwoLinkedList(){}
QueueTwoLinkedList::QueueTwoLinkedList(const QueueTwoLinkedList& copyList):TwoLinkedList(copyList){}

QueueTwoLinkedList& QueueTwoLinkedList::operator=
        (const QueueTwoLinkedList& copyList){
    if(this == &copyList){
        return *this;
    }
    TwoLinkedList::operator=(copyList);
    return *this;
}

QueueTwoLinkedList::QueueTwoLinkedList(QueueTwoLinkedList &&moveList) noexcept:TwoLinkedList(std::move(moveList)){}

QueueTwoLinkedList &QueueTwoLinkedList::operator=(QueueTwoLinkedList &&moveList) noexcept {
    if(this == &moveList){
        return *this;
    }
    TwoLinkedList::operator=(std::move(moveList));
    return *this;
}

void QueueTwoLinkedList::enqueue(const ValueType &value) {
    this->pushBack(value);
}

void QueueTwoLinkedList::dequeue() {
    this->removeFront();
}

const ValueType &QueueTwoLinkedList::front() const {
    return (*this)[0];
}

bool QueueTwoLinkedList::isEmpty() const {
    return this->TwoLinkedList::size() == 0;
}

size_t QueueTwoLinkedList::size() const {
    return TwoLinkedList::size();
}


