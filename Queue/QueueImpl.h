//
// Created by krage56 on 19.04.2020.
//

#ifndef QUEUE_QUEUEIMPL_H
#define QUEUE_QUEUEIMPL_H

#include <cstddef>
#include "../GeneralToken.h"
typedef GeneralToken* ValueType;

class QueueImpl {
public:
    // добавление в хвост
    virtual void enqueue(const ValueType& value) = 0;
    // удаление с начала
    virtual void dequeue() = 0;
    // посмотреть элемент в начале
    virtual const ValueType& front() const = 0;
    // проверка на пустоту
    virtual bool isEmpty() const = 0;
    // размер
    virtual size_t size() const = 0;
    // виртуальный деструктор
    virtual ~QueueImpl() {};
};
#endif //QUEUE_QUEUEIMPL_H
