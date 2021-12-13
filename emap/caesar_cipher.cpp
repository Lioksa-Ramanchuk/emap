#include "caesar_cipher.h"
#include <iostream>
#include <string>
using namespace std;

void caesarCipher()
{
    system("CLS");

    cout << "\n Шифратор-дешифратор Цезаря.\n";
    cout << " Позволяет зашифровать и дешифровать текст на английском, белорусском и русском языках.\n";

    const char* pALPHABET = BELARUSIAN_ALPHABET;
    string strText, strNewText;
    eCipherMode cipherMode;

    char answer;
    do
    {
        cout << "\n Выберите:\n";
        cout << "  1 ——> зашифровать текст при помощи шифра Цезаря\n";
        cout << "  2 ——> дешифровать текст при помощи шифра Цезаря\n";
        cout << "  3 ——> перейти в главное меню\n";
        cout << "  4 ——> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (answer)
            {
            case '1':
                cipherMode = eCipherMode::ENCRYPT_MODE;
                break;
            case '2':
                cipherMode = eCipherMode::DECRYPT_MODE;
                break;
            case '3':
                return;
            case '4':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '4'));

        strText.clear();
        strNewText.clear();

        cout << "\n Выберите язык текста:\n";
        cout << "  1 ——> английский\n";
        cout << "  2 ——> белорусский\n";
        cout << "  3 ——> русский\n";

        char answer;
        do
        {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (answer)
            {
            case '1':
                pALPHABET = ENGLISH_ALPHABET;
                break;
            case '2':
                pALPHABET = BELARUSIAN_ALPHABET;
                break;
            case '3':
                 pALPHABET = RUSSIAN_ALPHABET;
                 break;
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '3'));

        cout << "\n Введите текст:\n";
        getline(cin, strText);

        encodeDecodeWithCaesar(strText, strNewText, pALPHABET, cipherMode);

        cout << "\n Текст после" << ((cipherMode == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования:\n";
        cout << strNewText << endl;
    } while (true);
}

void encodeDecodeWithCaesar(string& strText, string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE)
{
    cout << "\n Введите значение сдвига для шифра Цезаря:\n";

    int delta = 0;      // Значение сдвига для шифра Цезаря
    string deltaInput;
    do
    {
        try
        {
            getline(cin, deltaInput);
            delta = stoi(deltaInput);
            break;
        }
        catch (...) {
            cout << " Некорректный ввод. Введите ещё раз:\n";
        }
    } while (true);

    if (CIPHER_MODE == eCipherMode::DECRYPT_MODE) {     // При дешифровании сдвиг осуществляется в другую сторону
        delta *= -1;
    }

    const int ALPHABET_LENGTH = strlen(pALPHABET);

    delta %= ALPHABET_LENGTH;   // Делаем сдвиг неотрицательным, меньше длины алфавита
    if (delta < 0) {
        delta += ALPHABET_LENGTH;
    }

    if (delta)
    {
        const int TEXT_LENGTH = strText.length();
        const char* pLETTER;

        for (int i = 0; i < TEXT_LENGTH; i++)
        {
            pLETTER = strchr(pALPHABET, charToUpper(strText[i]));
            if (pLETTER) {
                pLETTER = pALPHABET + ((pLETTER - pALPHABET + delta) % ALPHABET_LENGTH);    // Сдвиг, если буква в алфавите
            }
            else {
                pLETTER = &strText[i];  // Копирование символа не из алфавита
            }

            strNewText += *pLETTER;
        }
    }
    else {                      // Для нулевого сдвига текст не преобразуется
        strNewText = strText;
    }
}

char charToUpper(const char& LETTER)
{
    if (('a' <= LETTER) && (LETTER <= 'z')) {
        return LETTER + 'A' - 'a';
    }
    else if (('а' <= LETTER) && (LETTER <= 'я')) {
        return LETTER + 'А' - 'а';
    }
    else if (LETTER == 'ё') {
        return 'Ё';
    }
    else if (LETTER == 'і') {
        return 'І';
    }
    else if (LETTER == 'ў') {
        return 'Ў';
    }
    else {
        return LETTER;
    }
}