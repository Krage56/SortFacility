
#ifndef SORTSTATION_GENERALTOKEN_H
#define SORTSTATION_GENERALTOKEN_H


enum struct TokenType{
    Number = 0,
    Function,
    Operator,
    LeftBracket,
    RightBracket
};
class GeneralToken{
public:
    TokenType getType(){ return _type;};
    virtual ~GeneralToken()= default;
protected:
    TokenType _type;
};
#endif

