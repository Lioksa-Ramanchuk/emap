#include "timetable.h"
#include <iostream>
using std::cin;
using std::cout;

void timetable()
{
    system("CLS");

    cout << "\n –асписание зан€тий на заданный день.\n";

    char answer;
    do
    {
        cout << "\n ¬ыберите, на какой день недели вывести расписание зан€тий:\n";
        cout << "  1 ЧЧ> понедельник\n";
        cout << "  2 ЧЧ> вторник\n";
        cout << "  3 ЧЧ> среда\n";
        cout << "  4 ЧЧ> четверг\n";
        cout << "  5 ЧЧ> п€тница\n";
        cout << "  6 ЧЧ> суббота\n";
        cout << "  7 ЧЧ> на всю неделю\n";
        cout << "  8 ЧЧ> перейти в главное меню\n";
        cout << "  9 ЧЧ> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
            case '8':
                return;
            case '9':
                exit(0);
            default:
                cout << " Ќекорректный ввод. ¬ведите ещЄ раз:\n";
                break;
            }
        } while ((answer < '1')||(answer > '9'));
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
        cout << "\n  " << WORKING_DAYS[iDay] << "\n";
        cout << " +=================+=============================================================================================+\n";
        cout << " |                 |                                           «ан€тие                                           |\n";
        cout << " |      „асы       +----------------------------------------------+----------------------------------------------+\n";
        cout << " |                 |                 подгруппа 1                  |                 подгруппа 2                  |\n";
        cout << " +=================+==============================================+==============================================+\n";

        cout << TIMETABLES_FOR_DAYS[iDay];
    }
}