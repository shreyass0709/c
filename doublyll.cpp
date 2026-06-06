#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert at End
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
        newNode->prev = temp;
    }

    // Insert at Position (0-based indexing)
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
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from End
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

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    // Delete at Position (0-based indexing)
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

        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Display Forward
    void displayForward() {
        Node* temp = head;

        cout << "NULL <-> ";

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display Backward
    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "NULL <-> ";

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(20);
    dll.insertAtBeginning(10);

    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Initial List:\n";
    dll.displayForward();

    dll.insertAtPosition(25, 2);

    cout << "\nAfter inserting 25 at position 2:\n";
    dll.displayForward();

    dll.deleteBeginning();

    cout << "\nAfter deleting beginning:\n";
    dll.displayForward();

    dll.deleteEnd();

    cout << "\nAfter deleting end:\n";
    dll.displayForward();

    dll.deletePosition(1);

    cout << "\nAfter deleting position 1:\n";
    dll.displayForward();

    cout << "\nDisplay Backward:\n";
    dll.displayBackward();

    return 0;
}