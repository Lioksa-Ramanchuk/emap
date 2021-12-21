#include <iostream>
#include <vector>
#include "calc_exception.h"
#include "universal_expr_type.h"
using namespace std;

UniversalExprType::UniversalExprType()
{
    exprType = eExprType::NONE;
    value = 0.0;
}

UniversalExprType::UniversalExprType(double val)
{
    exprType = eExprType::NUMBER;
    value = val;
}


//====================================================================
//  ostream& operator<<(ostream& out, const UniversalExprType& EXPR)
//====================================================================

ostream& operator<<(ostream& out, const UniversalExprType& EXPR)
{
    if (EXPR.exprType == eExprType::NUMBER)
    {
        out << EXPR.value;
    }
    else if (EXPR.exprType == eExprType::VECTOR)
    {
        out << "{ ";
        
        const unsigned N_VALUES = EXPR.values.size();
        if (N_VALUES)
        {
            for (unsigned i = 0; i < N_VALUES - 1; i++) {
                out << EXPR.values[i] << ", ";
            }
            out << EXPR.values[N_VALUES - 1];
        }

        out << " }";
    }
    return out;
}


//====================================================================
//  UniversalExprType::operator-()
//====================================================================

UniversalExprType UniversalExprType::operator-()
{
    if (exprType == eExprType::NUMBER)
    {
        value *= -1;
    }
    else if (exprType == eExprType::VECTOR)
    {
        for (UniversalExprType& val : values) {
            val = -val;
        }
    }

    return *this;
}


//====================================================================
//  UniversalExprType::operator+(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator+(const UniversalExprType& RIGHT_EXPR)
{
    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        value += RIGHT_EXPR.value;
    }
    else if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(UniversalExprType(*this) + val);
        }

        value = 0.0;
        exprType = eExprType::VECTOR;
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : values) {
            val = val + RIGHT_EXPR;
        }
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = values.size();
        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга скласці вектары з рознай колькасцю каардынат");
        }

        for (unsigned i = 0; i < V_SIZE; i++) {
            values[i] = values[i] + RIGHT_EXPR.values[i];
        }
    }

    return *this;
}


//====================================================================
//  UniversalExprType::operator-(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator-(const UniversalExprType& RIGHT_EXPR)
{
    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        value -= RIGHT_EXPR.value;
    }
    else if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {

        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(UniversalExprType(*this) - val);
        }

        exprType = eExprType::VECTOR;
        value = 0.0;
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : values) {
            val = val - RIGHT_EXPR;
        }
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = values.size();

        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга знайсці рознасць вектароў з рознай колькасцю каардынат");
        }

        for (unsigned i = 0; i < V_SIZE; i++) {
            values[i] = values[i] - RIGHT_EXPR.values[i];
        }
    }

    return *this;
}


//====================================================================
//  UniversalExprType::operator*(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator*(const UniversalExprType& RIGHT_EXPR)
{
    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        value *= RIGHT_EXPR.value;
    }
    else if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(UniversalExprType(*this) * val);
        }

        value = 0.0;
        exprType = eExprType::VECTOR;
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : values) {
            val = val * RIGHT_EXPR;
        }
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = values.size();

        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга памножыць вектары з рознай колькасцю каардынат");
        }

        UniversalExprType result{ 0.0 };
        for (unsigned i = 0; i < V_SIZE; i++) {
            result = result + values[i] * RIGHT_EXPR.values[i];
        }

        *this = result;
    }

    return *this;
}


//====================================================================
//  UniversalExprType::operator/(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator/(const UniversalExprType& RIGHT_EXPR)
{
    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        value /= RIGHT_EXPR.value;
    }
    else if ((exprType == eExprType::VECTOR) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : values) {
            val = val / RIGHT_EXPR;
        }
    }
    else {
        throw CalcException("дзяліць можно толькі на лік");
    }

    return *this;
}


//====================================================================
//  operator string()
//====================================================================

UniversalExprType::operator string()
{
    string str = "";
    if (exprType == eExprType::NUMBER)
    {
        str = to_string(value);
    }
    else if (exprType == eExprType::VECTOR)
    {
        str += "{ ";

        const unsigned N_VALUES = values.size();
        if (N_VALUES)
        {
            for (unsigned i = 0; i < N_VALUES - 1; i++) {
                str += values[i] + ',' + ' ';
            }
            str += values[N_VALUES - 1];
        }

        str += " }";
    }

    return str;
}