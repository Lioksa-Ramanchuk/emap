#include <string>
#include "calc_exception.h"

CalcException::CalcException(std::string calcError)
    : exceptionMessage(calcError)
{
}

const char* CalcException::what()
{
    return exceptionMessage.c_str();
}