#include "number_calculator.h"
#include <iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;
istream* input;
void numberCalculator(int argc,char* argv[])
{
    system("CLS");

    cout << "\n Числовой калькулятор.\n";
    cout << " Вычисляет значение введённого арифметического выражения.\n";
    cout << " Поддерживает использование в выражении операторов + , -, *, / , () с корректным порядком вычислений.\n";
    cout << " Поддерживает использование в выражении констант pi и e.\n";
    cout << " Пример:\n";
    cout << "         выражение: 2.5 + (3 - 4 * 5)/17\n";
    cout << "         результат: 1.5\n";

    table["pi"] = 3.14159265358;
    table["e"] = 2.7182818284;

    

    char answer;
    do
    {
        cout << "\n Выберите:\n";
        cout << "  (C)ALCULATE —> вычислить значение арифметического выражения\n";
        cout << "  (M)ENU ——————> перейти в главное меню\n";
        cout << "  E(X)IT ——————> выйти из программы\n";

        do {
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            answer = toupper(answer);

            switch (answer)
            {
            case 'C':
                cout << "\n Введите арифметическое выражение:\n";
                
                while(input) {
                    get_token();
                    if (curr_tok == END)break;
                    if (curr_tok == PRINT)continue;
                    cout << expr(false) << '\n';
                   }
                if (input != &cin)delete input;
                return no_of_errors;

                break;
            case 'M':
                return;
            case 'X':
                exit(0);
            default:
                cout << " Некорректный ввод. Введите ещё раз:\n";
                break;
            }
        } while (answer != 'C');
    } while (true);
}
enum Token_value {
    NAME, NUMBER, END,
    PLUS='+', MINUS='-', MUL='*',DIV='/',
    PRINT=',', ASSIGN='=', LP='{', RP='}'
};

double expr(bool get) {
    double left = term(get);
        for(,,)
            switch (curr_tok) {
                case MUL
                    left *= prim(true);
                    break;
                case DIV
                    if (double d = prim(true)) {
                        left /= d;
                            break;
                    }
                return error("деление на 0");
                default:
                    return left;
            }
}
double term(bool get)
{
    double left = prim(get);
    for(,,)
        switch (curr_tok) {
            case MUL
                left *= prim(true);
                break;
                case DIV
                    if (double d = prim(true)) {
                        left /= d;
                        break;
                    }
                return error("деление на 0");
                default:
                    return left;
        
        }
}
double number_value;
double string_value;
double prim(bool get)
{
    if (get) get_token();
    switch (curr_tok)
    {
    case NUMBER: {
        double v = number_value;
        get_token();
        return v;
    }
    case NAME: {
        double& v = table[string_value];
        if (get_token() == ASSIGN) v = expr(true);
        return v;
    }
    case MINUS: {
        return -prim(true);
    }
    case LP: {
        double e = expr(true);
        if (curr_tok != RP) return error("ожидалось");
        get_token();
        return e;
    }
    default:
        return error("ожидалось первичное выражение");
    }
}
Token_value get_token()
{
    char ch = 0;
    cin >> ch;
    switch (ch) {
    case 0:
        return curr_tok = END;
    case ';':
    case'*':
    case'/':
    case'+':
    case'-':
    case'(':
    case')':
    case'=':
        return curr_tok = Token_value(ch);
    case'0':case'1':case'2':case'3':
    case'4':case'5':case'6':case'7':
    case'8':case'9':case'.':
        cin.putback(ch);
        cin >> number_value;
        return curr_tok = NUMBER;
    default:
        if (isalpha(ch)) {
            cin.putback(ch);
            cin >> string_value;
            return curr_tok = NAME;
        }
        error("неправельная лексема");
        return curr_tok = PRINT;
    }
}
int no_of_errors;
int error(const string& s)
{
    no_of_errors++;
    cerr << "ошибка" << s << '\n';
    return 1;
}

// Сюда вставь реализацию всех функций