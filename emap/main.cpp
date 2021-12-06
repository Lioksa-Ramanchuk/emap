#include "bin_dec_converter.h"  // Перевод числа из двоичной системы счисления в десятичную и наоборот
#include "string_calculator.h"  // Калькулятор для работы со строками
#include "test_func1.h"         // пример функции (в релизе не будет)
#include "test_func2.h"         // пример функции (в релизе не будет)

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    system("chcp 1251 > nul");  // Для поддержки Windows-1251

    // Главное меню
    char answer;
    do
    {
        cout << "\n Выберите вариант использования программы:\n";
        cout << "  1 ——————> перевести число из двоичной системы счисления в десятичную и наоборот\n";
        cout << "  2 ——————> калькулятор для работы со строками\n";
        cout << "  3 ——————> ещё не реализовано\n";
        cout << "  4 ——————> ещё не реализовано\n";
        cout << "  5 ——————> ещё не реализовано\n";
        cout << "  6 ——————> ещё не реализовано\n";
        cout << "  7 ——————> func1 (пример, в релизе не будет)\n";      // В релизе этого варианта не будет
        cout << "  8 ——————> func2 (пример, в релизе не будет)\n";      // В релизе этого варианта не будет
        cout << "  E(X)IT —> выйти из программы\n";

        do
        {
            cin >> answer;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case '1': binDecConverter();
                break;
            case '2': stringCalculator();
                break;
            case '3':; // Вставьте сюда свою основную функцию
                break;
            case '4':; // Вставьте сюда свою основную функцию
                break;
            case '5':; // Вставьте сюда свою основную функцию
                break;
            case '6':; // Вставьте сюда свою основную функцию
                break;
            case '7': testFunc1();  // Пример, в релизе не будет
                break;
            case '8': testFunc2();  // Пример, в релизе не будет
                break;
            case 'X':
                break;
            default:
                cout << " Некорректный ввод. Введите ещё раз.\n";
                break;
            }
                                 // (answer > '6'), когда уберём варианты примеров
        } while (((answer < '1') || (answer > '8')) && (answer != 'X'));
    } while (answer != 'X');

    return 0;
}