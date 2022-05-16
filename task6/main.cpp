#include <iostream>

using namespace std;

struct Data {
    int a;
};

struct List {
    Data d;
    List *next;
};

List *head = NULL;
List *tail = NULL;

/* void listLasted() {
    List *x;
    List *u;
    u = new List;
    cout << "Enter the item: " << '\n';
    cin >> u->d.a;
    u->next = NULL;
    x = u;
    x->next = new List;
    x = x->next;
    x->next = NULL;
} */

void listBegin() {
    // List *u = new List;
    List *u;
    u = new List;
    cout << "Enter the item: " << '\n';
    cin >> u->d.a;
    u->next = NULL;
    if (head == NULL) {
        head = u;
        tail = u;
    } else {
        u->next = head;
        head = u;
    }
}

void listAdd() {
    // List *u = new List;
    List *u;
    u = new List;
    cout << "Enter the item: " << '\n';
    cin >> u->d.a;
    u->next = NULL;
    if (head == NULL) {
        head = u;
        tail = u;
    } else {
        tail->next = u;
        tail = u;
    }
}

void displayList() {
    cout << "Displayed list:" << '\n';
    for (List *u = head; u != NULL; u = u->next) {
        cout << u->d.a << '\n';
    }
}

void deleteList() {
    cout << "Deleted!" << '\n';
    for (; head != NULL;) {
        List *u = head;
        head = u->next;
        delete u;
    }
}

int main() {
    listBegin();
    listAdd();
    displayList();
    deleteList();
    displayList();
    /* listLasted();
    displayList();
    deleteList();
    displayList(); */
    cin.ignore();
    return 0;
}