#include <iostream>
using namespace std;

int main() {
	int i , j;
    int n = 4;
    int upper[n*(n+1)/2];
    cout << "Enter upper triangular elements row-wise:\n";
    for( i=0; i<n*(n+1)/2; i++)
        cin >> upper[i];

    cout << "Upper Triangular Matrix:\n";
    int k=0;
    for( i=0; i<n; i++) {
        for( j=0; j<n; j++) {
            if(i<=j)
                cout << upper[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}

