#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

#include <string>

enum class eTokenValue {
    ERR_SYMBOL, NUMBER, PRINT,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    LP = '(', RP = ')'
};

void numberCalculator();
double expr(bool get);
double term(bool get);
double prim(bool get);
eTokenValue getToken();

#endif