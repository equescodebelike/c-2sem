#include <iostream>
using namespace std;

struct LAPTOP {
    string name;
    string processor;
    string graphicsCard;
    string ram;
    string hdd;
    string ssd;
    bool isIntPrice = false;

    union
    {
        struct { int intPrice; } intPriceShop;
        struct { float floatPrice; } floatPriceShop;
    };

    void setLaptop() {
        cout << "Введите характеристики ноутбука  \n";

        cout << "Введите имя ноутбука: ";
        cin >> name;
        cout << "Введите название процессора: ";
        cin >> processor;
        cout << "Введите название видеокарты: ";
        cin >> graphicsCard;
        cout << "Введите название оперативной памяти: ";
        cin >> ram;
        cout << "Введите название hdd: ";
        cin >> hdd;
        cout << "Введите название ssd: ";
        cin >> ssd;
        getUnion();
    }

    void getUnion() {
        cout << "Если стоимость ноутбука целочисленная,то напишете 'yes', если нет - то введите любую букву ";
        string answer;
        cin >> answer;
        cout << "Введите значениe: ";
        if (answer == "yes") {
            cin >> intPriceShop.intPrice;
            isIntPrice = true;
        }
        else {
            cin >> floatPriceShop.floatPrice;
        }

    }

    void printLaptop() {
        if (isIntPrice) {

            cout << intPriceShop.intPrice;
        }
        else {
            cout << floatPriceShop.floatPrice;

        }
        cout << "\n";

        cout << name + "\n" + processor + "\n" + graphicsCard + "\n"
                + ram + "\n" + hdd + "\n" + ssd + "\n";
    }

    void deleteLaptop() {
        delete this;
    }
};

void setLaptops(LAPTOP* laptops, int n) {
    for (size_t i = 0; i < n; i++)
    {
        laptops[i].setLaptop();
        cout << "\n";
    }
}

void getAllLaprtops(LAPTOP* laptops, int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << "--------------- \n";
        laptops[i].printLaptop();
        cout << "--------------- \n";
    }

}

struct Node {
    LAPTOP laptop;
    Node* next;
};
struct ListOfLaptops {

    Node* head = NULL;
    int size = 0;

    void addLaptop(LAPTOP d)
    {
        Node* nd = new Node;
        nd->laptop = d;
        nd->next = NULL;
        if (head == NULL)
            head = nd;
        else
        {
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = nd;
        }
        size++;
    }
    Node* getNode(int index) {
        Node* nd = head;
        for (size_t i = 0; i < index; i++)
        {
            nd = nd->next;
        }
        return nd;

    }

    LAPTOP getLaptop(int index) {
        return getNode(index)->laptop;
    }

    void removeLaptop(int index) {
        Node* node = getNode(index);
        if (node == head) {
            head->next = NULL;
        }
        else {
            getNode(index - 1)->next = node->next;
        }
        size--;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int call;
    bool flag = true;
    int size = 0;

    ListOfLaptops laptops;
    while (flag) {

        cout << "_________\n";

        cout << "1. Удалить ноутбук по индексу\n";
        cout << "2. Добавить n ноутбукoв\n";
        cout << "3. Вывести все ноутбуки\n";
        cout << "4. Выйти\n";

        cout << ">";

        cin >> call;

        switch (call) {
            case 1:
                int index;
                cout << "Введите моделей ноутбука, которую вы хотите удалить: ";
                cin >> index;


                laptops.removeLaptop(index - 1);


                size--;

                break;
            case 2:
                cout << "Введите кол-во моделей ноутбука, которые вы хотите добавить: ";
                int n;
                cin >> n;
                size += n;
                for (size_t i = 0; i < n; i++)
                {
                    LAPTOP laptop;
                    laptop.setLaptop();
                    laptops.addLaptop(laptop);
                }
                break;
            case 3:
                for (size_t i = 0; i < size; i++)
                {
                    cout << "____________________\n";
                    laptops.getLaptop(i).printLaptop();
                }
                break;
            case 4:
                flag = false;
                break;
            default: cout << "Repeat input!\n";
        }
    }



    //LAPTOP* laptops = new LAPTOP[n];

    //setLaptops(laptops, n);

    //getAllLaprtops(laptops, n);

    //delete[] laptops;

    cout << "ok";
}