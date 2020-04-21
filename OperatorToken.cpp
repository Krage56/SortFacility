//
// Created by krage56 on 21.04.2020.
//

#include <stdexcept>
#include "OperatorToken.h"

OperatorToken::OperatorToken(OperationName operation){
    if(operation == OperationName::Dev){
        _operAssoc = Associativity::Left;
        _operType = OperationType::Binary;
        _priority = 2;
    }
    else if(operation == OperationName::Multi){
        _operAssoc = Associativity::All;
        _operType = OperationType::Binary;
        _priority = 2;
    }
    else if(operation == OperationName::Plus){
        _operAssoc = Associativity::All;
        _operType = OperationType::Binary;
        _priority = 1;
    }
    else if(operation == OperationName::Minus){
        _operAssoc = Associativity::Left;
        _operType = OperationType::Binary;
        _priority = 1;
    }
    else if(operation == OperationName::Deg){
        _operAssoc = Associativity::Right;
        _operType = OperationType::Binary;
        _priority = 3;
    }
    else{
        throw std::invalid_argument("Invalid argument for "
                                    "OperatorToken constructor");
    }
    _operName = operation;
    _type = TokenType::Operator;
}

std::string OperatorToken::getCap() {
    switch(_operName){
        case OperationName::Dev:{
            return std::string("/");
        }
        case OperationName::Multi:{
            return std::string("*");
        }
        case OperationName::Minus:{
            return std::string("-");
        }
        case OperationName::Plus:{
            return std::string("+");
        }
        case OperationName::Deg:{
            return std::string("^");
        }
        default:
            return std::string("");
    }
}

unsigned short OperatorToken::getPriority() {
    return _priority;
}

Associativity OperatorToken::getAssociative() {
    return _operAssoc;
}

OperationName OperatorToken::getName() {
    return _operName;
}

OperationType OperatorToken::getOperType() {
    return _operType;
}
