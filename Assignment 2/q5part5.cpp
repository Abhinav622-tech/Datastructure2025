#include <iostream>
using namespace std;

int main() {
	int i , j;
    int n = 4;
    int sym[n*(n+1)/2];
    cout << "Enter lower triangle elements (including diagonal) row-wise:\n";
    for( i=0; i<n*(n+1)/2; i++)
        cin >> sym[i];

    cout << "Symmetric Matrix:\n";
    int k=0;
    for(i=0; i<n; i++) {
        for( j=0; j<n; j++) {
            if(i>=j)
                cout << sym[k + j*(j+1)/2] << " "; // lower triangle
            else
                cout << sym[j*(j+1)/2 + i] << " "; // mirror for upper triangle
        }
        cout << endl;
    }
    return 0;
}
