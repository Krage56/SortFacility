
#include "NumToken.h"


long long NumToken::getCap()  const{
    return atoll(_cap.c_str());
}

void NumToken::operator+=(std::string &str) {
    _cap += str;
}

NumToken::NumToken(std::string &str) {
    this->_type = TokenType::Number;
    _cap = str;
}


void GeneralNumToken::clear() {
    _cap = "";
}

std::string &GeneralNumToken::setCap() {
    return _cap;
}

FuncToken::FuncToken(std::string &str) {
    this->_type = TokenType::Function;
    _cap = str;
}

std::string FuncToken::getCap() const {
    return _cap;
}
