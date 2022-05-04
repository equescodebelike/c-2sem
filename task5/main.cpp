#include <iostream>

using namespace std;

struct Student {
    char Surname[10];
    int Course;
    int Group;
};

Student createStudent() {
    Student st;
    cout << "Surname: \n";
    cin >> st.Surname;
    cout << "Course: \n";
    cin >> st.Course;
    cout << "Group: \n";
    cin >> st.Group;
    return st;
}

void output(Student st) {
    cout << st.Surname << " | " << st.Course << " | " << st.Group << '\n';
}

Student &addCourse(Student &st, int course) {
    st.Course += course;
    return st;
}

int main() {
    Student
            st1 = {"Ivanov", 1, 3},
            st2 = {"Petrov", 2, 5},
            st3 = {"Vodkin", 5, 1},
            customSt;

    output(st1);
    output(st2);
    output(st3);

    output(addCourse(st1, 1));

    customSt = createStudent();
    output(customSt);

    cin.ignore();
    return 0;
}