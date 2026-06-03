#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int choice, value;

    do {
        cout << "\n--- Queue Operations ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.push(value);
                cout << value << " inserted into queue.\n";
                break;

            case 2:
                if(q.empty()) {
                    cout << "Queue is empty!\n";
                } else {
                    cout << q.front() << " removed from queue.\n";
                    q.pop();
                }
                break;

            case 3:
                if(q.empty()) {
                    cout << "Queue is empty!\n";
                } else {
                    cout << "Front element: " << q.front() << endl;
                }
                break;

            case 4:
                if(q.empty()) {
                    cout << "Queue is empty!\n";
                } else {
                    queue<int> temp = q;
                    cout << "Queue elements: ";
                    while(!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}