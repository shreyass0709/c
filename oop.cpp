#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void getData() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    }
};

int main() {
    Student s;

    s.getData();
    s.display();

    return 0;
}