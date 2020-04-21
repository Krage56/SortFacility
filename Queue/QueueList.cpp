//
// Created by krage56 on 18.04.2020.
//

#include <algorithm>
#include "QueueList.h"

QueueList::QueueList():LinkedList(){}
QueueList::QueueList(const QueueList& copyList):LinkedList(copyList){}

QueueList& QueueList::operator=
        (const QueueList& copyList){
    if(this == &copyList){
        return *this;
    }
    LinkedList::operator=(copyList);
    return *this;
}

QueueList::QueueList(QueueList &&moveList) noexcept:LinkedList(std::move(moveList)){}

QueueList &QueueList::operator=(QueueList &&moveList) noexcept {
    if(this == &moveList){
        return *this;
    }
    LinkedList::operator=(std::move(moveList));
    return *this;
}

void QueueList::enqueue(const ValueType &value) {
    this->pushBack(value);
}

void QueueList::dequeue() {
    this->removeFront();
}

const ValueType &QueueList::front() const {
    return (*this)[0];
}

bool QueueList::isEmpty() const {
    return this->LinkedList::size() == 0;
}

size_t QueueList::size() const {
    return LinkedList::size();
}


