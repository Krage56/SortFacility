#ifndef SORTSTATION_SORTSTATIONFUNCTIONS_H
#define SORTSTATION_SORTSTATIONFUNCTIONS_H
#include "./Stack/Stack.h"
#include "./Queue/Queue.h"
#include "GeneralToken.h"
#include "OperatorToken.h"
#include "NumToken.h"
#include "Brackets.h"
#include <string>
#include <vector>
#include "./Vector/MyVector.h"
#include "./TwoLinkedList/Two-LinkedList.h"
#include <cmath>

TwoLinkedList myLittleParser(std::string& input);
Queue shuntingYard(TwoLinkedList& tokens);
bool easyComparator(ValueType token, Queue& q, Stack& st);
long long calculation(Queue& outputQueue);
#endif //SORTSTATION_SORTSTATIONFUNCTIONS_H
