#include "current_date_time.h"
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>

void currentDateTime()
{
    using std::cout;

    system("CLS");

    cout << "\n √адз≥нн≥к.\n";
    cout << " ƒл€ пераходу Ґ галоҐнае меню нац≥сн≥це любую клав≥шу.\n";

    cout << "\n Ѕ€гуча€ дата ≥ час:\n";

    time_t now;
    tm timeinfo;

    while (!_kbhit())
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
    _getch();
    cout << '\n';
}