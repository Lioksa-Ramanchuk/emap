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
		cout << "  (C)OMPARE ——————> сравнить две строки\n";
		cout << "  (F)IND SUBSTR ——> определить позицию подстроки в строке\n";
		cout << "  (R)EPLACE ——————> заменить подстроку в строке\n";
		cout << "  COUNT (V)OWELS —> определить количество гласных и согласных в строке\n";
		cout << "  (M)ENU —————————> перейти в главное меню\n";
		cout << "  E(X)IT —————————> выйти из программы\n";

		do {
			cin >> answer;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			answer = toupper(answer);

			switch (answer)
			{
			case 'C': compareStrings();
				break;
			case 'F': findSubstr();
				break;
			case 'R': replaceSubstr();
				break;
			case 'V': countVowels();
				break;
			case 'M':
				return;
			case 'X':
				exit(0);
			default:
				cout << " Некорректный ввод. Введите ещё раз:\n";
				break;
			}
		} while ((answer != 'C') && (answer != 'F') && (answer != 'R') && (answer != 'V'));
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

	cout << "\n Введите подстроку:\n";
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
			cout << "  (N)EW SUBSTR —> ввести новую подстроку\n";
			cout << "  (M)ENU ———————> перейти в меню калькулятора для строк\n";
			cout << "  E(X)IT ———————> выйти из программы\n";

			do {
				cin >> answer;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				answer = toupper(answer);

				switch (answer)
				{
				case 'N':
					break;
				case 'M':
					return;
				case 'X':
					exit(0);
				default:
					cout << " Некорректный ввод. Введите ещё раз:\n";
					break;
				}
			} while (answer != 'N');
		}
	} while (pos == string::npos);

	cout << "\n Введите подстроку, на которую нужно заменить:\n";
	getline(cin, subStrToReplaceWith);

	str.replace(pos, subStrToReplace.length(), subStrToReplaceWith);

	cout << "\n Строка после замены подстроки:\n";
	cout << str << endl;
}

void countVowels()
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
			(letter == 'А') || (letter == 'Е') || (letter == 'Ё') || (letter == 'И') || (letter == 'О') ||
			(letter == 'У') || (letter == 'Ы') || (letter == 'Э') || (letter == 'Ю') || (letter == 'Я') ||
			(letter == 'а') || (letter == 'е') || (letter == 'ё') || (letter == 'и') || (letter == 'о') ||
			(letter == 'у') || (letter == 'ы') || (letter == 'э') || (letter == 'ю') || (letter == 'я') || (letter == 'і') || (letter == 'І')
			)
		{
			nVowels++;
		}
		else {
			if ((letter == 'B') || (letter == 'C') || (letter == 'D') || (letter == 'F') || (letter == 'G') || (letter == 'H') ||
				(letter == 'J') || (letter == 'K') || (letter == 'L') || (letter == 'M') || (letter == 'N') || (letter == 'P') || (letter == 'Q') || (letter == 'R') || (letter == 'S') || (letter == 'T') || (letter == 'V') || (letter == 'W') ||
				(letter == 'X') || (letter == 'Z') || (letter == 'b') || (letter == 'c') || (letter == 'd') || (letter == 'f') || (letter == 'g') || (letter == 'h') || (letter == 'j') || (letter == 'k') || (letter == 'l') || (letter == 'm') ||
				(letter == 'n') || (letter == 'p') || (letter == 'q') || (letter == 'r') || (letter == 's') || (letter == 't') || (letter == 'v') || (letter == 'w') || (letter == 'x') || (letter == 'z') ||
				(letter == 'б') || (letter == 'в') || (letter == 'г') || (letter == 'д') || (letter == 'ж') ||
				(letter == 'з') || (letter == 'й') || (letter == 'к') || (letter == 'л') || (letter == 'м') ||
				(letter == 'н') || (letter == 'п') || (letter == 'р') || (letter == 'с') || (letter == 'т') || (letter == 'ў') ||
				(letter == 'ф') || (letter == 'х') || (letter == 'ч') || (letter == 'ш') || (letter == 'щ')||
				(letter == 'Б') || (letter == 'В') || (letter == 'Г') || (letter == 'Д') || (letter == 'Ж') ||
				(letter == 'З') || (letter == 'Й') || (letter == 'К') || (letter == 'Л') || (letter == 'М') ||
				(letter == 'Н') || (letter == 'П') || (letter == 'Р') || (letter == 'С') || (letter == 'Т') ||
				(letter == 'Ф') || (letter == 'Х') || (letter == 'Ч') || (letter == 'Ш') || (letter == 'Щ')
				) 
			{
				nConsonants++;
			}
		}
	}

	cout << "\n Количество гласных в строке: " << nVowels << endl;
	cout << "\n Количество согласных в строке: " << nConsonants << endl;
}