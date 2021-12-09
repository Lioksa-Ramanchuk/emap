#include <time.h>
#include <stdio.h>
#include "current_date_time.h"
#include <iostream>

int current_date_time(void)
{
    using namespace std;
    char answer;
    do
    {
        cout << "\n Выведение текущей даты и времени.\n";  // Тут выполняется главная задача функции

        cout << "\n Выберите:\n";
        cout << "  (D)O —> вызвать функцию\n";
        cout << "  (M)ENU ————> перейти в главное меню\n";
        cout << "  E(X)IT ————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'D':
            {
                time_t output = time(NULL);
                char str[30];
                ctime_s(str, sizeof str, &output);
                printf("%s", str);
            }
            case 'M':
                break;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer != 'D') && (answer != 'M') && (answer != 'X'));
    } while (answer != 'M');
}