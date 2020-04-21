#include "SortStationFunctions.h"

TwoLinkedList/*MyVector*/ myLittleParser(std::string& input){
//std::vector<GeneralToken*> myLittleParser(std::string& input){
    size_t len = input.length();//длина прохода
    size_t ind = 0;//текущее положение на строке
    std::string tmpNum("");
    std::string tmpFunc("");
    std::string locTmp("-1");
    std::string currentStr("");
    TwoLinkedList result;
    //std::vector<GeneralToken*> result;
    bool unarMinus = false;
    while(len){
        currentStr = input.substr(ind, 1);
        if ((!tmpFunc.empty() || !tmpNum.empty()) && (
                (currentStr == "(") || (currentStr == ")") || (currentStr == "*") || (currentStr == "/")
                || (currentStr == "+") || (currentStr == "-") || (currentStr == "^")))
        {
            if(unarMinus){
                    unarMinus = !unarMinus;
                    result.pushBack(new NumToken(locTmp));
                    result.pushBack(new OperatorToken(OperationName::Multi));
            }
            if (!tmpFunc.empty()){
                result.pushBack(new FuncToken(tmpFunc));
                tmpFunc = "";
            }
            if(!tmpNum.empty()){
                result.pushBack(new NumToken(tmpNum));
                tmpNum = "";
            }
        }
        if(currentStr == "("){
            result.pushBack(new Brackets(TokenType::LeftBracket));
        }
        else if(currentStr == ")") {
            result.pushBack(new Brackets(TokenType::RightBracket));
        }
        else if(currentStr == "*") {
                result.pushBack(new OperatorToken(OperationName::Multi));
        }
        else if(currentStr == "/") {
            result.pushBack(new OperatorToken(OperationName::Dev));
        }
        else if(currentStr == "+") {
            result.pushBack(new OperatorToken(OperationName::Plus));
        }
        else if(currentStr == "-") {
            if((result.size() == 0) || (result[result.size() - 1]->getType() == TokenType::Number) ||
             (result[result.size() - 1]->getType() == TokenType::Function))
            {
                result.pushBack(new OperatorToken(OperationName::Minus));
            }
            else{
                unarMinus = true;
            }
        }
        else if(currentStr == "^") {
            result.pushBack(new OperatorToken(OperationName::Deg));
        }
        else if(isdigit(*currentStr.c_str())){
            tmpNum += input.substr(ind, 1);
        }
        else if(currentStr != " "){
            tmpFunc += input.substr(ind, 1);
        }
        --len;
        ++ind;
    }
    if(unarMinus){
        unarMinus = !unarMinus;
        result.pushBack(new NumToken(locTmp));
        result.pushBack(new OperatorToken(OperationName::Multi));
    }
    if (!tmpFunc.empty()){
        result.pushBack(new FuncToken(tmpFunc));
        tmpFunc = "";
    }
    if(!tmpNum.empty()){
        result.pushBack(new NumToken(tmpNum));
        tmpNum = "";
    }
    return result;
}
