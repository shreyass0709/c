#include <iostream>
#include <string>
using namespace std;

int main() {

    string s1 = "Hello";
    string s2 = " World";

    s1.append(s2);
    cout << "After append string: " << s1 << endl;

    string s3 = "Coding";
    s3.append(" Ninja");
    cout << "Append literal: " << s3 << endl;

    string s4 = "Hello ";
    string s5 = "Programming";
    s4.append(s5, 0, 7);
    cout << "Append part of string: " << s4 << endl;

    string s6 = "Hi";
    s6.append(5, '!');
    cout << "Append characters: " << s6 << endl;

    return 0;
}