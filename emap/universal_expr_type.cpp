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
        value = 0.0;
        exprType = eExprType::VECTOR;

        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(*this + val);
        }
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
        value = 0.0;
        exprType = eExprType::VECTOR;

        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(*this - val);
        }
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
//  UniversalExprType::operator-(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator*(const UniversalExprType& RIGHT_EXPR)
{
    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        value *= RIGHT_EXPR.value;
    }
    else if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        value = 0.0;
        exprType = eExprType::VECTOR;

        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            values.push_back(*this * val);
        }
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