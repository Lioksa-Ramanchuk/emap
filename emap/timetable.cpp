#include <iostream>
#include "timetable.h"

using std::cin;
using std::cout;

void timetable()
{
    system("CLS");

    cout << "\n Расклад зяняткаў.\n";

    int choice = 0;
    std::string choiceInput = "";

    while (true)
    {
        cout << "\n Абярыце, на які дзень тыдня вывесці расклад заняткаў:\n";
        cout << "  1 ——> панядзелак\n";
        cout << "  2 ——> аўторак\n";
        cout << "  3 ——> серада\n";
        cout << "  4 ——> чацвер\n";
        cout << "  5 ——> пятніца\n";
        cout << "  6 ——> субота\n";
        cout << "  7 ——> на ўвесь тыдзень\n";
        cout << "  8 ——> перайсці ў галоўнае меню\n";
        cout << "  9 ——> выйсці з праграмы\n";

        while (true)
        {
            getline(cin, choiceInput);

            try
            {
                for (char ch : choiceInput)
                {
                    if (!isdigit(ch)) {
                        throw std::out_of_range("выбар павінен быць цэлым лікам");
                    }
                }

                choice = stoi(choiceInput);

                if ((choice < 1) || (choice > 9)) {
                    throw std::out_of_range("выбар павінен быць ад 1 да 9");
                }

                break;
            }
            catch (...) {
                cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
            }
        }

        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            showTimetable(choice - 1);
            break;
        case 8:
            return;
        case 9:
            exit(0);
        default:
            cout << "Вы не павінны бачыць гэты радок.\n";
            break;
        }
    }
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
        cout << " |                 |                                           Заняткі                                           |\n";
        cout << " |     Гадзіны     +----------------------------------------------+----------------------------------------------+\n";
        cout << " |                 |                  падгрупа 1                  |                  падгрупа 2                  |\n";
        cout << " +=================+==============================================+==============================================+\n";

        cout << TIMETABLES_FOR_DAYS[iDay];
    }
}