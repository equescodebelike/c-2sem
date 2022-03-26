#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Привет, мир \n";
    cout << "Hello, world \n";
    int n = 5;
    cin >> n;
    n = n * 5;
    cout << "n = " << (double) n/3;
    return 0;
}
