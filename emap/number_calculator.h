#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

#include <string>

enum class eTokenValue {
    NAME, NUMBER, END,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};

void numberCalculator();
double expr(bool get);
double term(bool get);
double prim(bool get);
eTokenValue getToken();
int error(const std::string& s);

#endif