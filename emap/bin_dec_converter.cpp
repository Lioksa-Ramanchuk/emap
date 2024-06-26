#include <iostream>
#include <string>
#include "bin_dec_converter.h"

using std::cin;
using std::cout;
using std::string;

void binDecConverter()
{
    system("CLS");
    cout << "\n ��������� ��������� ��� � ����������� � ���������.\n";
    cout << " ��������� ��������, �������, �����, ������� ��.\n";

    int choice = 0;
    string choiceInput = "";

    while (true)
    {
        cout << "\n �������:\n";
        cout << "  1 ��> ��������� �� � ��������� ������ ������ � �����������\n";
        cout << "  2 ��> ��������� �� � ����������� ������ ������ � ���������\n";
        cout << "  3 ��> �������� � ������� ����\n";
        cout << "  4 ��> ������ � ��������\n";

        while (true)
        {
            getline(cin, choiceInput);

            try
            {
                for (char ch : choiceInput)
                {
                    if (!isdigit(ch)) {
                        throw std::out_of_range("����� ������ ���� ����� ����");
                    }
                }

                choice = stoi(choiceInput);

                if ((choice < 1) || (choice > 4)) {
                    throw std::out_of_range("����� ������ ���� �� 1 �� 4");
                }

                break;
            }
            catch (...) {
                cout << " ���������� ����. ����������� ���� ���:\n";
            }
        }

        switch (choice)
        {
        case 1: convertBinToDec();
            break;
        case 2: convertDecToBin();
            break;
        case 3:
            return;
        case 4:
            exit(0);
        default:
            cout << "�� �� ������ ������ ���� �����.\n";
            break;
        }
    }
}

void convertBinToDec()
{
    string binNumberInput = "";
    double decNumber = 0.0;

    int binNumberInputLength = 0;
    int dotPos = 0;
    bool binNumberIsPositive = true;
    bool binNumberHasDots = false;
    bool inputIsOK = true;

    cout << "\n ������� �� � ��������� ������ ������:\n";

    do
    {
        getline(cin, binNumberInput);
        binNumberInputLength = binNumberInput.length();
        binNumberIsPositive = true;
        inputIsOK = true;

        if (binNumberInput[0] == '-')
        {
            binNumberIsPositive = false;
            binNumberInput.erase(binNumberInput.begin());
            binNumberInputLength--;
        }
        else if (binNumberInput[0] == '+')
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
            cout << " ���������� ����. ����������� ���� ���:\n";
        }
    } while (!inputIsOK);

    try
    {
        for (int i = 0; i < dotPos; i++)
        {
            if (binNumberInput[i] == '1') {
                decNumber += pow(2, dotPos - 1 - i);
            }
        }
        for (int i = dotPos + 1; i < binNumberInputLength; i++)
        {
            if (binNumberInput[i] == '1') {
                decNumber += pow(2, dotPos - i);
            }
        }
        if (!binNumberIsPositive) {
            decNumber *= -1;
        }

        cout << "\n ˳� � ����������� ������ ������: " << decNumber << '\n';
    }
    catch (const std::exception& err)
    {
        std::cerr << " ������� ������ �� ���.  :/\n";
        std::cerr << " �������: " << typeid(err).name() << ": " << err.what() << '\n';
    }
}

void convertDecToBin()
{
    string decNumberInput = "";
    string binNumber = "";

    int decNumberInputLength = 0;
    int dotPos = 0;
    double integerPartOfDec = 0;
    double fractionPartOfDec = 0;
    bool decNumberIsPositive = true;
    bool decNumberHasDots = false;
    bool inputIsOK = true;

    cout << "\n ������� �� � ����������� ������ �������:\n";

    do
    {
        getline(cin, decNumberInput);
        decNumberInputLength = decNumberInput.length();
        decNumberIsPositive = true;
        inputIsOK = true;

        if (decNumberInput[0] == '-')
        {
            decNumberIsPositive = false;
            decNumberInput.erase(decNumberInput.begin());
            decNumberInputLength--;
        }
        else if (decNumberInput[0] == '+')
        {
            decNumberInput.erase(decNumberInput.begin());
            decNumberInputLength--;
        }
        decNumberHasDots = false;
        dotPos = decNumberInputLength;

        if ((decNumberInput[decNumberInputLength - 1] == '.') ||
            (decNumberInput[decNumberInputLength - 1] == ','))
        {
            decNumberInput += '0';
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
            cout << " ���������� ����. ����������� ���� ���:\n";
        }
        else
        {
            try {
                fractionPartOfDec = modf(stod(decNumberInput), &integerPartOfDec);
            }
            catch (std::out_of_range)
            {
                std::cerr << " ˳� ����� ����. ������� ���� ��:\n";
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
            while (integerPartOfDec > 0)
            {
                binNumber = std::to_string(int(fmod(integerPartOfDec, 2))) + binNumber;
                integerPartOfDec = floor(integerPartOfDec / 2);
            }
        }

        if (!decNumberIsPositive) {
            binNumber = '-' + binNumber;
        }

        if (decNumberHasDots)
        {
            binNumber += '.';
            const int NUMBER_OF_FRACTION_DIGITS = 15;
            for (int i = 0; i < NUMBER_OF_FRACTION_DIGITS; i++)
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

        cout << " ˳� � ��������� ������ ������: " << binNumber << '\n';
    }
    catch (const std::exception& err)
    {
        std::cerr << " ������� ������ �� ���.  :/\n";
        std::cerr << " �������: " << typeid(err).name() << ": " << err.what() << '\n';
    }
}