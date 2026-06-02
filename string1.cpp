#include<iostream>
#include<string>
using namespace std;

int main() {
    string name;
    string dept;
    string grade;
    cout<< "Enter your name,dept,grade:"<<endl;
    getline(cin, name);
    getline(cin, dept);
    getline(cin, grade);
    cout<< "Name: " << name << endl;
    cout<< "Department: " << dept << endl;
    cout<< "Grade: " << grade << endl;
    return 0;
}