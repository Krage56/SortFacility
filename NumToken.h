//
// Created by krage56 on 21.04.2020.
//

#ifndef SORTSTATION_NUMTOKEN_H
#define SORTSTATION_NUMTOKEN_H

#include <string>
#include "GeneralToken.h"

class GeneralNumToken: /*virtual*/ public GeneralToken {
public:
    void clear();
    std::string& setCap();
    ~GeneralNumToken(){};
protected:
    std::string _cap;
};

class NumToken: /*virtual*/ public GeneralNumToken{
public:
    explicit NumToken(std::string& str);
    double getCap() const;
    void operator+=(std::string&);
    ~NumToken()= default;
};

class FuncToken: virtual public GeneralNumToken{
public:
    explicit FuncToken(std::string&);
    std::string getCap() const;
    ~FuncToken()= default;
};
#endif //SORTSTATION_NUMTOKEN_H
