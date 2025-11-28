#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

// Function to print triplet matrix
void printTriplets(Triplet matrix[], int size) {
    cout << "Row Col Value\n";
    for(int i=0; i<size; i++) {
        cout << matrix[i].row << "   " << matrix[i].col << "   " << matrix[i].val << endl;
    }
}

// Function to transpose
int transpose(Triplet A[], Triplet At[], int size) {
    for(int i=0; i<size; i++) {
        At[i].row = A[i].col;
        At[i].col = A[i].row;
        At[i].val = A[i].val;
    }
    return size; // number of non-zero elements
}

// Function to add two sparse matrices
int add(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet sum[]) {
    int i=0, j=0, k=0;
    while(i<sizeA && j<sizeB) {
        if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            sum[k++] = A[i++];
        } else if(B[j].row < A[i].row || (A[i].row == B[j].row && B[j].col < A[i].col)) {
            sum[k++] = B[j++];
        } else {
            int s = A[i].val + B[j].val;
            if(s != 0) {
                sum[k].row = A[i].row;
                sum[k].col = A[i].col;
                sum[k].val = s;
                k++;
            }
            i++; j++;
        }
    }
    while(i<sizeA) sum[k++] = A[i++];
    while(j<sizeB) sum[k++] = B[j++];
    return k; // size of sum matrix
}

int main() {
    Triplet A[100] = {{0,2,3}, {1,0,4}, {2,1,5}};
    int sizeA = 3;

    Triplet B[100] = {{0,2,2}, {1,1,7}, {2,1,1}};
    int sizeB = 3;

    cout << "---Matrix A---\n";
    printTriplets(A, sizeA);

    Triplet At[100];
    int sizeAt = transpose(A, At, sizeA);
    cout << "\n---Transpose of A---\n";
    printTriplets(At, sizeAt);

    Triplet sum[100];
    int sizeSum = add(A, sizeA, B, sizeB, sum);
    cout << "\n---Addition A + B---\n";
    printTriplets(sum, sizeSum);

    return 0;
}

