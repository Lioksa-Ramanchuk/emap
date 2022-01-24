#ifndef UNIVERSAL_EXPR_TYPE
#define UNIVERSAL_EXPR_TYPE

#include <vector>

enum class eExprType
{
    NONE, NUMBER, VECTOR, MATRIX
};

class UniversalExprType
{
public:
    UniversalExprType();
    UniversalExprType(double val);

    eExprType exprType;
    double value;
    std::vector<UniversalExprType> values;

    void fillMatrix();

    friend std::ostream& operator<<(std::ostream& out, const UniversalExprType& EXPR);

    UniversalExprType operator-();
    UniversalExprType operator+(const UniversalExprType& RIGHT_EXPR);
    UniversalExprType operator-(const UniversalExprType& RIGHT_EXPR);
    UniversalExprType operator*(const UniversalExprType& RIGHT_EXPR);
    UniversalExprType operator/(const UniversalExprType& RIGHT_EXPR);

    operator std::string();
};

#endif