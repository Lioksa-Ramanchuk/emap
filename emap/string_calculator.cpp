#include "string_calculator.h"
#include <iostream>
#include <string>
using namespace std;

void stringCalculator()
{
	system("CLS");

	cout << "\n ������� �����������.\n";

	char answer;
	do
	{
		cout << "\n �������:\n";
		cout << "  1 ��> �������� ��� ����\n";
		cout << "  2 ��> ��������� ������ �������� � �����\n";
		cout << "  3 ��> �������� �������� � �����\n";
		cout << "  4 ��> ��������� ��������� �������� � ������ � �����\n";
		cout << "  5 ��> �������� � ������� ����\n";
		cout << "  6 ��> ������ � ��������\n";

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
				cout << " ���������� ����. ����������� ���� ���:\n";
				break;
			}
		} while ((answer < '1')||(answer > '6'));
	} while (true);
}

void compareStrings()
{
	string firstString, secondString;

	cout << "\n ������� ����� �����:\n";
	getline(cin, firstString);

	cout << "\n ������� ���� �����:\n";
	getline(cin, secondString);

	if (firstString == secondString) {
		cout << "\n ���� �����.\n";
	}
	else
	{
		if (firstString > secondString) {
			cout << "\n ����� ����� ������ �� ����.\n";
		}
		else {
			cout << "\n ����� ����� ����� �� �����.\n";
		}
	}
}

void findSubstr()
{
	string str, subString;

	cout << "\n ������� �����, � ��� ����� ������� ��������:\n";
	getline(cin, str);
	int firstStringLength = str.length();

	cout << "\n ������� ��������, �� ����� ������� � �����:\n";
	getline(cin, subString);
	int secondStringLength = subString.length();

	int pos = str.find(subString);

	if (pos == string::npos) {
		cout << "\n ����� �� ��������� ������� ��������.\n";
	}
	else {
		cout << "\n ������ �������� � �����: " << pos << endl;
	}
}

void replaceSubstr()
{
	string str, subStrToReplace, subStrToReplaceWith;
	int pos = 0;

	cout << "\n ������� �����, � ��� ����� �������� ��������:\n";
	getline(cin, str);

	char answer;
	do
	{
		cout << "\n ������� ��������, �� ����� ��������:\n";
		getline(cin, subStrToReplace);

		pos = str.find(subStrToReplace);

		if (pos == string::npos)
		{
			cout << "\n ����� �� ��������� ������� ��������. �������:\n";
			cout << "  1 ��> ������ ���� ��������\n";
			cout << "  2 ��> �������� � ���� ��������� ������������\n";
			cout << "  3 ��> ������ � ��������\n";

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
					cout << " ���������� ����. ����������� ���� ���:\n";
					break;
				}
			} while ((answer < '1') || (answer > '3'));
		}
	} while (pos == string::npos);

	cout << "\n ������� ��������, �� �� ����� ��������:\n";
	getline(cin, subStrToReplaceWith);

	str.replace(pos, subStrToReplace.length(), subStrToReplaceWith);

	cout << "\n ����� ����� ������ ��������:\n";
	cout << str << endl;
}

void countLetters()
{
	string str;

	cout << "\n ������� �����, � ��� ����� �������� �������� � ������:\n";
	getline(cin, str);
	int strLength = str.length();

	int nVowels = 0;
	int nConsonants = 0;
	for (char letter : str)
	{
		if (
			(letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'O') || (letter == 'U') || (letter == 'Y') ||
			(letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u') || (letter == 'y') ||

			(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
			(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
			(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
			(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�')
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
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�')
				||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') ||
				(letter == '�') || (letter == '�') || (letter == '�') || (letter == '�') || (letter == '�')
				) 
			{
				nConsonants++;
			}
		}
	}

	cout << "\n ��������� �������� � �����: " << nVowels << endl;
	cout << "\n ��������� ������ � �����: " << nConsonants << endl;
}