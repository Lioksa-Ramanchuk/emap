#include "number_calculator.h"  // Калькулятор для работы с числами                                     | by Никита Каребо
#include "string_calculator.h"  // Калькулятор для работы со строками                                   | by Владислав Горощеня
#include "current_date_time.h"  // Часы: вывод текущего времени                                         | by Олег Точило
#include "timetable.h"          // Расписание занятий на заданный день                                  | by Максим Ружицкий
#include "bin_dec_converter.h"  // Перевод числа из двоичной системы счисления в десятичную и наоборот  | by Алексей Романчук
#include "caesar_cipher.h"      // Шифратор-дешифратор Цезаря                                           | by Алексей Романчук

#include <iostream>
#define NOMINMAX
#include <Windows.h>

int main()
{
    using std::cout;
    using std::cin;

    system("chcp 1251 > nul");  // Для поддержки Windows-1251

    // Главное меню

    char answer;
    do
    {
        system("CLS");
        cout << "\n Главное меню.\n";

        cout << "\n Выберите вариант использования программы:\n";
        cout << "  1 ———————> калькулятор для работы с числами\n";
        cout << "  2 ———————> калькулятор для работы со строками\n";
        cout << "  3 ———————> часы: вывод текущего времени\n";
        cout << "  4 ———————> расписание занятий на заданный день\n";
        cout << "  5 ———————> конвертер чисел из двоичной системы счисления в десятичную и наоборот\n";
        cout << "  6 ———————> напоминалка\n";
        cout << "  7 ———————> шифратор-дешифратор Цезаря\n";             // Дополнительное задание
        cout << "  (A)BOUT —> открыть сайт проекта с документацией\n";
        cout << "  E(X)IT ——> выйти из программы\n";

        do
        {
            cin >> answer;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case '1': numberCalculator();   //                             - НИКИТА КАРЕБО
                break;
            case '2': stringCalculator(); //                               - ВЛАД ГОРОЩЕНЯ
                break;
            case '3': currentDateTime(); //                                - ОЛЕГ ТОЧИЛО
                break;
            case '4': timetable();  //                                     - МАКСИМ РУЖИЦКИЙ
                break;
            case '5': binDecConverter(); //                                - АЛЕКСЕЙ РОМАНЧУК
                break;
            case '6':; // функция: напоминалка                             - ИЛЬЯ ТИХОМИРОВ
                break;
            case '7': caesarCipher(); //                                   - АЛЕКСЕЙ РОМАНЧУК
                break;
            case 'A': ShellExecuteA(GetConsoleWindow(), "open", "..\\emap.html", NULL, NULL, SW_SHOWDEFAULT);
                break;
            case 'X':
                break;
            default:
                cout << " Некорректный ввод. Введите ещё раз.\n";
                break;
            }
        } while (((answer < '1') || (answer > '7')) && (answer != 'A') && (answer != 'X'));
    } while (answer != 'X');

    return 0;
}