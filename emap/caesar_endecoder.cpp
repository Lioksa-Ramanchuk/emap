#include <iostream>
#include <string>
#include "caesar_endecoder.h"

using std::cin;
using std::cout;
using std::string;

void caesarEnDecoder()
{
    system("CLS");

    cout << "\n Шыфратар-дэшыфратар Цэзара.\n";
    cout << "Дазваляе зашыфраваць і дэшыфраваць тэкст на ангельскай, беларускай і расейскай мовах.\n";

    const char* pALPHABET = BELARUSIAN_ALPHABET;
    string strText, strNewText;
    eCipherMode cipherMode;

    char answer;
    do
    {
        cout << "\n Абярыце:\n";
        cout << "  1 ——> зашыфраваць тэкст пры дапамозе шыфра Цэзара\n";
        cout << "  2 ——> дешыфраваць тэкст пры дапамозе шыфра Цэзара\n";
        cout << "  3 ——> перайсці ў галоўнае меню\n";
        cout << "  4 ——> выйсці з праграмы\n";

        do {
            cin >> answer;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
                cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '4'));

        strText.clear();
        strNewText.clear();

        cout << "\n Абярыце мову тэкста:\n";
        cout << "  1 ——> ангельская\n";
        cout << "  2 ——> беларуская\n";
        cout << "  3 ——> расейская\n";

        char answer;
        do
        {
            cin >> answer;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
                cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '3'));

        cout << "\n Увядзіце тэкст:\n";
        getline(cin, strText);

        cipherWithCaesar(strText, strNewText, pALPHABET, cipherMode);

        cout << "\n Тэкст пасля" << ((cipherMode == eCipherMode::DECRYPT_MODE) ? " дэ" : " ") << "шыфравання:\n";
        cout << strNewText << '\n';
    } while (true);
}

void cipherWithCaesar(string& strText, string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE)
{
    cout << "\n Увядзіце значэнне зруху для шыфра Цэара:\n";

    int delta = 0;
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
            cout << " Некарэктны ўвод. Паспрабуйце яшчэ раз:\n";
        }
    } while (true);

    if (CIPHER_MODE == eCipherMode::DECRYPT_MODE) {
        delta *= -1;
    }

    const int ALPHABET_LENGTH = strlen(pALPHABET);

    delta %= ALPHABET_LENGTH;
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
                pLETTER = pALPHABET + ((pLETTER - pALPHABET + delta) % ALPHABET_LENGTH);
            }
            else {
                pLETTER = &strText[i];
            }

            strNewText += *pLETTER;
        }
    }
    else {
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