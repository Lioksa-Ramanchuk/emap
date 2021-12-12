#include "timetable.h"
#include <iostream>
using namespace std;

void timetable()
{
    system("CLS");

    cout << "\n Расписание занятий на заданный день.\n";

    char answer;
    do
    {
        cout << "\n Выберите, на какой день недели вывести расписание занятий:\n";
        cout << "  1 ——————> понедельник\n";
        cout << "  2 ——————> вторник\n";
        cout << "  3 ——————> среда\n";
        cout << "  4 ——————> четверг\n";
        cout << "  5 ——————> пятница\n";
        cout << "  6 ——————> суббота\n";
        cout << "  7 ——————> на всю неделю\n";
        cout << "  (M)ENU —> перейти в главное меню\n";
        cout << "  E(X)IT —> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                showTimetable(answer - '0' - 1);
                break;
            case 'M':
                return;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer < '1')||(answer > '7'));
    } while (true);
}

void showTimetable(unsigned day)
{
    int iDay = 0, iDaysCount = 0;

    if (day < WORKING_DAYS_NUMBER)
    {
        iDay = day;
        iDaysCount = iDay + 1;
    }
    else
    {
        iDay = 0;
        iDaysCount = WORKING_DAYS_NUMBER;
    }
    
    for (; iDay < iDaysCount; iDay++)
    {
        cout << "\n  " << WORKING_DAYS[iDay] << '\n';
        cout << " +-----------------+---------------------------------------+\n";
        cout << " |                 |                Занятие                |\n";
        cout << " |      Часы       +-------------------+-------------------+\n";
        cout << " |                 |    подгруппа 1    |    подгруппа 2    |\n";
        cout << " +-----------------+-------------------+-------------------+\n";

        cout << TIMETABLES_FOR_DAYS[iDay];
    }
}