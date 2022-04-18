#include <iostream>

using namespace std;

const unsigned int row = 2;
const unsigned int col = 3;

string arr[row * col];
string arr2[row * col];

int main() {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(arr + i * col + j);
            cout << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(arr2 + i * col + j) = *(arr + i * col + j) + *(arr + i * col + j);
            cout << *(arr2 + i * col + j);
            cout << " ";
        }
        cout << "\n";
    }

    cin.ignore();
    return 0;
}
