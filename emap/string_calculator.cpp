#include <iostream>
#include <string>
#include "string_calculator.h"

using std::cin;
using std::cout;
using std::string;

void stringCalculator()
{
	system("CLS");

	cout << "\n Радковы калькулятар.\n";

	int choice = 0;
	string choiceInput = "";

	while (true)
	{
		cout << "\n Абярыце:\n";
		cout << "  1 ——> параўнаць два радкі\n";
		cout << "  2 ——> вызначыць пазіцыю падрадка ў радку\n";
		cout << "  3 ——> замяніць падрадок у радку\n";
		cout << "  4 ——> вызначыць колькасць галосных і зычных у радку\n";
		cout << "  5 ——> перайсці ў галоўнае меню\n";
		cout << "  6 ——> выйсці з праграмы\n";

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

				if ((choice < 1) || (choice > 6)) {
					throw std::out_of_range("выбар павінен быць ад 1 да 6");
				}

				break;
			}
			catch (...) {
				cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
			}
		}

		switch (choice)
		{
		case 1: compareStrings();
			break;
		case 2: findSubstr();
			break;
		case 3: replaceSubstr();
			break;
		case 4: countLetters();
			break;
		case 5:
			return;
		case 6:
			exit(0);
		default:
			cout << "Вы не павінны бачыць гэты радок.\n";
			break;
		}
	}
}

void compareStrings()
{
	string firstString, secondString;

	cout << "\n Увядзіце першы радок:\n";
	getline(cin, firstString);

	cout << "\n Увядзіце другі радок:\n";
	getline(cin, secondString);

	if (firstString == secondString) {
		cout << "\n Радкі роўныя.\n";
	}
	else
	{
		if (firstString > secondString) {
			cout << "\n Першы радок большы за другі.\n";
		}
		else {
			cout << "\n Першы радок меншы за здругі.\n";
		}
	}
}

void findSubstr()
{
	string str, subString;

	cout << "\n Увядзіце радок, у якім трэба знайсці падрадок:\n";
	getline(cin, str);
	unsigned firstStringLength = str.length();

	cout << "\n Увядзіце падрадок, які трэба знайсці ў радку:\n";
	getline(cin, subString);
	unsigned secondStringLength = subString.length();

	int pos = str.find(subString);

	if (pos == string::npos) {
		cout << "\n Радок не ўтрымлівае дадзены падрадок.\n";
	}
	else {
		cout << "\n Пазіцыя падрадка ў радку: " << pos << '\n';
	}
}

void replaceSubstr()
{
	string str, subStrToReplace, subStrToReplaceWith;
	int pos = 0;

	cout << "\n Увядзіце радок, у якім трэба замяніць падрадок:\n";
	getline(cin, str);

	int choice = 0;
	string choiceInput = "";

	do
	{
		cout << "\n Увядзіце падрадок, які трэба замяніць:\n";
		getline(cin, subStrToReplace);

		pos = str.find(subStrToReplace);

		if (pos == string::npos)
		{
			cout << "\n Радок не ўтрымлівае дадзены падрадок. Абярыце:\n";
			cout << "  1 ——> увесці іншы падрадок\n";
			cout << "  2 ——> перайсці ў меню радковага калькулятора\n";
			cout << "  3 ——> выйсці з праграмы\n";

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

					if ((choice < 1) || (choice > 3)) {
						throw std::out_of_range("выбар павінен быць ад 1 да 3");
					}

					break;
				}
				catch (...) {
					cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
				}
			}

			switch (choice)
			{
			case '1':
				break;
			case '2':
				return;
			case '3':
				exit(0);
			default:
				cout << "Вы не павінны бачыць гэты радок.\n";
				break;
			}
		}
	} while (pos == string::npos);

	cout << "\n Увядзіце падрадок, на які трэба замяніць:\n";
	getline(cin, subStrToReplaceWith);

	str.replace(pos, subStrToReplace.length(), subStrToReplaceWith);

	cout << "\n Радок пасля замены падрадка:\n";
	cout << str << '\n';
}

void countLetters()
{
	string str;

	cout << "\n Увядзіце радок, у якім трэба падлічыць галосныя и зычныя:\n";
	getline(cin, str);
	unsigned strLength = str.length();

	unsigned nVowels = 0;
	unsigned nConsonants = 0;
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

	cout << "\n Колькасць галосных у радку: " << nVowels << '\n';
	cout << "\n Колькасць зычных у радку: " << nConsonants << '\n';
}