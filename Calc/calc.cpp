#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Введите a: \n";
    int a;
    cin >> a;
    cout << "Введите b: \n";
    int b;
    cin >> b;
    cout << "Выберите операцию: + - * / \n";

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
                cout << "Error \n";
            } else {
                cout << "Ответ: " << a / b << '\n';
                break;
            }
        }
        default:
            cout << "Error \n";
    }

    cin.ignore();
    return 0;

}
