#include <iostream>

using namespace std;

struct Data {
    string Name;
    string surname;
    int age;
    int height;
};

struct List {
    Data a;
    List *next;
};

void getInfo(List *u) {
    cout << "�������� ��������� Man:";
    cout << u->a.Name << " " << u->a.surname << " " << u->a.height << " " << u->a.age;
}

void deleteList(List *head) {
    cout << "Deleted!" << '\n';
    for (; head != NULL;) {
        List *u = head;
        head = u->next;
        delete u;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ���������� �������:";
    cin >> n;
    List *u;
    u = new List;
    List *head = u;

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            u->next = NULL;
            cout << "������� ����� " << i + 1 << endl;

            cout << "������� �������� ����� ������ Man:" << endl;
            cout << "������� ��� ��������:" << endl;
            cin >> u->a.Name;
            cout << "������� ������� ��������:" << endl;
            cin >> u->a.surname;
            cout << "������� ���� ��������:" << endl;
            cin >> u->a.height;
            cout << "������� ������� ��������:" << endl;
            cin >> u->a.age;
        } else {
            u->next = new List;
            cout << "������� ����� " << i + 1 << endl;
            cout << "������� �������� ����� ������ Man:" << endl;
            cout << "������� ��� ��������:" << endl;
            cin >> u->a.Name;
            cout << "������� ������� ��������:" << endl;
            cin >> u->a.surname;
            cout << "������� ���� ��������:" << endl;
            cin >> u->a.height;
            cout << "������� ������� ��������:" << endl;
            cin >> u->a.age;
            u = u->next;
        }
    }

    u = head;

    for (int i = 0; i < n; i++) {
        getInfo(u);
        u = u->next;
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        head = u->next;
        delete u;
    }

}