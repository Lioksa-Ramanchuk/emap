#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

#include <string>
#include <map>

const std::map<std::string, double> CONSTANTS
{
    { (std::string)"pi" , 3.141592653589793 },
    { (std::string)"e", 2.718281828459045 }
};

enum class eTokenValue {
    NUMBER, WORD, PRINT,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/', POW = '^', FACT = '!',
    LP = '(', RP = ')', LSP = '[', RSP = ']'
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

long double factorial(unsigned long long value);

#endif