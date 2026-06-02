#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "banana programming";

    // 1. Find a character
    cout << "Position of 'a': " << s.find('a') << endl;

    // 2. Find a substring
    cout << "Position of \"gram\": " << s.find("gram") << endl;

    // 3. Find from a specific position
    cout << "Position of 'a' starting from index 2: "
         << s.find('a', 2) << endl;

    // 4. Check if a substring exists
    if (s.find("pro") != string::npos)
        cout << "\"pro\" found" << endl;
    else
        cout << "\"pro\" not found" << endl;

    // 5. Check if a character exists
    if (s.find('z') != string::npos)
        cout << "'z' found" << endl;
    else
        cout << "'z' not found" << endl;

    // 6. Find multiple occurrences of a character
    size_t pos = s.find('a');

    cout << "All positions of 'a': ";
    while (pos != string::npos) {
        cout << pos << " ";
        pos = s.find('a', pos + 1);
    }
    cout << endl;

    return 0;
}