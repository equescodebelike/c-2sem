#include <iostream>

using namespace std;

struct Human {
    Human *Next;   // Указатель на следующую структуру в списке
    char Case;
    char Surname[10];
    union {
        struct {
            int AgeM;
        } male;
        struct {
            int AgeF;
        } female;
    };
};

Human *DataBase = NULL; // Указатель начала списка - базы данных

Human createHuman() {
    Human human;
    cout << "Input M or F" << '\n';
    cin >> human.Case;
    cout << "Surname: \n";
    cin >> human.Surname;
    switch (human.Case) {
        case 'M':
            cout << "Age: \n";
            cin >> human.male.AgeM;
            break;
        case 'F':
            cout << "Age: \n";
            cin >> human.female.AgeF;
            break;
        default:
            cout << "Error: \n";
    }
    return human;
}

void output(Human st) {
    cout << st.Surname;
    switch (st.Case) {
        case 'M':
            cout << " | " << st.male.AgeM << " years" << " | " << "Male" << '\n';
            break;
        case 'F':
            cout << " | " << st.female.AgeF << " years" << " | " << "Female" << '\n';
            break;
    }
}

/* Поиск в списке абонента с заданным порядковым номером num в списке
(нумеруем, начиная с 0):   */
Human *humanSearch(int num) {
    Human *p;
    p = DataBase;
    while (p != NULL && num--) {  // Пока не конец списка и не найден номер,
        p = p->Next;
    }// продвигаем указатель вдоль списка.
    return p;   // Возвращаем указатель на найденный элемент или NULL,
}

void addHuman(int num) {
    Human *q;
    q = new Human;// Создали новую структуру.
    *q = createHuman();    // Заполнили ее информацией.
    if (DataBase == NULL) {
        num = 0;
    }   // Если список пустой - добавим в начало.
    if (num) { // > 0 - true
        Human *p = DataBase;      // Ищем указатель
        while (p->Next != NULL && --num) {// на предыдущую структуру.
            p = p->Next;
        }
        q->Next = p->Next;
        p->Next = q;// Вставляем новую структуру после *p
    } else {
        q->Next = DataBase;
        DataBase = q;
    } // Добавим в начало списка.
}

// Удалить абонента с номером num из списка:
void deleteHuman(int num) {
    Human *q;
    if (DataBase == NULL) return;
    if (num) {
        Human *p;
        p = DataBase;// Ищем указатель на предыдущую структуру.
        while (p->Next != NULL && --num) {
            p = p->Next;
        }
        if ((q = p->Next) != NULL) {
            p->Next = q->Next;
            delete q;
        }
    }                           // Удаляем начальный элемент:
    else {
        q = DataBase;
        DataBase = q->Next;
        delete q;
    }
}

int main() {
    Human *p;
    int i;
    while (1) {
        cout << '\n';
        cout << "1 - input" << '\n' << "2 - output" << '\n' << "3 - delete" << '\n'
             << "4 - end" << '\n';
        cin >> i;
        switch (i) {
            case 1:
                cout << "Position:" << '\n';
                cin >> i;
                addHuman(i);
                break;
            case 2:
                cout << "Position:" << '\n';
                cin >> i;
                if ((p = humanSearch(i)) != NULL) {
                    output(*p);
                } else {
                    cout << "Not found" << '\n';
                }
                break;
            case 3:
                cout << "Position:" << '\n';
                cin >> i;
                deleteHuman(i);
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