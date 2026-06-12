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

void deleteNode(Node* &head, int key) {

    if(head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL &&
          temp->next->data != key)
        temp = temp->next;

    if(temp->next != NULL) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}