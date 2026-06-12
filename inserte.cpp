#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    display(head);

    return 0;
}