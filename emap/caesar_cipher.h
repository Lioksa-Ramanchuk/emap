#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>

const char ENGLISH_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char BELARUSIAN_ALPHABET[] = "АБВГДЕЁЖЗІЙКЛМНОПРСТУЎФХЦЧШ'ЫЬЭЮЯ";
const char RUSSIAN_ALPHABET[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

enum class eCipherMode { DECRYPT_MODE, ENCRYPT_MODE };

void caesarCipher();	// Шифратор-дешифратор Цезаря

// Функция (де-)шифрования при помощи шифра Цезаря
void encodeDecodeWithCaesar(std::string& strText, std::string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE);

char charToUpper(const char& LETTER);    // Конвертация символа в верхний регистр

#endif