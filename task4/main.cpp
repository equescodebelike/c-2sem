#include <iostream>

using namespace std;

const int row = 2;
const int col = 3;

// string arr[row * col];
// string arr2[row * col];

string **array_set() {
    string **arr = new string *[row]; // функция для создания двумерного динамического массива
    for (int i = 0; i < row; i++) {
        arr[i] = new string[col];
    }
    return arr;
}

string **convert(string **arr) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = arr[i][j] + arr[i][j];
            cout << arr[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    return arr;
}

int main() {

    /* for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(arr + i * col + j);
            cout << " ";
        }
        cout << "\n";
    } */

    string **arr;
    string **arr_result;
    arr = array_set();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            cout << " ";
        }
        cout << "\n";
    }

    arr_result = convert(arr);

    /* for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(arr2 + i * col + j) = *(arr + i * col + j) + *(arr + i * col + j);
            cout << *(arr2 + i * col + j);
            cout << " ";
        }
        cout << "\n";
    } */

    cin.ignore();
    return 0;
}

