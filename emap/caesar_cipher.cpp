#include "caesar_cipher.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void caesarCipher()
{
    system("CLS");

    cout << "\n Шифратор-дешифратор Цезаря.\n";
    cout << " Позволяет зашифровать и дешифровать текст на английском, белорусском и русском языках.\n";
    cout << " Поддерживает чтение текста из выбранного файла и запись в выбранный файл.\n";

    const char* pALPHABET;
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

        pALPHABET = chooseAlphabet();
        if (getText(strText))
        {
            encodeDecodeWithCaesar(strText, strNewText, pALPHABET, cipherMode);
            putText(strNewText, cipherMode);
        }
    } while (true);
}

const char* chooseAlphabet()
{
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
            return ENGLISH_ALPHABET;
        case '2':
            return BELARUSIAN_ALPHABET;
        case '3':
            return RUSSIAN_ALPHABET;
        default:
            cout << " Некорректный ввод. Введите ещё раз:\n";
            break;
        }
    } while (true);
}

bool getText(string& strText)
{
    cout << "\n Выберите:\n";
    cout << "  1 ——> ввести текст при помощи клавиатуры\n";
    cout << "  2 ——> считать текст из файла\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (answer)
        {
        case '1':
            cout << "\n Введите текст:\n";
            getline(cin, strText);
            return true;
        case '2':
            return getTextFromFile(strText);
        default:
            cout << " Некорректный ввод. Введите ещё раз:\n";
            break;
        }
    } while (true);
}

bool getTextFromFile(string& strText)
{
    ifstream in;
    string path;

    do
    {
        cout << "\n Введите путь к файлу:\n";
        getline(cin, path);
        in.open(path);

        if (!in) {
            cout << "\n Не удаётся открыть файл. Выберите:\n";
            cout << "  1 ——> ввести другой путь к файлу\n";
            cout << "  2 ——> перейти в меню (де-)шифратора\n";
            cout << "  3 ——> выйти из программы\n";

            char answer;
            do {
                cin >> answer;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (answer)
                {
                case '1':
                    break;
                case '2':
                    return false;
                case '3':
                    exit(0);
                default:
                    cout << " Некорректный ввод. Введите ещё раз:\n";
                    break;
                }
            } while ((answer < '1') || (answer > '3'));
        }
        else
        {
            getline(in, strText);
            in.close();

            cout << "\n Текст был успешно считан из файла.\n";
            break;
        }
    } while (true);

    return true;
}

void putText(string& strNewText, const eCipherMode& CIPHER_MODE)
{
    cout << "\n Текст после" << ((CIPHER_MODE == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования\n";
    cout << "  1 ——> вывести на консоль\n";
    cout << "  2 ——> записать в файл\n";
    cout << "  3 ——> вывести на консоль и записать в файл\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (answer)
        {
        case '1':
            cout << "\n Текст после" << ((CIPHER_MODE == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования:\n";
            cout << strNewText << endl;
            return;
        case '2':
            putTextInFile(strNewText, CIPHER_MODE);
            return;
        case '3':
            cout << "\n Текст после" << ((CIPHER_MODE == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования:\n";
            cout << strNewText << endl;
            putTextInFile(strNewText, CIPHER_MODE);
            return;
        default:
            cout << " Некорректный ввод. Введите ещё раз:\n";
            break;
        }
    } while (true);
}

void putTextInFile(string& strNewText, const eCipherMode& CIPHER_MODE)
{
    ofstream out;
    string path;

    do
    {
        cout << "\n Введите путь к файлу:\n";
        getline(cin, path);
        out.open(path);

        if (!out) {
            cout << "\n Не удаётся открыть файл. Выберите:\n";
            cout << "  1 ——> ввести другой путь к файлу\n";
            cout << "  2 ——> перейти в меню (де-)шифратора\n";
            cout << "  3 ——> выйти из программы\n";

            char answer;
            do {
                cin >> answer;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (answer)
                {
                case '1':
                    break;
                case '2':
                    return;
                case '3':
                    exit(0);
                default:
                    cout << " Некорректный ввод. Введите ещё раз:\n";
                    break;
                }
            } while ((answer < '1') || (answer > '3'));
        }
        else
        {
            out << strNewText;
            out.close();

            cout << "\n Текст после" << ((CIPHER_MODE == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования был успешно записан в файл.\n";
            break;
        }
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