#include "number_calculator.h"  // Лікавы калькулятар
#include "string_calculator.h"  // Радковы калькулятар
#include "current_date_time.h"  // Гадзіннік
#include "timetable.h"          // Расклад заняткаў
#include "bin_dec_converter.h"  // BIN/DEC канвертар
#include "reminder.h"			// Напамінальнік
#include "caesar_endecoder.h"	// Шыфратар-дэшыфратар Цэзара

#include <iostream>
#include <thread>
#define NOMINMAX
#include <Windows.h>

int main()
{
	using std::cin;
	using std::cout;

	system("chcp 1251 > nul");  // Windows-1251

	std::thread th(checkRem);
	th.detach();

	char answer;
	do
	{
		system("CLS");
		cout << "\n Галоўнае меню.\n";

		cout << "\n Абярыце варыянт выкарыстання праграмы:\n";
		cout << "  1 ——> лікавы калькулятар\n";
		cout << "  2 ——> радковы калькулятар\n";
		cout << "  3 ——> гадзіннік\n";
		cout << "  4 ——> расклад заняткаў\n";
		cout << "  5 ——> BIN/DEC канвертар\n";
		cout << "  6 ——> напамінальнік\n";
		cout << "  7 ——> шыфратар-дэшыфратар Цэзара\n";
		cout << "  8 ——> адкрыць сайт з недакументацыяй\n";
		cout << "  9 ——> выйсці з праграмы\n";

		do
		{
			cin >> answer;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			answer = toupper(answer);

			switch (answer)
			{
			case '1': numberCalculator();
				break;
			case '2': stringCalculator();
				break;
			case '3': currentDateTime();
				break;
			case '4': timetable();
				break;
			case '5': binDecConverter();
				break;
			case '6': reminder();
				break;
			case '7': caesarEnDecoder();
				break;
			case '8': ShellExecuteA(GetConsoleWindow(), "open", "..\\emap.html", NULL, NULL, SW_SHOWDEFAULT);
				break;
			case '9':
				break;
			default:
				cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
				break;
			}
		} while ((answer < '1') || (answer > '9'));
	} while (answer != '9');

	return 0;
}



// Тут былі А. Раманчук, У. Гарашчэня, М. Карэба,  М. Ружыцкі, А. Тачыла, І. Ціхаміраў. 