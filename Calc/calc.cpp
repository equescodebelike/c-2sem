#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "������� ������ �����: \n";
    int a;
    cin >> a;
    cout << "������� ������ �����: \n";
    int b;
    cin >> b;
    cout << "�������� ���� �� ������������ �������� (������� ����): + ��������, - ���������, * ���������, / ������� \n";

    char operation;
    cin >> operation;

    switch (operation) {
        case '+': {
            cout << "�����: " << a + b << '\n';
            break;
        }
        case '-': {
            cout << "�����: " << a - b << '\n';
            break;
        }
        case '*': {
            cout << "�����: " << a * b << '\n';
            break;
        }
        case '/': {
            if (b == 0) {
                cout << "������: ������� �� ���� \n";
            } else {
                cout << "�����: " << a / b << '\n';
                break;
            }
        }
        default:
            cout << "������: ������������ �������� \n";
    }

    cin.ignore();
    return 0;

}
