#include <iostream>
#include <string>
using namespace std;
void toLowercase(string &A){
	for (int i = 0; i < A.length(); i++) {
        if (A[i] >= 'A' && A[i] <= 'Z') {   // check uppercase
            A[i] = A[i] + 32;               // convert to lowercase
        }
    }
}
int main() {
    string str;
    cout << "Enter a string in uppercase: ";
    getline(cin, str);

    toLowercase(str);

    cout << "Lowercase string: " << str << endl;
    return 0;
}

