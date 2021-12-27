#include "number_calculator.h"  // Калькулятар
#include "string_calculator.h"  // Радковы калькулятар
#include "dozenal_mul_table.h"	// Дванаццатковая табліца множання
#include "current_date_time.h"  // Гадзіннік
#include "timetable.h"          // Расклад заняткаў
#include "bin_dec_converter.h"  // BIN/DEC канвертар
#include "reminder.h"			// Напамінальнік
#include "caesar_endecoder.h"	// Шыфратар-дэшыфратар Цэзара

#include <iostream>
#include <string>
#include <thread>
#define NOMINMAX
#include <Windows.h>

int main()
{
	using std::cin;
	using std::cout;
	
	system("chcp 1251 > nul");		// Windows-1251

	srand((unsigned)time(NULL));	// Рандом

	std::thread th(checkRem);		// Праверка напамінаў
	th.detach();

	int choice = 0;
	std::string choiceInput = "";
	
	do
	{
		system("CLS");
		cout << "\n Галоўнае меню.\n";

		cout << "\n Абярыце варыянт выкарыстання праграмы:\n";
		cout << "  1 ———> калькулятар\n";
		cout << "  2 ———> радковы калькулятар\n";
		cout << "  3 ———> дванаццатковая табліца множання\n";
		cout << "  4 ———> гадзіннік\n";
		cout << "  5 ———> расклад заняткаў\n";
		cout << "  6 ———> BIN/DEC канвертар\n";
		cout << "  7 ———> напамінальнік\n";
		cout << "  8 ———> шыфратар-дэшыфратар Цэзара\n";
		cout << "  9 ———> адкрыць сайт з недакументацыяй\n";
		cout << "  10 ——> выйсці з праграмы\n";

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

				if ((choice < 1) || (choice > 10)) {
					throw std::out_of_range("выбар павінен быць ад 1 да 10");
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
			numberCalculator();
			break;
		case 2:
			stringCalculator();
			break;
		case 3:
			dozenalMulTable();
			break;
		case 4:
			currentDateTime();
			break;
		case 5:
			timetable();
			break;
		case 6:
			binDecConverter();
			break;
		case 7:
			reminder();
			break;
		case 8:
			caesarEnDecoder();
			break;
		case 9:
			ShellExecuteA(GetConsoleWindow(), "open", "..\\emap.html", NULL, NULL, SW_SHOWDEFAULT);
			break;
		case 10:
			break;
		default:
			cout << "Вы не павінны бачыць гэты радок.\n";
			break;
		}
	} while (choice != 10);

	return 0;
}



// Тут былі А. Раманчук, У. Гарашчэня, М. Карэба,  М. Ружыцкі, А. Тачыла, І. Ціхаміраў. 