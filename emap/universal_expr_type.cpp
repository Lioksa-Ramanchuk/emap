#include <iostream>
#include <vector>
#include "calc_exception.h"
#include "universal_expr_type.h"

using std::vector;

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
//  void UniversalExprType::fillMatrix()
//====================================================================

void UniversalExprType::fillMatrix()
{
    if (exprType == eExprType::MATRIX)
    {
        unsigned rowLength = 0;
        unsigned maxRowLength = 0;
        
        for (UniversalExprType& row : values)
        {
            rowLength = row.values.size();

            if (rowLength > maxRowLength) {
                maxRowLength = rowLength;
            }
        }

        for (UniversalExprType& row : values)
        {
            row.values.resize(maxRowLength, 0);
        }
    }
}


//====================================================================
//  ostream& operator<<(ostream& out, const UniversalExprType& EXPR)
//====================================================================

std::ostream& operator<<(std::ostream& out, const UniversalExprType& EXPR)
{
    switch (EXPR.exprType)
    {
    case eExprType::NUMBER:
    {
        out << EXPR.value;

        break;
    }
    case eExprType::VECTOR:
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

        break;
    }
    case eExprType::MATRIX:
    {
        UniversalExprType expr = EXPR;

        expr.fillMatrix();

        out << "[ ";

        const unsigned N_ROWS = expr.values.size();

        if (N_ROWS)
        {
            for (unsigned i = 0; i < N_ROWS - 1; i++) {
                out << expr.values[i] << ", ";
            }
            out << expr.values[N_ROWS - 1];
        }

        out << " ]";

        break;
    }
    }
    
    return out;
}


//====================================================================
//  UniversalExprType::operator-()
//====================================================================

UniversalExprType UniversalExprType::operator-()
{
    UniversalExprType result = *this;

    switch (result.exprType)
    {
    case eExprType::NUMBER:
    {
        result.value *= -1;

        break;
    }
    case eExprType::VECTOR:
    {
        for (UniversalExprType& val : result.values) {
            val = -val;
        }

        break;
    }
    case eExprType::MATRIX:
    {
        result.fillMatrix();

        for (UniversalExprType& val : result.values) {
            val = -val;
        }

        break;
    }
    }

    return result;
}


//====================================================================
//  UniversalExprType::operator+(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator+(const UniversalExprType& RIGHT_EXPR)
{
    UniversalExprType result = *this;

    if ((result.exprType == eExprType::NUMBER) &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.value += RIGHT_EXPR.value;
    }
    else if ((result.exprType == eExprType::NUMBER)
        && 
        ((RIGHT_EXPR.exprType == eExprType::VECTOR) ||
         (RIGHT_EXPR.exprType == eExprType::MATRIX)))
    {
        result.values = RIGHT_EXPR.values;
        result.exprType = RIGHT_EXPR.exprType;
        result.fillMatrix();
        
        for (UniversalExprType& val : result.values) {
            val = val + (UniversalExprType)result.value;
        }

        result.value = 0.0;
    }
    else if (((result.exprType == eExprType::VECTOR) ||
              (result.exprType == eExprType::MATRIX))
        &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.fillMatrix();

        for (UniversalExprType& val : result.values) {
            val = val + RIGHT_EXPR;
        }
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = values.size();

        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга скласц≥ вектары з рознай колькасцю каардынат");
        }

        for (unsigned i = 0; i < V_SIZE; i++) {
            result.values[i] = result.values[i] + RIGHT_EXPR.values[i];
        }
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        throw CalcException("нельга скласц≥ вектар ≥ матрыцу");
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        throw CalcException("нельга скласц≥ матрыцу ≥ вектар");
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        const unsigned N_ROWS = result.values.size();

        if (N_ROWS != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга скласц≥ матрыцы з рознай памернасцю");
        }

        result.fillMatrix();
        
        unsigned nCols = 0;
        
        if (N_ROWS) {
            nCols = result.values[0].values.size();
        }

        unsigned nRightCols = 0;
        unsigned maxNRightCols = 0;

        for (const UniversalExprType& RIGHT_ROW : RIGHT_EXPR.values)
        {
            nRightCols = RIGHT_ROW.values.size();

            if (nRightCols > maxNRightCols) {
                maxNRightCols = nRightCols;
            }
        }

        if (nCols != maxNRightCols) {
            throw CalcException("нельга скласц≥ матрыцы з рознай памернасцю");
        }

        for (unsigned iRow = 0; iRow < N_ROWS; iRow++)
        {
            nRightCols = RIGHT_EXPR.values[iRow].values.size();

            for (unsigned jCol = 0; jCol < nRightCols; jCol++)
            {
                result.values[iRow].values[jCol] = result.values[iRow].values[jCol] + RIGHT_EXPR.values[iRow].values[jCol];
            }
        }
    }

    return result;
}


//====================================================================
//  UniversalExprType::operator-(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator-(const UniversalExprType& RIGHT_EXPR)
{
    UniversalExprType result = *this;

    if ((result.exprType == eExprType::NUMBER) &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.value -= RIGHT_EXPR.value;
    }
    else if ((result.exprType == eExprType::NUMBER)
        && 
        ((RIGHT_EXPR.exprType == eExprType::VECTOR) ||
         (RIGHT_EXPR.exprType == eExprType::MATRIX)))
    {
        result.values = RIGHT_EXPR.values;
        result.exprType = RIGHT_EXPR.exprType;
        result.fillMatrix();
        
        for (UniversalExprType& val : result.values) {
            val = -val + (UniversalExprType)result.value;
        }

        result.value = 0.0;
    }
    else if (((exprType == eExprType::VECTOR) ||
              (exprType == eExprType::MATRIX))
        &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.fillMatrix();

        for (UniversalExprType& val : result.values) {
            val = val - RIGHT_EXPR;
        }
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = values.size();

        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга знайсц≥ рознасць вектароҐ з рознай колькасцю каардынат");
        }

        for (unsigned i = 0; i < V_SIZE; i++) {
            result.values[i] = result.values[i] - RIGHT_EXPR.values[i];
        }
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        throw CalcException("нельга адн€ць ад вектара матрыцу");
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        throw CalcException("нельга адн€ць ад матрыцы вектар");
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        const unsigned N_ROWS = result.values.size();

        if (N_ROWS != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга знайсц≥ рознасць матрыц з рознай памернасцю");
        }

        result.fillMatrix();

        unsigned nCols = 0;

        if (N_ROWS) {
            nCols = result.values[0].values.size();
        }

        unsigned nRightCols = 0;
        unsigned maxNRightCols = 0;

        for (const UniversalExprType& RIGHT_ROW : RIGHT_EXPR.values)
        {
            nRightCols = RIGHT_ROW.values.size();

            if (nRightCols > maxNRightCols) {
                maxNRightCols = nRightCols;
            }
        }

        if (nCols != maxNRightCols) {
            throw CalcException("нельга знайсц≥ рознасць матрыц з рознай памернасцю");
        }

        for (unsigned iRow = 0; iRow < N_ROWS; iRow++)
        {
            nRightCols = RIGHT_EXPR.values[iRow].values.size();

            for (unsigned jCol = 0; jCol < nRightCols; jCol++)
            {
                result.values[iRow].values[jCol] = result.values[iRow].values[jCol] - RIGHT_EXPR.values[iRow].values[jCol];
            }
        }
    }

    return result;
}


//====================================================================
//  UniversalExprType::operator*(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator*(const UniversalExprType& RIGHT_EXPR)
{
    UniversalExprType result = *this;

    if ((result.exprType == eExprType::NUMBER) &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.value *= RIGHT_EXPR.value;
    }
    else if ((result.exprType == eExprType::NUMBER)
        &&
        ((RIGHT_EXPR.exprType == eExprType::VECTOR) ||
            (RIGHT_EXPR.exprType == eExprType::MATRIX)))
    {
        for (const UniversalExprType& val : RIGHT_EXPR.values) {
            result.values.push_back(UniversalExprType(*this) * val);
        }

        result.value = 0.0;
        result.exprType = RIGHT_EXPR.exprType;

        result.fillMatrix();
    }
    else if (((result.exprType == eExprType::VECTOR) ||
              (result.exprType == eExprType::MATRIX))
        &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : result.values) {
            val = val * RIGHT_EXPR;
        }

        result.fillMatrix();
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        const unsigned V_SIZE = result.values.size();

        if (V_SIZE != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга памножыць вектары з рознай колькасцю каардынат");
        }

        UniversalExprType resultVal{ 0.0 };

        for (unsigned i = 0; i < V_SIZE; i++) {
            resultVal = resultVal + result.values[i] * RIGHT_EXPR.values[i];
        }
        result = resultVal;
    }
    else if ((result.exprType == eExprType::VECTOR) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        if (result.values.size() != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга памножыць вектар на матрыцу (колькасць каардынат вектара не супадае з колькасцю радкоҐ матырцы)");
        }

        result.exprType = eExprType::MATRIX;

        result = result * RIGHT_EXPR;
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::VECTOR))
    {
        result.fillMatrix();

        unsigned nCols = 0;
        if (result.values.size()) {
            nCols = values[0].values.size();
        }

        if (nCols != RIGHT_EXPR.values.size()) {
            throw CalcException("нельга памножыць матрыцу на вектар (колькасць слупкоҐ матрыцы не супадае з колькасцю каардынат вектара)");
        }

        for (UniversalExprType& leftRow : result.values)
        {
            UniversalExprType resultRow{ 0.0 };
            resultRow.exprType = eExprType::VECTOR;

            resultRow.values.push_back(leftRow * RIGHT_EXPR);

            leftRow = resultRow;
        }
    }
    else if ((result.exprType == eExprType::MATRIX) &&
        (RIGHT_EXPR.exprType == eExprType::MATRIX))
    {
        UniversalExprType rightExpr = RIGHT_EXPR;
        
        result.fillMatrix();
        rightExpr.fillMatrix();

        unsigned nLeftRows = result.values.size();

        unsigned nLeftCols = 0;
        if (nLeftRows) {
            nLeftCols = result.values[0].values.size();
        }

        if (nLeftCols != rightExpr.values.size()) {
            throw CalcException("нельга памножыць матрыцу на матрыцу (колькасць слупкоҐ першай матрыцы не супадае з колькасцю радкоҐ другой)");
        }

        unsigned nRightCols = 0;
        if (rightExpr.values.size()) {
            nRightCols = rightExpr.values[0].values.size();
        }

        UniversalExprType resultMatrix{ 0.0 };
        resultMatrix.exprType = eExprType::MATRIX;

        UniversalExprType resultRow{ 0.0 };
        resultRow.exprType = eExprType::VECTOR;

        UniversalExprType resultVal{ 0.0 };

        for (unsigned iRow = 0; iRow < nLeftRows; iRow++)
        {
            resultRow.exprType = eExprType::VECTOR;
            resultRow.values.clear();
            
            for (unsigned jCol = 0; jCol < nRightCols; jCol++)
            {
                resultVal.exprType = eExprType::NUMBER;
                resultVal.values.clear();
                resultVal.value = 0.0;

                for (unsigned i = 0; i < nLeftCols; i++)
                {
                    resultVal = resultVal + result.values[iRow].values[i] * rightExpr.values[i].values[jCol];
                }

                resultRow.values.push_back(resultVal);
            }

            resultMatrix.values.push_back(resultRow);
        }

        result = resultMatrix;
    }

    return result;
}


//====================================================================
//  UniversalExprType::operator/(const UniversalExprType& RIGHT_EXPR)
//====================================================================

UniversalExprType UniversalExprType::operator/(const UniversalExprType& RIGHT_EXPR)
{
    UniversalExprType result = *this;

    if ((exprType == eExprType::NUMBER) && (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        result.value /= RIGHT_EXPR.value;
    }
    else if (((result.exprType == eExprType::VECTOR) ||
              (result.exprType == eExprType::MATRIX))
        &&
        (RIGHT_EXPR.exprType == eExprType::NUMBER))
    {
        for (UniversalExprType& val : result.values) {
            val = val / RIGHT_EXPR;
        }

        result.fillMatrix();
    }
    else {
        throw CalcException("дз€л≥ць можна тольк≥ на л≥к");
    }

    return result;
}


//====================================================================
//  operator string()
//====================================================================

UniversalExprType::operator std::string()
{
    std::string str = "";

    switch (exprType)
    {
    case eExprType::NUMBER:
    {
        str = std::to_string(value);

        break;
    }
    case eExprType::VECTOR:
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

        break;
    }
    case eExprType::MATRIX:
    {
        fillMatrix();

        str += "[ ";

        const unsigned N_ROWS = values.size();

        if (N_ROWS)
        {
            for (unsigned i = 0; i < N_ROWS - 1; i++) {
                str += values[i] + ',' + ' ';
            }
            str += values[N_ROWS - 1];
        }

        str += " ]";

        break;
    }
    }

    return str;
}