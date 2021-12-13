#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "reminder.h"

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void reminder() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");

	static string message;
	bool call = true;
	int menuItem;

	ull h = 0;
	ull m = 0;

	//auto now = zoned_time{ current_zone(), system_clock::now() }.get_local_time();
	//auto time_now = now - floor<days>(now);//текущее время дня после полуночи
	//для получения текущего времеми через chrono

	while (call) {
		cout << "1.Создать новую напоминалку\n";
		cout << "2.Перейти в главное меню\n";
		cout << "3.Выйти из программы\n";
		cin >> menuItem;
		switch (menuItem)
		{
		case 1:
			cout << "Установите время, через которое должна сработать напоминалка" << "\n"
				<< "часы : ";
			cin >> h;
			cout << "минуты:  ";
			cin >> m;

			cout << "Текст напоминалки: ";
			cin.ignore(32767, '\n');
			getline(cin, message);

			this_thread::sleep_for(chrono::hours(h));
			this_thread::sleep_for(chrono::seconds(m));//понятно, что минуты, но тестировать удобнее в сек
			Beep(432, 300);

			cout << message << "\n";

		case 2:
			break;
		case 3:
			call = false;
			break;
		default:
			cout << "дэбил?\n";
			break;
		}
	}
}