#include "current_date_time.h"
#include <ctime>
#include <cstdio>
#include <iostream>

void currentDateTime()
{
    std::cout << "\n Текущая дата и время:\n\n";

    time_t output = time(NULL);
    char str[30];
    ctime_s(str, sizeof str, &output);
    printf(" %s", str);
}