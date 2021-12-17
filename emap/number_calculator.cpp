#include "number_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const static unsigned MAX_NESTING_VALUE = 100;

static stringstream g_expression;
static eTokenValue g_currentToken = eTokenValue::PRINT;
static double g_numberValue = 0;
static string g_stringValue = "";
static int g_bracketsCount = 0;
static unsigned g_nestingChecker = 0;

void numberCalculator()
{
    system("CLS");

    cout << "\n Лікавы калькулятар.\n";
    cout << " Вылічвае значэнне уведзенага выразу.\n";
    cout << " Падтрымлівае выкарыстанне ў выразе аператараў +, -, *, /, ^, () з карэктным парадкам вылічэнняў.\n";
    cout << " Прыклад:\n";
    cout << "         выраз: 2.5 + (3^2 - 4 * 5)/11\n";
    cout << "         вынік: 1.5\n";

    char answer;
    do
    {
        cout << "\n Абярыце:\n";
        cout << "  1 ——> вылічыць значэнне арыфметычнага выразу\n";
        cout << "  2 ——> перайсці ў галоўнае меню\n";
        cout << "  3 ——> выйсці з праграмы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (answer)
            {
            case '1':
            {
                cout << "\n Увядзіце арыфметычны выраз:\n";
                string exp;
                getline(cin, exp);

                g_expression.str("");
                g_expression.clear();
                g_numberValue = 0;
                g_bracketsCount = 0;
                g_nestingChecker = 0;

                g_expression << exp;

                getToken();

                try
                {
                    exp = to_string(expr(false));
                    cout << "\n Значэнне выразу: " << exp << '\n';
                }
                catch (CalcException& err) {
                    cerr << "\n Памылка: " << err.what() << '\n';
                }
                catch (...) {
                    cerr << "\n Чэл, ты нашто калькулятар зламаў...\n";
                }
            }
            break;
            case '2':
                return;
            case '3':
                exit(0);
            default:
                cout << " Некарэктны ўвод. Увядзіце яшчэ раз:\n";
                break;
            }
        } while ((answer < '1') || (answer > '3'));
    } while (true);
}

double expr(bool get)
{
    if (++g_nestingChecker > MAX_NESTING_VALUE) {
        throw CalcException("надта складаны выраз");
    }

    double left = term(get);

    while (true)
    {
        switch (g_currentToken)
        {
        case eTokenValue::PLUS:
            left += term(true);
            break;
        case eTokenValue::MINUS:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

double term(bool get)
{
    if (++g_nestingChecker > MAX_NESTING_VALUE) {
        throw CalcException("надта складаны выраз");
    }

    double left = prim(get);
    while (true)
    {
        switch (g_currentToken)
        {
        case eTokenValue::MUL:
            left *= prim(true);
            break;
        case eTokenValue::DIV:
            if (double d = prim(true)) {
                left /= d;
                break;
            }
            else {
                throw CalcException("дзяленне на 0");
            }
        case eTokenValue::LP:
            throw CalcException("сустрэты нечаканы аператар (");
        case eTokenValue::RP:
            g_bracketsCount--;
            if (g_bracketsCount < 0) {
                throw CalcException("сустрэты нечаканы аператар )");
            }
            return left;
        case eTokenValue::NUMBER:
            throw CalcException("сустрэта нечаканая дзесятковая кропка");
        default:
            return left;
        }
    }
}

double prim(bool get)
{
    if (++g_nestingChecker > MAX_NESTING_VALUE) {
        throw CalcException("надта складаны выраз");
    }

    double value = 0;

    if (get) {
        getToken();
    }
    switch (g_currentToken)
    {
    case eTokenValue::NUMBER:
    {
        value = g_numberValue;
        getToken();
        break;
    }
    case eTokenValue::PLUS:
        value = prim(true);
        break;
    case eTokenValue::MINUS:
        value = -prim(true);
        break;
    case eTokenValue::LP:
    {
        g_bracketsCount++;
        value = expr(true);
        if (g_currentToken != eTokenValue::RP) {
            throw CalcException("чакалася )");
        }
        getToken();
    }
    break;
    case eTokenValue::WORD:
    {
        if ((g_stringValue == "sin") ||
            (g_stringValue == "cos") ||
            (g_stringValue == "tan") ||
            (g_stringValue == "cot"))
        {
            getToken();
            if (g_currentToken == eTokenValue::LP)
            {
                g_expression.putback('(');
                value = prim(true);

                if (g_stringValue == "sin") {
                    value = sin(value);
                }
                else if (g_stringValue == "cos") {
                    value = cos(value);
                }
                else if (g_stringValue == "tan") {
                    if (cos(value)) {
                        value = tan(value);
                    }
                    else {
                        throw CalcException((string)"нельга вылічыць тангенс pi/2");
                    }
                }
                else if (g_stringValue == "cot") {
                    if (sin(value)) {
                        value = cos(value) / sin(value);
                    }
                    else {
                        throw CalcException((string)"нельга вылічыць катангенс 0");
                    }
                }
            }
            else {
                throw CalcException("чакалася (");
            }
        }
        else {
            throw CalcException((string)"сустрэты невядомы сімвал " + g_stringValue[0]);
        }
    }
    break;
    default:
        throw CalcException("чакаўся першасны выраз");
    }

    while (true)
    {
        switch (g_currentToken)
        {
        case eTokenValue::POW:
        {
            double powerValue = prim(true);
            if ((value == 0) && (powerValue == 0)) {
                throw CalcException("узвядзенне 0 у ступень 0");
            }
            return pow(value, powerValue);
        }
        default:
            return value;
        }
    }
}

eTokenValue getToken()
{
    char ch;

    do
    {
        if (!g_expression.get(ch)) {
            return g_currentToken = eTokenValue::PRINT;
        }
    } while (ch != '\n' && isspace((unsigned char)ch));

    switch (ch)
    {
    case '\n':
    case 0:
        return g_currentToken = eTokenValue::PRINT;
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
        return g_currentToken = (eTokenValue)ch;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        g_expression.putback(ch);
        g_expression >> g_numberValue;
        return g_currentToken = eTokenValue::NUMBER;

    default:
        if (isalpha(ch))
        {
            g_stringValue = ch;
            while (g_expression.get(ch) && isalpha(ch)) {
                g_stringValue.push_back(ch);
            }
            g_expression.putback(ch);
            return g_currentToken = eTokenValue::WORD;
        }
        throw CalcException((string)"сустрэты невядомы сімвал " + ch);
    }
}