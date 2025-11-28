#include <iostream>
using namespace std;

int main() {
	int i , j;
    int n = 4;
    int lower[n*(n+1)/2];
    cout << "Enter lower triangular elements row-wise:\n";
    for(i=0; i<n*(n+1)/2; i++)
        cin >> lower[i];

    cout << "Lower Triangular Matrix:\n";
    int k=0;
    for(i=0; i<n; i++) {
        for( j=0; j<n; j++) {
            if(i>=j)
                cout << lower[k+1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}

