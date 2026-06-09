#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool prime = true;

    if (n <= 1)
        prime = false;
    else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
    }

    if (prime)
        cout << n << " is Prime";
    else
        cout << n << " is Not Prime";

    return 0;
}