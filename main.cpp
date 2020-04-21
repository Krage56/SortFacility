#include <iostream>
#include "SortStationFunctions.h"
using namespace std;
#define mem_block 1024
int main() {
    char buff[mem_block];
    cin.getline(buff, mem_block - 1);
    string input(buff);
    TwoLinkedList tokens = myLittleParser(input);
    for(int i = 0; i < tokens.size(); ++i){
        switch (tokens[i]->getType()){
            case TokenType::Number:{
                cout << (dynamic_cast<NumToken*>(tokens[i]))->getCap() << flush;
                break;
            }
            case TokenType::Function:{
                cout << (dynamic_cast<FuncToken*>(tokens[i]))->getCap()<< flush;
                break;
            }
            case TokenType::Operator:{
                cout << (dynamic_cast<OperatorToken*>(tokens[i]))->getCap()<< flush;
                break;
            }
            case TokenType::LeftBracket:{
                cout << "(";
                break;
            }
            case TokenType::RightBracket:{
                cout << ")";
                break;
            }
        }
    }
    cout << "\n";
    Queue outputQueue = shuntingYard(tokens);
    while(!outputQueue.isEmpty()){
        switch (outputQueue.front()->getType()){
            case TokenType::Number:{
                cout << (dynamic_cast<NumToken*>(outputQueue.front())->getCap())<< flush;
                outputQueue.dequeue();
                break;
            }
            case TokenType::Function:{
                cout << (dynamic_cast<FuncToken*>(outputQueue.front())->getCap())<< flush;
                outputQueue.dequeue();
                break;
            }
            case TokenType::Operator:{
                cout << (dynamic_cast<OperatorToken*>(outputQueue.front())->getCap())<< flush;
                outputQueue.dequeue();
                break;
            }
            case TokenType::LeftBracket:{
                cout << "(";
                outputQueue.dequeue();
                break;
            }
            case TokenType::RightBracket:{
                cout << ")";
                outputQueue.dequeue();
                break;
            }
        }
    }
    cout << "\n";
    outputQueue = shuntingYard(tokens);
    cout << calculation(outputQueue) << endl;
    return 0;
}