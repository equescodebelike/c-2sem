#include <iostream>

using namespace std;

double factorial(int f) {
    if (f < 0) {
        return 0;
    }
    if (f == 0) {
        return 1;
    } else {
        return f * factorial(f - 1);
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Введите n: \n";
    int n;
    cin >> n;
    double result = 0;
    for (int i = 1; i <= n; ++i) {
        result += i / factorial(i + 1);
    }
    printf("Ответ: %.40lf", result);

    cin.ignore();
    return 0;
}
