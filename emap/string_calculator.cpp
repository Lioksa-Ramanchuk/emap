#include "string_calculator.h"
#include <iostream>
#include <string>
using namespace std;

void stringCalculator()
{
	system("CLS");

	cout << "\n Строковый калькулятор.\n";

	char answer;
	do
	{
		cout << "\n Выберите:\n";
		cout << "  1 ——> сравнить две строки\n";
		cout << "  2 ——> определить позицию подстроки в строке\n";
		cout << "  3 ——> заменить подстроку в строке\n";
		cout << "  4 ——> определить количество гласных и согласных в строке\n";
		cout << "  5 ——> перейти в главное меню\n";
		cout << "  6 ——> выйти из программы\n";

		do {
			cin >> answer;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (answer)
			{
			case '1': compareStrings();
				break;
			case '2': findSubstr();
				break;
			case '3': replaceSubstr();
				break;
			case '4': countLetters();
				break;
			case '5':
				return;
			case '6':
				exit(0);
			default:
				cout << " Некорректный ввод. Введите ещё раз:\n";
				break;
			}
		} while ((answer < '1')||(answer > '6'));
	} while (true);
}

void compareStrings()
{
	string firstString, secondString;

	cout << "\n Введите первую строку:\n";
	getline(cin, firstString);

	cout << "\n Введите вторую строку:\n";
	getline(cin, secondString);

	if (firstString == secondString) {
		cout << "\n Строки равны.\n";
	}
	else
	{
		if (firstString > secondString) {
			cout << "\n Первая строка больше второй.\n";
		}
		else {
			cout << "\n Первая строка меньше второй.\n";
		}
	}
}

void findSubstr()
{
	string str, subString;

	cout << "\n Введите строку, в которой будет осуществляться поиск подстроки:\n";
	getline(cin, str);
	int firstStringLength = str.length();

	cout << "\n Введите подстроку, которую нужно найти в строке:\n";
	getline(cin, subString);
	int secondStringLength = subString.length();

	int pos = str.find(subString);

	if (pos == string::npos) {
		cout << "\n Строка не содержит данную подстроку.\n";
	}
	else {
		cout << "\n Позиция подстроки в строке: " << pos << endl;
	}
}

void replaceSubstr()
{
	string str, subStrToReplace, subStrToReplaceWith;
	int pos = 0;

	cout << "\n Введите строку, в которой нужно заменить подстроку:\n";
	getline(cin, str);

	char answer;
	do
	{
		cout << "\n Введите подстроку, которую нужно заменить:\n";
		getline(cin, subStrToReplace);

		pos = str.find(subStrToReplace);

		if (pos == string::npos)
		{
			cout << "\n Строка не содержит данную подстроку. Выберите:\n";
			cout << "  1 ——> ввести новую подстроку\n";
			cout << "  2 ——> перейти в меню калькулятора для строк\n";
			cout << "  3 ——> выйти из программы\n";

			do {
				cin >> answer;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (answer)
				{
				case '1':
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
		}
	} while (pos == string::npos);

	cout << "\n Введите подстроку, на которую нужно заменить:\n";
	getline(cin, subStrToReplaceWith);

	str.replace(pos, subStrToReplace.length(), subStrToReplaceWith);

	cout << "\n Строка после замены подстроки:\n";
	cout << str << endl;
}

void countLetters()
{
	string str;

	cout << "\n Введите строку, в которой нужно посчитать гласные и согласные:\n";
	getline(cin, str);
	int strLength = str.length();

	int nVowels = 0;
	int nConsonants = 0;
	for (char letter : str)
	{
		if (
			(letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'O') || (letter == 'U') || (letter == 'Y') ||
			(letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u') || (letter == 'y') ||

			(letter == 'А') || (letter == 'Е') || (letter == 'Ё') || (letter == 'И') || (letter == 'І') || (letter == 'О') ||
			(letter == 'У') || (letter == 'Ы') || (letter == 'Э') || (letter == 'Ю') || (letter == 'Я') ||
			(letter == 'а') || (letter == 'е') || (letter == 'ё') || (letter == 'и') || (letter == 'і') || (letter == 'о') ||
			(letter == 'у') || (letter == 'ы') || (letter == 'э') || (letter == 'ю') || (letter == 'я')
			)
		{
			nVowels++;
		}
		else {
			if (
				(letter == 'B') || (letter == 'C') || (letter == 'D') || (letter == 'F') || (letter == 'G') || (letter == 'H') ||
				(letter == 'J') || (letter == 'K') || (letter == 'L') || (letter == 'M') || (letter == 'N') || (letter == 'P') ||
				(letter == 'Q') || (letter == 'R') || (letter == 'S') || (letter == 'T') || (letter == 'V') || (letter == 'W') ||
				(letter == 'X') || (letter == 'Z')				
				||				
				(letter == 'b') || (letter == 'c') || (letter == 'd') || (letter == 'f') || (letter == 'g') || (letter == 'h') ||
				(letter == 'j') || (letter == 'k') || (letter == 'l') || (letter == 'm') || (letter == 'n') || (letter == 'p') ||
				(letter == 'q') || (letter == 'r') || (letter == 's') || (letter == 't') || (letter == 'v') || (letter == 'w') ||
				(letter == 'x') || (letter == 'z')
				||
				(letter == 'Б') || (letter == 'В') || (letter == 'Г') || (letter == 'Д') || (letter == 'Ж') || (letter == 'З') ||
				(letter == 'Й') || (letter == 'К') || (letter == 'Л') || (letter == 'М') || (letter == 'Н') || (letter == 'П') ||
				(letter == 'Р') || (letter == 'С') || (letter == 'Т') || (letter == 'Ў') || (letter == 'Ф') || (letter == 'Х') ||
				(letter == 'Ч') || (letter == 'Ш') || (letter == 'Щ') || (letter == 'Ъ') || (letter == 'ь')
				||
				(letter == 'б') || (letter == 'в') || (letter == 'г') || (letter == 'д') || (letter == 'ж') || (letter == 'з') ||
				(letter == 'й') || (letter == 'к') || (letter == 'л') || (letter == 'м') || (letter == 'н') || (letter == 'п') ||
				(letter == 'р') || (letter == 'с') || (letter == 'т') || (letter == 'ў') || (letter == 'ф') || (letter == 'х') ||
				(letter == 'ч') || (letter == 'ш') || (letter == 'щ') || (letter == 'ъ') || (letter == 'ь')
				) 
			{
				nConsonants++;
			}
		}
	}

	cout << "\n Количество гласных в строке: " << nVowels << endl;
	cout << "\n Количество согласных в строке: " << nConsonants << endl;
}