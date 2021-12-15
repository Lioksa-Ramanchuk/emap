#include "timetable.h"
#include <iostream>
using std::cin;
using std::cout;

void timetable()
{
    system("CLS");

    cout << "\n –асклад з€н€ткаҐ.\n";

    char answer;
    do
    {
        cout << "\n јб€рыце, на €к≥ дзень тыдн€ вывесц≥ расклад зан€ткаҐ:\n";
        cout << "  1 ЧЧ> пан€дзелак\n";
        cout << "  2 ЧЧ> аҐторак\n";
        cout << "  3 ЧЧ> серада\n";
        cout << "  4 ЧЧ> чацвер\n";
        cout << "  5 ЧЧ> п€тн≥ца\n";
        cout << "  6 ЧЧ> субота\n";
        cout << "  7 ЧЧ> на Ґвесь тыдзень\n";
        cout << "  8 ЧЧ> перайсц≥ Ґ галоҐнае меню\n";
        cout << "  9 ЧЧ> выйсц≥ з праграмы\n";

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
                cout << " Ќекарэктны Ґвод. ѕаспрабуйце €шчэ раз:\n";
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
        cout << " |                 |                                           «ан€тк≥                                           |\n";
        cout << " |     √адз≥ны     +----------------------------------------------+----------------------------------------------+\n";
        cout << " |                 |                  падгрупа 1                  |                  падгрупа 2                  |\n";
        cout << " +=================+==============================================+==============================================+\n";

        cout << TIMETABLES_FOR_DAYS[iDay];
    }
}