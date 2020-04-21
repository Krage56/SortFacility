//
// Created by krage56 on 18.04.2020.
//

#ifndef QUEUE_QUEUELIST_H
#define QUEUE_QUEUELIST_H

#include "QueueImpl.h"
#include "../LinkedList ZRL/LinkedList.h"

class QueueList:
        public  QueueImpl, LinkedList{
public:
    QueueList();
    explicit QueueList(const QueueList& copyList);
    QueueList& operator=(const QueueList& copyList);

    // Конструктор копирования присваиванием
    QueueList(QueueList&& moveList) noexcept;
    QueueList& operator=(QueueList&& moveList) noexcept;
    // добавление в хвост
    void enqueue(const ValueType& value);
    // удаление с начала
    void dequeue() override;
    // посмотреть элемент в начале
    const ValueType& front() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер
    size_t size() const override;

};


#endif //QUEUE_QueueList_H

