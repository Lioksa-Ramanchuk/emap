#include "current_date_time.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

void currentDateTime()
{
    using std::cout;

    system("CLS");

    cout << "\n ����: ����� �������� �������.\n";
    cout << " ��� ������ � ������� ���� ������� Esc\n";
    cout << "\n ������� ���� � �����:\n";

    struct tm timeinfo;
    time_t now;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        now = time(NULL);
        localtime_s(&timeinfo, &now);

        cout << ("\r                      \r");
        cout << " " << timeinfo.tm_year + 1900;
        cout << "." << std::setw(2) << std::setfill('0') << timeinfo.tm_mon + 1;
        cout << "." << std::setw(2) << std::setfill('0') << timeinfo.tm_mday;
        cout << " " << std::setw(2) << std::setfill('0') << timeinfo.tm_hour;
        cout << ":" << std::setw(2) << std::setfill('0') << timeinfo.tm_min;
        cout << ":" << std::setw(2) << std::setfill('0') << timeinfo.tm_sec;

        Sleep(250);
    }
    cout << '\n';
}