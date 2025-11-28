#include <iostream>
using namespace std;

int main() {
	int i , j ,k;
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {0}; // result matrix

    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;

    if(c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    // Multiply
    for( i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            for( k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result
    cout << "Matrix multiplication result:" << endl;
    for( i = 0; i < r1; i++) {
        for( j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
