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
        cout << "  (E)NCRYPT —> зашифровать текст при помощи шифра Цезаря\n";
        cout << "  (D)ECRYPT —> дешифровать текст при помощи шифра Цезаря\n";
        cout << "  (M)ENU ————> перейти в главное меню\n";
        cout << "  E(X)IT ————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'E':
                cipherMode = eCipherMode::ENCRYPT_MODE;
                break;
            case 'D':
                cipherMode = eCipherMode::DECRYPT_MODE;
                break;
            case 'M':
                return;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while ((answer != 'E') && (answer != 'D'));

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
    cout << "  (E)NGLISH ————> английский\n";
    cout << "  (B)ELARUSIAN —> белорусский\n";
    cout << "  (R)USSIAN ————> русский\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'E':
            return ENGLISH_ALPHABET;
        case 'B':
            return BELARUSIAN_ALPHABET;
        case 'R':
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
    cout << "  (K)EYBOARD —> ввести текст при помощи клавиатуры\n";
    cout << "  (F)ILE —————> считать текст из файла\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'K':
            cout << "\n Введите текст:\n";
            getline(cin, strText);
            return true;
        case 'F':
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
            cout << "  (N)EW PATH —> ввести другой путь к файлу\n";
            cout << "  (M)ENU —————> перейти в меню (де-)шифратора\n";
            cout << "  E(X)IT —————> выйти из программы\n";

            char answer;
            do {
                cin >> answer;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                answer = toupper(answer);

                switch (answer)
                {
                case 'N':
                    break;
                case 'M':
                    return false;
                case 'X':
                    exit(0);
                default:
                    cout << " Некорректный ввод. Введите ещё раз:\n";
                    break;
                }
            } while (answer != 'N');
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
    cout << "  (C)ONSOLE —> вывести на консоль\n";
    cout << "  (F)ILE ————> записать в файл\n";
    cout << "  (B)OTH ————> вывести на консоль и записать в файл\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'C':
            cout << "\n Текст после" << ((CIPHER_MODE == eCipherMode::DECRYPT_MODE) ? " де" : " ") << "шифрования:\n";
            cout << strNewText << endl;
            return;
        case 'F':
            putTextInFile(strNewText, CIPHER_MODE);
            return;
        case 'B':
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
            cout << "  (N)EW PATH —> ввести другой путь к файлу\n";
            cout << "  (M)ENU —————> перейти в меню (де-)шифратора\n";
            cout << "  E(X)IT —————> выйти из программы\n";

            char answer;
            do {
                cin >> answer;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                answer = toupper(answer);

                switch (answer)
                {
                case 'N':
                    break;
                case 'M':
                    return;
                case 'X':
                    exit(0);
                default:
                    cout << " Некорректный ввод. Введите ещё раз:\n";
                    break;
                }
            } while (answer != 'N');
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