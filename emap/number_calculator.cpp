#include "number_calculator.h"
#include <iostream>
// Добавь сюда нужные #include
using namespace std;

void numberCalculator()
{
    system("CLS");

    cout << "\n Числовой калькулятор.\n";
    cout << " Вычисляет значение введённого арифметического выражения.\n";
    cout << " Поддерживает использование в выражении операторов + , -, *, / , () с корректным порядком вычислений.\n";
    cout << " Поддерживает использование в выражении констант pi и e.\n";
    cout << " Пример:\n";
    cout << "         выражение: 2.5 + (3 - 4 * 5)/17\n";
    cout << "         результат: 1.5\n";

    // Сюда вставь pi и e из main

    char answer;
    do
    {
        cout << "\n Выберите:\n";
        cout << "  (C)ALCULATE —> вычислить значение арифметического выражения\n";
        cout << "  (M)ENU ——————> перейти в главное меню\n";
        cout << "  E(X)IT ——————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'C':
                cout << "\n Введите арифметическое выражение:\n";
                // Сюда вставь цикл while из main
                break;
            case 'M':
                return;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while (answer != 'C');
    } while (true);
}

// Сюда вставь реализацию всех функций