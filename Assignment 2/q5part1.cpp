#include <iostream>
using namespace std;

int main() {
	int i ,j;
    int n = 4;
    int diag[4]; // store only diagonal elements
    cout << "Enter diagonal elements:\n";
    for( i=0; i<n; i++)
        cin >> diag[i];

    cout << "Diagonal Matrix:\n";
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
