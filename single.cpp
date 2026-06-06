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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at given position (0-based indexing)
    void insertAtPosition(int val, int pos) {
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Delete at given position (0-based indexing)
    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 0) {
            deleteBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Initial List:\n";
    list.display();

    list.insertAtPosition(25, 2);

    cout << "\nAfter inserting 25 at position 2:\n";
    list.display();

    list.deleteBeginning();

    cout << "\nAfter deleting from beginning:\n";
    list.display();

    list.deleteEnd();

    cout << "\nAfter deleting from end:\n";
    list.display();

    list.deletePosition(1);

    cout << "\nAfter deleting position 1:\n";
    list.display();

    return 0;
}