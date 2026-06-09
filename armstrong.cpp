#include <iostream>
using namespace std;

int main() {
    int num, original, rem, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num > 0) {
        rem = num % 10;
        sum += rem * rem * rem;
        num /= 10;
    }

    if (sum == original)
        cout << "Armstrong Number";
    else
        cout << "Not an Armstrong Number";

    return 0;
}