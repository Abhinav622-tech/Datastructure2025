#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[3*n-2]; // store only non-zero diagonals
    cout << "Enter elements for tri-diagonal matrix (row-wise):\n";
    int i; int j;
    for( i=0; i<3*n-2; i++)
        cin >> tri[i];

    cout << "Tri-diagonal Matrix:\n";
    for(i=0; i<n; i++) {
        for( j=0; j<n; j++) {
            if(i-j == 1) cout << tri[i-1] << " ";         // lower diagonal
            else if(i-j == 0) cout << tri[n-1 + i] << " "; // main diagonal(n-1+i means skip the lower one )
            else if(j-i == 1) cout << tri[2*n-1 + i] << " "; // upper diagonal(it skips above both n-1+n
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
