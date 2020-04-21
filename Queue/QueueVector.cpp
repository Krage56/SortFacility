
#include "./QueueVector.h"
#include <algorithm>


QueueVector::QueueVector():
MyVector(10, ResizeStrategy::Multiplicative, 2), _queueSize(0), _begInd(0){}

QueueVector::QueueVector(const QueueVector& copyVector)
:MyVector(copyVector), _queueSize(copyVector._queueSize),_begInd(copyVector._begInd) {}

QueueVector& QueueVector::operator=(const QueueVector& copyVector){
    if(this == &copyVector){
        return *this;
    }
    MyVector::operator=(copyVector);
    _queueSize = copyVector._queueSize;
    _begInd = copyVector._begInd;
    return *this;
}

QueueVector::QueueVector(QueueVector &&moveVector) noexcept {
    delete(dynamic_cast<MyVector*>(this));
    _queueSize = moveVector._queueSize;
    _begInd = moveVector._begInd;
    moveVector._queueSize = 0;
    moveVector._begInd = 0;
    *(dynamic_cast<MyVector*>(this)) = std::move(moveVector);
}

QueueVector &QueueVector::operator=(QueueVector &&moveVector) noexcept {
    if(this == &moveVector){
        return *this;
    }
    delete(dynamic_cast<MyVector*>(this));
    _queueSize = moveVector._queueSize;
    _begInd = moveVector._begInd;
    moveVector._queueSize = 0;
    moveVector._queueSize = 0;
    *(dynamic_cast<MyVector*>(this)) = std::move(moveVector);
    return *this;
}

void QueueVector::enqueue(const ValueType &value) {
    if(_queueSize + 1 + _begInd <= this->MyVector::size()){
        (*this)[_queueSize + _begInd] = value;
    }
    else{
        if (_begInd){
            this->erase(0, _begInd);
            _begInd = 0;
            //(*this)[_queueSize] = value;
            pushBack(value);
        }
        else{
            (*this).pushBack(value);
        }
        this->MyVector::resize(2 * (_queueSize == 0? 1: _queueSize), new GeneralToken());
    }
    ++_queueSize;
}

void QueueVector::dequeue() {
    if(_queueSize){
        --_queueSize;
        ++_begInd;
    }
}

const ValueType &QueueVector::front() const {
    if(_queueSize){
        return (*this)[_begInd];
    }
}

bool QueueVector::isEmpty() const {
    return (_queueSize == 0);
}

size_t QueueVector::size() const {
    return _queueSize;
}


