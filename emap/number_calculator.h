#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

#include <map>
#include <string>
#include "universal_expr_type.h"

const std::map<std::string, double> CONSTANTS
{
    { (std::string)"pi" , 3.141592653589793 },
    { (std::string)"e", 2.718281828459045 }
};

const double MAX_VALUE_FOR_FACTORIAL = 150.0;

void numberCalculator();

long double factorial(unsigned long long value);

#endif