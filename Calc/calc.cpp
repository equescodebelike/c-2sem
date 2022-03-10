#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Введите первое число: \n";
    int a;
    cin >> a;
    cout << "Введите второе число: \n";
    int b;
    cin >> b;
    cout << "Выберите одну из предложенных операций (введите знак): + сложение, - вычитание, * умножение, / деление \n";

    char operation;
    cin >> operation;

    switch (operation) {
        case '+': {
            cout << "Ответ: " << a + b << '\n';
            break;
        }
        case '-': {
            cout << "Ответ: " << a - b << '\n';
            break;
        }
        case '*': {
            cout << "Ответ: " << a * b << '\n';
            break;
        }
        case '/': {
            if (b == 0) {
                cout << "Ошибка: деление на ноль \n";
            } else {
                cout << "Ответ: " << a / b << '\n';
                break;
            }
        }
        default:
            cout << "Ошибка: некорректная операция \n";
    }

    cin.ignore();
    return 0;

}
