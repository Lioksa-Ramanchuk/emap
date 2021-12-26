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

	std::string answer;
	bool answerIsOK = true;
	
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

		do
		{
			answerIsOK = true;
			getline(cin, answer);

			if (answer == "1") {
				numberCalculator();
			}
			else if (answer == "2") {
				stringCalculator();
			}
			else if (answer == "3") {
				dozenalMulTable();
			}
			else if (answer == "4") {
				currentDateTime();
			}
			else if (answer == "5") {
				timetable();
			}
			else if (answer == "6") {
				binDecConverter();
			}
			else if (answer == "7") {
				reminder();
			}
			else if (answer == "8") {
				caesarEnDecoder();
			}
			else if (answer == "9") {
				ShellExecuteA(GetConsoleWindow(), "open", "..\\emap.html", NULL, NULL, SW_SHOWDEFAULT);
			}
			else if (answer == "10") {
				break;
			}
			else
			{
				answerIsOK = false;
				cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
			}
		} while (!answerIsOK);
	} while (answer != "10");

	return 0;
}



// Тут былі А. Раманчук, У. Гарашчэня, М. Карэба,  М. Ружыцкі, А. Тачыла, І. Ціхаміраў. 