#ifndef SORTSTATION_SORTSTATION_H
#define SORTSTATION_SORTSTATION_H
#include "./Stack/Stack.h"
#include "./Queue/Queue.h"
#include "GeneralToken.h"
#include "OperatorToken.h"
#include "NumToken.h"
#include "Brackets.h"
#include "./Vector/MyVector.h"
#include "./TwoLinkedList/Two-LinkedList.h"

class SortStation{
public:
    explicit SortStation(std::string& input);
    double getResult();
    ~SortStation()= default;
private:
    TwoLinkedList tokens;
    TwoLinkedList myLittleParser(std::string& input);
    Queue shuntingYard(TwoLinkedList& tokens);
    bool easyComparator(ValueType token, Queue& q, Stack& st);
    double calculation(Queue& outputQueue);
};

#endif //SORTSTATION_SORTSTATION_H
