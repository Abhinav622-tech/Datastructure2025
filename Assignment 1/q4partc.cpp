#include <iostream>
using namespace std;

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int r = 2, c = 3;
    int T[3][2]; // transpose matrix
    int i , j;

    // Transpose
    for( i = 0; i < r; i++) {
        for( j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }

    // Print transpose
    cout << "Transpose of the matrix:" << endl;
    for(i = 0; i < c; i++) {
        for( j = 0; j < r; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}
