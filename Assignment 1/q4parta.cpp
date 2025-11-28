#include <iostream>
using namespace std;
void rev(int A[],int n){
	int i = 0;        
    int j = n - 1;    

    while(i <= j) {  
        
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        i++;  // move start forward
        j--;  // move end backward
    }
}

int main() {
    int A[] = {6,7,1,2,3};
    int n = sizeof(A) / sizeof(int);

    rev(A,n);

    cout << "Reversed array: ";
    int k;
    for( k = 0; k < n; k++) {
        cout << A[k] << " ";
    }
    cout << endl;
}
