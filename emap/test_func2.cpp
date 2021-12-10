#include "test_func2.h"
#include <iostream>
using namespace std;

void testFunc2()
{
    system("CLS");

    char answer;
    do
    {
        cout << "\n Выберите:\n";
        cout << "  (D)O SMTH ——————> сделать что-нибудь\n";
        cout << "  DO SMTH (E)LSE —> сделать что-нибудь другое\n";
        cout << "  (M)ENU —————————> перейти в главное меню\n";
        cout << "  E(X)IT —————————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'D': doSomething();
                break;
            case 'E': doSomethingElse();
                break;
            case 'M':
                break;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer != 'D') && (answer != 'E') && (answer != 'M') && (answer != 'X'));
    } while (answer != 'M');
}

void doSomething()
{
    cout << "\n Что-то происходит.\n";          // Тут выполняется подзадача функции
}

void doSomethingElse()
{
    cout << "\n Происходит что-то другое.\n";   // Тут выполняется другая подзадача функции
}