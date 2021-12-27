#include <iostream>
#include <string>
#include "dozenal_mul_table.h"

using std::cin;
using std::cout;
using std::string;

const unsigned NUMBER_OF_TASKS = 10;

string decToDoz(int decNumber);

void dozenalMulTable()
{
    system("CLS");
    cout << "\n Дванаццатковая табліца множання.\n";

    string dozResult, resultInput;
    int firstNumber, secondNumber, score = 0, nCurrentTask = 1;

    int choice = 0;
    string choiceInput = "";

    while (true)
    {
        cout << "\n Абярыце:\n";
        cout << "  1 ——> выканаць тэст на " << NUMBER_OF_TASKS << " заданняў\n";
        cout << "  2 ——> паўтарыць дванаццатковую табліцу множання\n";
        cout << "  3 ——> перайсці ў галоўнае меню\n";
        cout << "  4 ——> выйсці з праграмы\n";

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

                if ((choice < 1) || (choice > 4)) {
                    throw std::out_of_range("выбар павінен быць ад 1 да 4");
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
        {
            system("CLS");
            cout << "\n Дванаццатковая табліца множання.\n";
            cout << "\n Тэст на " << NUMBER_OF_TASKS << " заданняў.\n";
            cout << " Каб перапыніць тэст, увядзіце \"X\".\n";

            score = 0;
            for (nCurrentTask = 1; nCurrentTask <= NUMBER_OF_TASKS; nCurrentTask++)
            {
                firstNumber = rand() % 11 + 2;
                secondNumber = rand() % 11 + 2;
                dozResult = decToDoz(firstNumber * secondNumber);

                cout << "\n Заданне №" << nCurrentTask << '\n';
                cout << ' ' << decToDoz(firstNumber) << " * " << decToDoz(secondNumber) << " = ";
                getline(cin, resultInput);

                if (resultInput == dozResult)
                {
                    score++;
                    cout << " Слушна!\n";
                }
                else if ((resultInput == "X") || (resultInput == "x") || (resultInput == "Х") || (resultInput == "х")) {
                    break;
                }
                else {
                    cout << " Слушны адказ: " << dozResult << '\n';
                }
            }
            cout << "\n Рэзультат: " << score << "/" << nCurrentTask - 1 << '\n';
        }
            break;
        case 2:
            cout << "\n Дванаццатковая табліца множання.\n";
            cout << '\n';
            cout << "      +----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << "      | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | A  | B  | 10  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 1  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | A  | B  | 10  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 2  | 2  | 4  | 6  | 8  | A  | 10 | 12 | 14 | 16 | 18 | 1A | 20  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 3  | 3  | 6  | 9  | 10 | 13 | 16 | 19 | 20 | 23 | 26 | 29 | 30  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 4  | 4  | 8  | 10 | 14 | 18 | 20 | 24 | 28 | 30 | 34 | 38 | 40  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 5  | 5  | A  | 13 | 18 | 21 | 26 | 2B | 34 | 39 | 42 | 47 | 50  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 6  | 6  | 10 | 16 | 20 | 26 | 30 | 36 | 40 | 46 | 50 | 56 | 60  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 7  | 7  | 12 | 19 | 24 | 2B | 36 | 41 | 48 | 53 | 5A | 65 | 70  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 8  | 8  | 14 | 20 | 28 | 34 | 40 | 48 | 54 | 60 | 68 | 74 | 80  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 9  | 9  | 16 | 23 | 30 | 39 | 46 | 53 | 60 | 69 | 76 | 83 | 90  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | A  | A  | 18 | 26 | 34 | 42 | 50 | 5A | 68 | 76 | 84 | 92 | A0  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | B  | B  | 1A | 29 | 38 | 47 | 56 | 65 | 74 | 83 | 92 | A1 | B0  |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            cout << " | 10 | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | A0 | B0 | 100 |\n";
            cout << " +----+----+----+----+----+----+----+----+----+----+----+----+-----+\n";
            break;
        case 3:
            return;
        case 4:
            exit(0);
        default:
            cout << "Вы не павінны бачыць гэты радок.\n";
            break;
        }
    }
}

string decToDoz(int decNumber)
{
    string dozNumber("");
    do
    {
        int r = decNumber % 12;
        if (r > 9) {
            r += (int)'A' - 10;
        }
        else {
            r += (int)'0';
        }
        dozNumber = (char)r + dozNumber;
        decNumber /= 12;
    } while (decNumber);

    return dozNumber;
}