#include "test_func1.h"
#include <iostream>
using namespace std;

void testFunc1()
{
    char answer;
    do
    {
        cout << "\n Что-то происходит.\n";  // Тут выполняется главная задача функции

        cout << "\n Выберите:\n";
        cout << "  (D)O SMTH —> сделать что-нибудь\n";
        cout << "  (M)ENU ————> перейти в главное меню\n";
        cout << "  E(X)IT ————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'D':
                break;
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