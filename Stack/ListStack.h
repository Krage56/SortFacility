#pragma once

#include "StackImplementation.h"
#include "ListStack.h"
#include "../LinkedList ZRL/LinkedList.h"

class ListStack : virtual public StackImplementation, public LinkedList
{
public:
    ListStack();
    explicit ListStack(const ListStack& copyList);
    ListStack& operator=(const ListStack& copyVec);

    // Конструктор копирования присваиванием
    ListStack(ListStack&& moveVec) noexcept;
    ListStack& operator=(ListStack&& moveVec) noexcept;
    // добавление в конец
    void push(const ValueType& value) override;
    // удаление с хвоста
    void pop() override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер
    size_t size() const override;
    // деструктор
    ~ListStack()override ;

};

