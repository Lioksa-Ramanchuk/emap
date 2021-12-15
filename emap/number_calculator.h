#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

#include <string>

enum class eTokenValue {
    NUMBER, PRINT,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/', POW = '^',
    LP = '(', RP = ')'
};

class CalcException
{
private:
    std::string exceptionMessage;
    
public:
    CalcException(std::string calcError)
        : exceptionMessage(calcError)
    {
    }

    const char* what() { return exceptionMessage.c_str(); }
};

void numberCalculator();
double expr(bool get);
double term(bool get);
double prim(bool get);
eTokenValue getToken();

#endif