//
// Created by krage56 on 19.04.2020.
//

#include "Queue.h"
#include "QueueList.h"
#include "QueueTwoLinkedList.h"
#include "QueueVector.h"

Queue::Queue(QueueContainer container): _containerType(container)
{
    switch (container)
    {
        case QueueContainer::TwoLinkedList: {
            _pimpl = new QueueTwoLinkedList();
            break;
        }
        case QueueContainer::LinkedList: {
            _pimpl = new QueueList();
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = new QueueVector();
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue::Queue(const ValueType *valueArray, const size_t arraySize, QueueContainer container) {
    switch (container)
    {
        case QueueContainer::TwoLinkedList: {
            _pimpl = new QueueTwoLinkedList();
            break;
        }
        case QueueContainer::LinkedList: {
            _pimpl = new QueueList();
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = new QueueVector();
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    for(size_t i = 0; i < arraySize; ++i){
        _pimpl->enqueue(valueArray[i]);
    }
}

Queue::Queue(const Queue& copyQueue){
    delete(_pimpl);
    switch (copyQueue._containerType) {
        case QueueContainer::LinkedList: {
            _pimpl = new QueueList(*(dynamic_cast<QueueList*>(copyQueue._pimpl)));
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = new QueueVector(
                    *(dynamic_cast<QueueVector*>(copyQueue._pimpl)));    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case QueueContainer::TwoLinkedList: {
            _pimpl = new QueueTwoLinkedList(
                    *(dynamic_cast<QueueTwoLinkedList*>(copyQueue._pimpl)));    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
    }
    _containerType = copyQueue._containerType;
}

Queue& Queue::operator=(const Queue& copyQueue){
    if(this == &copyQueue){
        return *this;
    }
    delete(_pimpl);
    switch (copyQueue._containerType) {
        case QueueContainer::LinkedList: {
            _pimpl = new QueueList(*(dynamic_cast<QueueList*>(copyQueue._pimpl)));
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = new QueueVector(
                    *(dynamic_cast<QueueVector*>(copyQueue._pimpl)));    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case QueueContainer::TwoLinkedList: {
            _pimpl = new QueueTwoLinkedList(
                    *(dynamic_cast<QueueTwoLinkedList*>(copyQueue._pimpl)));    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
    }
    _containerType = copyQueue._containerType;
}

Queue::Queue(Queue &&moveQueue) noexcept {
    delete(_pimpl);
    _pimpl = moveQueue._pimpl;
    moveQueue._pimpl = nullptr;
    _containerType = moveQueue._containerType;
}

Queue &Queue::operator=(Queue &&moveQueue) noexcept {
    delete(_pimpl);
    _pimpl = moveQueue._pimpl;
    moveQueue._pimpl = nullptr;
    _containerType = moveQueue._containerType;

    return *this;
}

Queue::~Queue() {
    delete _pimpl;
}

void Queue::enqueue(const ValueType &value) {
    _pimpl->enqueue(value);
}

void Queue::dequeue() {
    _pimpl->dequeue();
}

const ValueType &Queue::front() const {
    return _pimpl->front();
}

bool Queue::isEmpty() const {
    return _pimpl->isEmpty();
}

size_t Queue::size() const {
    return _pimpl->size();
}






