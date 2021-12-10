#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>

const int WORKING_DAYS_NUMBER = 6;

const std::string WORKING_DAYS[WORKING_DAYS_NUMBER]
{ 
	(const std::string)"Понедельник",
	(const std::string)"Вторник",
	(const std::string)"Среда",
	(const std::string)"Четверг",
	(const std::string)"Пятница",
	(const std::string)"Суббота"
};

const std::string TIMETABLES_FOR_DAYS[WORKING_DAYS_NUMBER] =
{
	// Расписание на понедельник (незаконченное: это просто пример)
	(
		(const std::string)" |  14:40 - 16:00  |   I лк 200-3а Математический анализ   |\n" +
		(const std::string)" |                 |   II пз 111-4 Математический анализ   |\n" +
		(const std::string)" +-----------------+-------------------+-------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |   пз 221-2 общ.   |   пз 11-2 общ.    |\n" +
		(const std::string)" |                 |  Английский язык  |  Английский язык  |\n" +
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	),

	// Такие же расписания для других дней
	(
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	),

	(
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	),

	(
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	),

	(
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	),

	(
		(const std::string)" +-----------------+-------------------+-------------------+\n"
	)
};

void timetable();
void showTimetable(unsigned day);	// Вывод расписания по номеру дня

#endif