//
// Created by krage56 on 21.04.2020.
//

#ifndef SORTSTATION_BRACKETS_H
#define SORTSTATION_BRACKETS_H

#include "GeneralToken.h"

class Brackets:virtual public GeneralToken {
public:Brackets(TokenType type = TokenType::LeftBracket);
};


#endif //SORTSTATION_BRACKETS_H
