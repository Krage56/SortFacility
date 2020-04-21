//
// Created by krage56 on 21.04.2020.
//

#ifndef SORTSTATION_OPERATORTOKEN_H
#define SORTSTATION_OPERATORTOKEN_H

#include <string>
#include "GeneralToken.h"
enum struct OperationName{
    Dev,
    Multi,
    Plus,
    Minus,
    Deg
};
enum struct OperationType{
    Unary = 0,
    Binary
};
enum struct Associativity{
    All,
    Left,
    Right
};

class OperatorToken: virtual public GeneralToken{
public:
    OperatorToken(OperationName operation);
    std::string getCap();
    unsigned short getPriority();
    Associativity getAssociative();
    OperationType getType();
    ~OperatorToken()= default;
protected:
    OperationName _operName;
    OperationType _operType;
    Associativity _operAssoc;
    unsigned short _priority;
};


#endif //SORTSTATION_OPERATORTOKEN_H
