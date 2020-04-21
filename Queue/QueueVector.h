//
// Created by krage56 on 18.04.2020.
//

#ifndef QUEUE_QUEUEVECTOR_H
#define QUEUE_QUEUEVECTOR_H

#include "QueueImpl.h"
#include "../Vector/MyVector.h"

class QueueVector:
        public virtual QueueImpl, MyVector {
public:
    QueueVector();
    explicit QueueVector(const QueueVector& copyVector);
    QueueVector& operator=(const QueueVector& copyVector);

    // Конструктор копирования присваиванием
    QueueVector(QueueVector&& moveVector) noexcept;
    QueueVector& operator=(QueueVector&& moveVector) noexcept;
    // добавление в хвост
    void enqueue(const ValueType& value) override;
    // удаление с начала
    void dequeue() override;
    // посмотреть элемент в начале
    const ValueType& front() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер
    size_t size() const override;

private:
    size_t _queueSize;
    size_t _begInd;
};


#endif //QUEUE_QUEUEVECTOR_H
