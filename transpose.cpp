#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[100][100];

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose Matrix:\n";

    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}