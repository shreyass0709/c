#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(Node* node, int key) {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
};

int main() {
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    int key;
    cout << "\n\nEnter value to search: ";
    cin >> key;

    if (tree.search(tree.root, key))
        cout << "Element found.";
    else
        cout << "Element not found.";

    return 0;
}