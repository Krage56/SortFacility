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
//MyVector myLittleParser(std::string& input);
TwoLinkedList myLittleParser(std::string& input);
//std::vector<GeneralToken*> myLittleParser(std::string& input);
#endif //SORTSTATION_SORTSTATIONFUNCTIONS_H
