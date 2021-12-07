#include "caesar_cipher.h"
#include <iostream>
#include <fstream>
using namespace std;

// ========================================
// void caesarCipher
// ========================================
void caesarCipher()
{
    const char* pALPHABET;
    string strText, strNewText;
    eCipherMode cipherMode;

    char answer;
    do
    {
        strText.clear();
        strNewText.clear();

        pALPHABET = chooseAlphabet();
        if (getText(strText))
        {
            cipherMode = chooseMode();
            encodeDecodeWithCaesar(strText, strNewText, pALPHABET, cipherMode);
            putText(strNewText);
        }

        cout << "\n ��������:\n";
        cout << "  (C)IPHER �> �����������/����������� �����\n";
        cout << "  (M)ENU ���> ������� � ������� ����\n";
        cout << "  E(X)IT ���> ����� �� ���������\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'C':
                break;
            case 'M':
                break;
            case 'X':
                exit(0);
            default:
                cout << " ������������ ����. ������� ��� ���:\n";
                break;
            }
        } while ((answer != 'C') && (answer != 'M') && (answer != 'X'));
    } while (answer != 'M');
}

// ========================================
// const char* chooseAlphabet
// ========================================
const char* chooseAlphabet()
{
    cout << "\n �������� ���� ������ ��� (��-)����������:\n";
    cout << "  (E)NGLISH �> ����������\n";
    cout << "  (R)USSIAN �> �������\n";

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
        case 'R':
            return RUSSIAN_ALPHABET;
        default:
            cout << " ������������ ����. ������� ��� ���:\n";
            break;
        }
    } while (true);
}

// ========================================
// eCipherMode chooseMode
// ========================================
eCipherMode chooseMode()
{
    cout << "\n �������� ����� ������:\n";
    cout << "  (E)NCRYPT �> ����������\n";
    cout << "  (D)ECRYPT �> ������������\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'E':
            return ENCRYPT_MODE;
        case 'D':
            return DECRYPT_MODE;
        default:
            cout << " ������������ ����. ������� ��� ���:\n";
            break;
        }
    } while (true);
}

// ========================================
// bool getText
// ========================================
bool getText(string& strText)
{
    cout << "\n ��������:\n";
    cout << "  (K)EYBOARD �> ������ ����� ��� ������ ����������\n";
    cout << "  (F)ILE �����> ������� ����� �� �����\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'K':
            cout << "\n ������� �����:\n";
            getline(cin, strText);
            return true;
        case 'F':
            return getTextFromFile(strText);
        default:
            cout << " ������������ ����. ������� ��� ���:\n";
            break;
        }
    } while (true);
}

// ========================================
// bool getTextFromFile
// ========================================
bool getTextFromFile(string& strText)
{
    ifstream in;
    string path;

    do
    {
        cout << "\n ������� ���� � �����:\n";
        getline(cin, path);
        in.open(path);

        if (!in) {
            cout << "\n �� ������ ������� ����. ��������:\n";
            cout << "  (N)EW PATH �> ������ ������ ���� � �����\n";
            cout << "  (M)ENU �����> ������� � ���� (��-)���������\n";
            cout << "  E(X)IT �����> ����� �� ���������\n";

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
                    cout << " ������������ ����. ������� ��� ���:\n";
                    break;
                }
            } while ((answer != 'N') && (answer != 'M') && (answer != 'X'));
        }
        else
        {
            getline(in, strText);
            in.close();

            cout << "\n ����� ��� ������� ������ �� �����.\n";
            break;
        }
    } while (true);

    return true;
}

// ========================================
// void putText
// ========================================
void putText(string& strNewText)
{
    cout << "\n ����� ����� (��-)����������\n";
    cout << "  (C)ONSOLE �> ������� �� �������\n";
    cout << "  (F)ILE ����> �������� � ����\n";
    cout << "  (B)OTH ����> ������� �� ������� � �������� � ����\n";

    char answer;
    do
    {
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        answer = toupper(answer);

        switch (answer)
        {
        case 'C':
            cout << "\n ����� ����� (��-)����������:\n" << strNewText << endl;
            return;
        case 'F':
            putTextInFile(strNewText);
            return;
        case 'B':
            cout << "\n ����� ����� (��-)����������:\n" << strNewText << endl;
            putTextInFile(strNewText);
            return;
        default:
            cout << " ������������ ����. ������� ��� ���:\n";
            break;
        }
    } while (true);
}

// ========================================
// void putTextInFile
// ========================================
void putTextInFile(string& strNewText)
{
    ofstream out;
    string path;

    do
    {
        cout << "\n ������� ���� � �����:\n";
        getline(cin, path);
        out.open(path);

        if (!out) {
            cout << "\n �� ������ ������� ����. ��������:\n";
            cout << "  (N)EW PATH �> ������ ������ ���� � �����\n";
            cout << "  (M)ENU �����> ������� � ���� (��-)���������\n";
            cout << "  E(X)IT �����> ����� �� ���������\n";

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
                    cout << " ������������ ����. ������� ��� ���:\n";
                    break;
                }
            } while ((answer != 'N') && (answer != 'M') && (answer != 'X'));
        }
        else
        {
            out << strNewText;
            out.close();

            cout << "\n ����� ����� (��-)���������� ��� ������� ������� � ����.\n";
            break;
        }
    } while (true);
}

// ========================================
// void encodeDecodeWithCaesar
// ========================================
void encodeDecodeWithCaesar(string& strText, string& strNewText, const char* pALPHABET, eCipherMode& CIPHER_MODE)
{

    cout << "\n ������� �������� ������ ��� ����� ������:\n";

    int delta = 0;      // �������� ������ ��� ����� ������
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
            cout << " ������������ ����. ������� ��� ���:\n";
        }
    } while (true);

    if (CIPHER_MODE == DECRYPT_MODE) {     // ��� ������������ ����� �������������� � ������ �������
        delta *= -1;
    }

    const int ALPHABET_LENGTH = strlen(pALPHABET);

    delta %= ALPHABET_LENGTH;   // ������ ����� ���������������, ������ ����� ��������
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
                pLETTER = pALPHABET + ((pLETTER - pALPHABET + delta) % ALPHABET_LENGTH);    // �����, ���� ����� � ��������
            }
            else {
                pLETTER = &strText[i];  // ����������� ������� �� �� ��������
            }

            strNewText += *pLETTER;
        }
    }
    else {                      // ��� �������� ������ ����� �� �������������
        strNewText = strText;
    }
}

// ========================================
// char charToUpper
// ========================================
char charToUpper(const char& LETTER)            // ����������� � ������� ������� ��� �������� � ���������
{
    if (('a' <= LETTER) && (LETTER <= 'z')) {
        return LETTER + 'A' - 'a';
    }
    else if (('�' <= LETTER) && (LETTER <= '�')) {
        return LETTER + '�' - '�';
    }
    else if (LETTER == '�') {
        return '�';
    }
    else {
        return LETTER;
    }
}