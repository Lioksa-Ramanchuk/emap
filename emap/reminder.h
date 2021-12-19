#ifndef REMINDER_H
#define REMINDER_H

#define NOMINMAX
#include <Windows.h>

const unsigned long long MAX_REMS_COUNT = 100;

void reminder();
void setRem();
void delRem();
void checkRem();
void CALLBACK remCallback(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime);

#endif