#include <iostream>

using namespace std;

struct Human {
    char Case;
    char Surname[10];
    union {
        struct {
            int Age;
        } male;
        struct {
            int Age;
        } female;
    };
};

Human createHuman() {
    Human st;
    cout << "Input M or F" << '\n';
    cin >> st.Case;
    cout << "Surname: \n";
    cin >> st.Surname;
    switch (st.Case) {
        case 'M':
            cout << "Age: \n";
            cin >> st.male.Age;
            break;
        case 'F':
            cout << "Age: \n";
            cin >> st.female.Age;
            break;
        default:
            cout << "Error: \n";
    }
    return st;
}

void output(Human st) {
    cout << st.Surname;
    switch (st.Case) {
        case 'M':
            cout << " | " << st.male.Age << " years" << " | " << "Male" << '\n';
            break;
        case 'F':
            cout << " | " << st.female.Age << " years" << " | " << "Female" << '\n';
            break;
    }
}

Human *deleteSt(Human *stArr, int index, int n) {
    index--;
    for (int i = index + 1; i < n; i++) {
        stArr[i - 1] = stArr[i];
    }
    return stArr;
}

int main() {
    int n = 10;
    Human humanData[10],
            std = {0, ""};

    int i;
    for (i = 0; i < sizeof(humanData) / sizeof(Human); i++) {
        humanData[i] = std;
    }

    while (1) {
        cout << '\n';
        cout << "1 - input" << '\n' << "2 - output" << '\n' << "3 - delete" << '\n'
             << "4 - end" << '\n';
        cin >> i;
        switch (i) {
            case 1:
                cout << "Position:" << '\n';
                cin >> i;
                humanData[i] = createHuman();
                break;

            case 2:
                cout << "Position:" << '\n';
                cin >> i;
                output(humanData[i]);
                break;

            case 3:
                cout << "Position:" << '\n';
                cin >> i;
                deleteSt(humanData, i, n);
                n--;
                break;

            case 4:
                cin.ignore();
                return 0;

            default:
                cout << "Error" << '\n';
                break;
        }

    }

}