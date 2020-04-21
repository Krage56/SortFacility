#include "SortStationFunctions.h"

TwoLinkedList myLittleParser(std::string& input){
    size_t len = input.length();//длина прохода
    size_t ind = 0;//текущее положение на строке
    std::string tmpNum("");
    std::string tmpFunc("");
    std::string locTmp("-1");
    std::string currentStr("");
    TwoLinkedList result;
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
            if((result.size() == 0) || ((result[result.size() - 1]->getType() != TokenType::Number) &&
             (result[result.size() - 1]->getType() != TokenType::Function)))
            {
                unarMinus = true;
            }
            else{
                result.pushBack(new OperatorToken(OperationName::Minus));
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

Queue shuntingYard(TwoLinkedList& tokens){
    Queue q;
    Stack st;
    for(int i = 0; i < tokens.size(); ++i){
        if(tokens[i]->getType() == TokenType::Number){
            q.enqueue(tokens[i]);
        }
        if(tokens[i]->getType() == TokenType::Function){
            st.push(tokens[i]);
        }
        if(tokens[i]->getType() == TokenType::Operator){
            while(easyComparator(tokens[i], q, st)){
                q.enqueue(st.top());
                st.pop();
            }
            st.push(tokens[i]);
        }
        if(tokens[i]->getType() == TokenType::LeftBracket){
            st.push(tokens[i]);
        }
        if(tokens[i]->getType() == TokenType::RightBracket){
            while(st.top()->getType() != TokenType::LeftBracket){
                q.enqueue(st.top());
                st.pop();
            }
            if(st.isEmpty()){
                throw std::invalid_argument("Brackets are not balanced");
            }
            //q.enqueue(st.top());
            st.pop();
            //q.enqueue(tokens[i]);//fix
        }
    }
    while(!st.isEmpty()){
        if((st.top()->getType() == TokenType::LeftBracket) ||
        (st.top()->getType() == TokenType::RightBracket)){
            throw std::invalid_argument("Brackets are not balanced");
        }
        q.enqueue(st.top());
        st.pop();
    }
    return q;
}
bool easyComparator(ValueType token, Queue& q, Stack& st){
    if(!st.isEmpty() && st.top()->getType() == TokenType::Function)
        return (st.top()->getType() != TokenType::RightBracket);

    if(!st.isEmpty() && (st.top()->getType() == TokenType::Operator) &&
    (dynamic_cast<OperatorToken*>(st.top())->getPriority() >
      dynamic_cast<OperatorToken*>(token)->getPriority()))
    {
        return (st.top()->getType() != TokenType::RightBracket);
    }

    if((!st.isEmpty() &&  (st.top()->getType() == TokenType::Operator) &&
    (dynamic_cast<OperatorToken*>(st.top())->getPriority() ==
      dynamic_cast<OperatorToken*>(token)->getPriority())) &&
            (dynamic_cast<OperatorToken*>(token)->getAssociative() == Associativity::Left))
    {
        return (st.top()->getType() != TokenType::RightBracket);
    }
    return false;
}

long long calculation(Queue& outputQueue){
    ValueType tmp;
    std::string tmpStr = "";
    Stack localStack;
    while(!outputQueue.isEmpty()){
        tmp = outputQueue.front();
        outputQueue.dequeue();
        if(tmp->getType() == TokenType::Number){
            localStack.push(tmp);
        }
        if(tmp->getType() == TokenType::Operator){
            short j = dynamic_cast<OperatorToken*>(tmp)->getOperType()==OperationType::Unary?1:2;
            long long arr[2];
            for(short i = j; i > 0; --i){
                arr[i - 1] = dynamic_cast<NumToken*>(localStack.top())->getCap();
                localStack.pop();
            }
            if(j == 2){
                switch(dynamic_cast<OperatorToken*>(tmp)->getName()){
                    case OperationName::Minus:{
                        arr[0] -= arr[1];
                        tmpStr = std::to_string(arr[0]);
                        localStack.push(new NumToken(tmpStr));
                        break;
                    }
                    case OperationName::Plus:{
                        arr[0] += arr[1];
                        tmpStr = std::to_string(arr[0]);
                        localStack.push(new NumToken(tmpStr));
                        break;
                    }
                    case OperationName::Multi :{
                        arr[0] *= arr[1];
                        tmpStr = std::to_string(arr[0]);
                        localStack.push(new NumToken(tmpStr));
                        break;
                    }
                    case OperationName::Dev :{
                        arr[0] /= arr[1];
                        tmpStr = std::to_string(arr[0]);
                        localStack.push(new NumToken(tmpStr));
                        break;
                    }
                    case OperationName::Deg :{
                        tmpStr = std::to_string(pow(arr[0], arr[1]));
                        localStack.push(new NumToken(tmpStr));
                        break;
                    }
                }
            }
        }

    }
    return dynamic_cast<NumToken*>(localStack.top())->getCap();
}