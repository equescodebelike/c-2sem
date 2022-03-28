#include <iostream>

using namespace std;

int main() {

    int len;
    cout << "Arr length: \n";
    cin >> len;
    char arr[len];
    cout << "Arr elements: \n";
    for (int i = 0; i < len; ++i) {
        cin >> *(arr + i);
    }

    /* for (int i = 0, c = 1; i < len; ++i, c++) {
        if (c % 3 == 0) {
            cout << *(arr + i);
        }
    } */

    // char *p = arr; первый элемент в массиве
    for (int i = 2; i < len; i += 3) {
        cout << *(arr + i);
    }

    cin.ignore();
    return 0;
}
