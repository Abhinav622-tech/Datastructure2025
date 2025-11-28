#include <iostream>
#include <string>
using namespace std;
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}


int main() {
	int n;
	cin>>n;
	cin.ignore();
    string arr[n];   // array of 5 strings

    cout << "Enter n strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    //Alph
    for (int i = 0; i < n-1; i++) {             // passes
        for (int j = 0; j < n -i-1; j++) {     // comparisons
            if (arr[j] > arr[j + 1]) {        // string comparison (lexicographical)
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
