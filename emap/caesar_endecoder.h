#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>

const char ENGLISH_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char BELARUSIAN_ALPHABET[] = "юабцде╗фг╡ийклмнопярс║тужвь'шэщчъ";
const char RUSSIAN_ALPHABET[] = "юабцде╗фгхийклмнопярстужвьызшэщчъ";

enum class eCipherMode { DECRYPT_MODE, ENCRYPT_MODE };

void caesarEnDecoder();

void cipherWithCaesar(std::string& strText, std::string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE);

char charToUpper(const char& LETTER);

#endif