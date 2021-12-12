#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>

const int WORKING_DAYS_NUMBER = 6;

const std::string WORKING_DAYS[WORKING_DAYS_NUMBER]
{ 
	(const std::string)"�����������",
	(const std::string)"�������",
	(const std::string)"�����",
	(const std::string)"�������",
	(const std::string)"�������",
	(const std::string)"�������"
};

const std::string TIMETABLES_FOR_DAYS[WORKING_DAYS_NUMBER] =
{
	(
		(const std::string)" |                 |                   I �� 200-3� �������������� ������ ���. ���������� �.�.                    |\n" +
		(const std::string)" |  14:40 - 16:00  +---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |                 |                              II �� 111-4 �������������� ������                              |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |                �� 221-2 ���.                 |                �� 111-2 ���.                 |\n" +
		(const std::string)" |                 |               ���������� ����                |               ���������� ����                |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  18:05 - 19:25  |               �� 303-1 ������                |            �� 324-1 ������������             |\n" +
		(const std::string)" |                 |            ����������� ���������             |                ����� ��������                |\n" +
		(const std::string)" +=================+==============================================+==============================================+\n"
	),

	(
		(const std::string)" |  14:40 - 16:00  |            �� 310�-1 ������������            |               �� 324-1 ������                |\n" +
		(const std::string)" |                 |                ����� ��������                |            ����������� ���������             |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |                     �� 200-3� ������ �������������� � ����������������                      |\n" +
		(const std::string)" |                 |                                      ���. ������� �.�                                       |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  18:05 - 19:25  |                                  �� 423-4 ����������� ����                                  |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +=================+=============================================================================================+\n"
	),

	(
		(const std::string)" |  14:40 - 16:00  |                �� 200-3� ����������-���������� ������ �������������� ������                 |\n" +
		(const std::string)" |                 |                                      ���. ������ �.�.                                       |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |                                     ���������� ��������                                     |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  18:05 - 19:25  |                    �� 100-3� �������� ������� � ������������� ���������                     |\n" +
		(const std::string)" |                 |                                    ���. ���������� �.�.                                     |\n" +
		(const std::string)" +=================+=============================================================================================+\n"
	),

	(
		(const std::string)" |  14:40 - 16:00  |        I �� 221-2 ���. ���������� ����       |   II �� 126-4 ����������-���������� ������   |\n" +
		(const std::string)" |                 |                                              |             �������������� ������            |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |                           �� 200-3� ������ ����������� ���������                            |\n" +
		(const std::string)" |                 |                                   ��. ����. �������� �.�                                    |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  18:05 - 19:25  |                                              |         �� 111-2 ���. ���������� ����        |\n" +
		(const std::string)" |                 |                                              |                                              |\n" +
		(const std::string)" +=================+==============================================+==============================================+\n"
	),

	(
		(const std::string)" |  14:40 - 16:00  |        �� 413-1 ������ ��������������        |        �� 322-1 ������ ��������������        |\n" +
		(const std::string)" |                 |              � ����������������              |              � ����������������              |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |  16:30 - 17:50  |                                  �� 360-4 �������� �������                                  |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  18:05 - 19:25  |                               �� 360-4 �������������� ������                                |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +-----------------+----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |                 |         I �� 100-3� ������� ������������� ����� ���������� ������ ���. �������� �.�         |\n" +
		(const std::string)" |  19:40 - 21:00  +----------------------------------------------+----------------------------------------------+\n" +
		(const std::string)" |                 |       II �� 221-2 ���. ���������� ����       |                                              |\n" +
		(const std::string)" +=================+==============================================+==============================================+\n"
	),

	(
		(const std::string)" |  11:25 - 12:45  |                     �� 100-3� �������������� ������ ���. ���������� �.�                     |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  13:00 - 14:20  |                                     ���������� ��������                                     |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +-----------------+---------------------------------------------------------------------------------------------+\n" +
		(const std::string)" |  14:40 - 16:00  |                  �� 200-3� ������������ ����� �������� ���. ���������� �.�                  |\n" +
		(const std::string)" |                 |                                                                                             |\n" +
		(const std::string)" +=================+==============================================+==============================================+\n"
	)
};

void timetable();
void showTimetable(unsigned day);	// ����� ���������� �� ��� ������

#endif