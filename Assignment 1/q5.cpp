#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Hey! Enter number of rows: ";
    cin >> rows;
    cout << "Cool, now enter number of columns: ";
    cin >> cols;

    int arr[10][10]; // keeping it simple, max 10x10
int i , j;
    // Taking input for the array
    cout << "Enter the elements row by row:\n";
    for( i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Calculating sum of each row
    for( i = 0; i < rows; i++) {
        int sumRow = 0;
        for( j = 0; j < cols; j++) {
            sumRow += arr[i][j];
        }
        cout << "Sum of row " << i+1 << " is " << sumRow << endl;
    }

    // Calculating sum of each column
    for( j = 0; j < cols; j++) {
        int sumCol = 0;
        for( i = 0; i < rows; i++) {
            sumCol += arr[i][j];
        }
        cout << "Sum of column " << j+1 << " is " << sumCol << endl;
    }

    cout << "Done! All sums calculated successfully." << endl;
    return 0;
}
