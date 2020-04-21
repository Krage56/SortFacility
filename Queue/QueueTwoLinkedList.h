//
// Created by krage56 on 18.04.2020.
//

#ifndef QUEUE_QUEUETWOLINKEDLIST_H
#define QUEUE_QUEUETWOLINKEDLIST_H

#include "QueueImpl.h"
#include "../TwoLinkedList/Two-LinkedList.h"
class QueueTwoLinkedList:
        public  QueueImpl, TwoLinkedList{
public:
    QueueTwoLinkedList();
    explicit QueueTwoLinkedList(const QueueTwoLinkedList& copyList);
    QueueTwoLinkedList& operator=(const QueueTwoLinkedList& copyList);

    // Конструктор копирования присваиванием
    QueueTwoLinkedList(QueueTwoLinkedList&& moveList) noexcept;
    QueueTwoLinkedList& operator=(QueueTwoLinkedList&& moveList) noexcept;
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

};


#endif //QUEUE_QUEUETWOLINKEDLIST_H
