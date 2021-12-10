#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H
#include <string>

const char ENGLISH_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char BELARUSIAN_ALPHABET[] = "АБВГДЕЁЖЗІЙКЛМНОПРСТУЎФХЦЧШ'ЫЬЭЮЯ";
const char RUSSIAN_ALPHABET[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

enum eCipherMode { DECRYPT_MODE, ENCRYPT_MODE };

void caesarCipher();																			// Шифратор-дешифратор Цезаря
const char* chooseAlphabet();																	// Выбор алфавита текста: EN/BE/RU
bool getText(std::string& strText);																// Ввод текста для (де-)шифрования
bool getTextFromFile(std::string& strText);														// Чтение текста из файла
void putText(std::string& strNewText, const eCipherMode& CIPHER_MODE = ENCRYPT_MODE);			// Вывод текста после (де-)шифрования
void putTextInFile(std::string& strNewText, const eCipherMode& CIPHER_MODE = ENCRYPT_MODE);		// Запись текста в файл после (де-)шифрования

// Функция (де-)шифрования при помощи шифра Цезаря
void encodeDecodeWithCaesar(std::string& strText, std::string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE);

char charToUpper(const char& LETTER);   // Конвертация символа в верхний регистр

#endif