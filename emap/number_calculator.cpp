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
        cout << "  1 ——> вычислить значение арифметического выражения\n";
        cout << "  2 ——> перейти в главное меню\n";
        cout << "  3 ——> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (answer)
            {
            case '1':
                cout << "\n Введите арифметическое выражение:\n";
                // Сюда вставь цикл while из main
                break;
            case '2':
                return;
            case '3':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '3'));
    } while (true);
}

// Сюда вставь реализацию всех функций