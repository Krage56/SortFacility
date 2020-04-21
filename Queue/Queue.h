//
// Created by krage56 on 19.04.2020.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <cstddef>
#include "../GeneralToken.h"
typedef GeneralToken* ValueType;

// на основе какого контейнера работает стек
enum class QueueContainer {
    Vector,
    LinkedList,
    TwoLinkedList
};

// декларация класса с реализацией
class QueueImpl;


class Queue {
public:
    Queue(QueueContainer container = QueueContainer::TwoLinkedList);
    
    Queue(const ValueType* valueArray, const size_t arraySize,
          QueueContainer container = QueueContainer::Vector);

    Queue(const Queue& copyQueue);
    Queue& operator=(const Queue& copyQueue);
    
    Queue(Queue&& moveQueue) noexcept;
    Queue& operator=(Queue&& moveQueue) noexcept;

    ~Queue();

    // добавление в хвост
    void enqueue(const ValueType& value);
    // удаление с начала
    void dequeue();
    // посмотреть элемент в начале
    const ValueType& front() const;
    // проверка на пустоту
    bool isEmpty() const;
    // размер
    size_t size() const;

private:
    // указатель на имплементацию (уровень реализации)
    QueueImpl* _pimpl = nullptr;
    // тип контейнера, наверняка понадобится
    QueueContainer _containerType;
};


#endif //QUEUE_QUEUE_H
