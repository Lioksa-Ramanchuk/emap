#ifndef CALC_EXCEPTION
#define CALC_EXCEPTION

#include <string>

class CalcException
{
private:
    std::string exceptionMessage;

public:
    CalcException(std::string calcError);

    const char* what();
};

#endif
