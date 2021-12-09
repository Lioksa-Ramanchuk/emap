#include "bin_dec_converter.h"
#include <iostream>
#include <string>
using namespace std;

void binDecConverter()
{
    system("CLS");
    cout << "\n Конвертер двоичных чисел в десятичные и наоборот.\n";

    char answer;
    do
    {

        cout << "\n Выберите:\n";
        cout << "  (B)IN to DEC —> перевести число из двоичной системы счисления в десятичную\n";
        cout << "  (D)EC to BIN —> перевести число из десятичной системы счисления в двоичную\n";
        cout << "  (M)ENU ———————> перейти в главное меню\n";
        cout << "  E(X)IT ———————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'B': convertBinToDec();
                break;
            case 'D': convertDecToBin();
                break;
            case 'M':
                return;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer != 'B') && (answer != 'D'));
    } while (true);
}

void convertBinToDec()
{
    string binNumberInput = "";
    double decNumber = 0.0;

    int binNumberInputLength = 0;
    int dotPos = 0;                     // Позиция точки/запятой в числе
    bool binNumberIsPositive = true;
    bool binNumberHasDots = false;
    bool inputIsOK = true;

    cout << "\n Введите число в двоичной системе счисления:\n";

    do
    {
        getline(cin, binNumberInput);
        binNumberInputLength = binNumberInput.length();
        binNumberIsPositive = true;
        inputIsOK = true;

        if (binNumberInput[0] == '-')                       // Если двоичное число отрицательное
        {
            binNumberIsPositive = false;
            binNumberInput.erase(binNumberInput.begin());
            binNumberInputLength--;
        }
        else if (binNumberInput[0] == '+')                  // Если двоичное число явно положительное
        {
            binNumberInput.erase(binNumberInput.begin());
            binNumberInputLength--;
        }
        binNumberHasDots = false;
        dotPos = binNumberInputLength;

        for (int i = binNumberInputLength - 1; i >= 0; i--)
        {
            if ((binNumberInput[i] == '.') || (binNumberInput[i] == ','))
            {
                if (binNumberHasDots)
                {
                    inputIsOK = false;
                    break;
                }
                else
                {
                    binNumberHasDots = true;
                    dotPos = i;
                }
            }
            else if (!((binNumberInput[i] == '0') || (binNumberInput[i] == '1')))
            {
                inputIsOK = false;
                break;
            }
        }

        if (!inputIsOK) {
            cout << " Некорректный ввод. Введите ещё раз:\n";
        }
    } while (!inputIsOK);

    try
    {
        // Перевод целой части числа
        for (int i = 0; i < dotPos; i++)
        {
            if (binNumberInput[i] == '1') {
                decNumber += pow(2, dotPos - 1 - i);
            }
        }
        // Перевод дробной части числа
        for (int i = dotPos + 1; i < binNumberInputLength; i++)
        {
            if (binNumberInput[i] == '1') {
                decNumber += pow(2, dotPos - i);
            }
        }
        if (!binNumberIsPositive) {
            decNumber *= -1;
        }

        cout << " Число в десятичной системе счисления: " << decNumber << endl;
    }
    catch (const exception& err)
    {
        cerr << " Что-то пошло не так.\n";
        cerr << " Ошибка: " << typeid(err).name() << ": " << err.what() << '\n';
    }
}

void convertDecToBin()
{
    string decNumberInput = "";
    string binNumber = "";

    int decNumberInputLength = 0;
    int dotPos = 0;
    double integerPartOfDec = 0;        // Целая часть числа (тип double для большего диапазона значений)
    double fractionPartOfDec = 0;       // Дробная часть числа
    bool decNumberIsPositive = true;
    bool decNumberHasDots = false;
    bool inputIsOK = true;

    cout << "\n Введите число в десятичной системе счисления:\n";

    do
    {
        getline(cin, decNumberInput);
        decNumberInputLength = decNumberInput.length();
        decNumberIsPositive = true;
        inputIsOK = true;

        if (decNumberInput[0] == '-')                       // Если число отрицательное
        {
            decNumberIsPositive = false;
            decNumberInput.erase(decNumberInput.begin());
            decNumberInputLength--;
        }
        else if (decNumberInput[0] == '+')                  // Если число явно положительное
        {
            decNumberInput.erase(decNumberInput.begin());
            decNumberInputLength--;
        }
        decNumberHasDots = false;
        dotPos = decNumberInputLength;

        if ((decNumberInput[decNumberInputLength - 1] == '.') ||    // Если в конце стоит точка/запятая без дробной части
            (decNumberInput[decNumberInputLength - 1] == ','))
        {
            decNumberInput += '0';      // Дополнение числа нулём для корректного разбиения на целую и дробную части
            decNumberInputLength++;
        }

        for (int i = decNumberInputLength - 1; i >= 0; i--)
        {
            if (decNumberInput[i] == ',') {
                (decNumberInput[i] = '.');
            }
            if (decNumberInput[i] == '.')
            {
                if (decNumberHasDots)
                {
                    inputIsOK = false;
                    break;
                }
                else
                {
                    decNumberHasDots = true;
                    dotPos = i;
                }
            }
            else if ((decNumberInput[i] < '0') || (decNumberInput[i] > '9'))
            {
                inputIsOK = false;
                break;
            }
        }
        if (!inputIsOK) {
            cout << " Некорректный ввод. Введите ещё раз:\n";
        }
        else
        {
            // Попытка разбиения числа на целую и дробную части
            try {
                fractionPartOfDec = modf(stod(decNumberInput), &integerPartOfDec);
            }
            catch (out_of_range)
            {
                cerr << " Число слишком большое. Введите другое число:\n";
                inputIsOK = false;
            }
        }
    } while (!inputIsOK);

    try
    {
        if (integerPartOfDec == 0) {
            binNumber = '0' + binNumber;
        }
        else
        {
            while (integerPartOfDec > 0)    // Перевод целой части числа
            {
                binNumber = to_string(int(fmod(integerPartOfDec, 2))) + binNumber;
                integerPartOfDec = floor(integerPartOfDec / 2);
            }
        }

        if (!decNumberIsPositive) {
            binNumber = '-' + binNumber;
        }

        if (decNumberHasDots)   // Если число имеет дробную часть
        {
            binNumber += '.';
            const int NUMBER_OF_FRACTION_DIGITS = 15;               // Максимальное число отображаемых знаков после точки/запятой
            for (int i = 0; i < NUMBER_OF_FRACTION_DIGITS; i++)     // Перевод дробной части числа
            {
                fractionPartOfDec *= 2;
                if (fractionPartOfDec >= 1.0)
                {
                    binNumber += '1';
                    fractionPartOfDec--;
                }
                else
                {
                    binNumber += '0';
                    if (fractionPartOfDec == 0.0) {
                        break;
                    }
                }
            }
        }

        cout << " Число в двоичной системе счисления: " << binNumber << endl;
    }
    catch (const exception& err)
    {
        cerr << " Что-то пошло не так.\n";
        cerr << " Ошибка: " << typeid(err).name() << ": " << err.what() << '\n';
    }
}