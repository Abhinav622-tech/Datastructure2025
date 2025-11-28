#include <iostream>
#include <string>
using namespace std;

bool isCommonSubstring(const string &common, const string &other1, const string &other2) {
    return (other1.find(common) != (size_t)-1 && other2.find(common) != (size_t)-1);
}

bool canSplit(const string &s) {
	int i;
	int j;
    int n = s.length();
    for ( i = 1; i <= n - 2; i++) {
        for ( j = i + 1; j <= n - 1; j++) {
            string P1 = s.substr(0, i);
            string P2 = s.substr(i, j - i);
            string P3 = s.substr(j);

            if (isCommonSubstring(P1, P2, P3) ||isCommonSubstring(P2, P1, P3)||isCommonSubstring(P3, P1, P2))
                
                 {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    if (canSplit(s))
        cout << "YES, it can be split!" << endl;
    else
        cout << "NO, it cannot be split!" << endl;

    return 0;
}
