#include "current_date_time.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

void currentDateTime()
{
    using std::cout;

    system("CLS");

    cout << "\n Часы: вывод текущего времени.\n";
    cout << " Для выхода в главное меню нажмите Esc\n";

    cout << "\n Текущая дата и время:\n";

    time_t now;
    struct tm timeinfo;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        now = time(NULL);
        localtime_s(&timeinfo, &now);

        cout << ("\r                      \r");
        cout << " " << std::setw(2) << std::setfill('0') << timeinfo.tm_mday;
        cout << "." << std::setw(2) << std::setfill('0') << timeinfo.tm_mon + 1;
        cout << "." << timeinfo.tm_year + 1900;
        cout << " " << std::setw(2) << std::setfill('0') << timeinfo.tm_hour;
        cout << ":" << std::setw(2) << std::setfill('0') << timeinfo.tm_min;
        cout << ":" << std::setw(2) << std::setfill('0') << timeinfo.tm_sec;

        Sleep(1000);
    }
    cout << '\n';
}