#ifndef NUMBER_CALCULATOR_H
#define NUMBER_CALCULATOR_H

void numberCalculator();
enum Token_value;
double expr(bool get);
double term(bool get);
double number_value;
double string_value;
double prim(bool get);
Token_value get_token();
int error(const string& s);

#endif