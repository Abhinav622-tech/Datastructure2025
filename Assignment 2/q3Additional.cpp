#include <iostream>
#include <string>
#include <cctype> // for isalpha and tolower

using namespace std;

bool areAnagrams(string str1, string str2) {
    int count[26] = {0};
    int i ;

    // Count letters in str1
    for ( i = 0; i < str1.length(); i++) {
        if (isalpha(str1[i]))
            count[tolower(str1[i]) - 'a']++;
    }

    // Subtract letters in str2
    for ( i = 0; i < str2.length(); i++) {
        if (isalpha(str2[i]))
            count[tolower(str2[i]) - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin, str1); // read string with spaces
    cout << "Enter second string: ";
    getline(cin, str2);

    if (areAnagrams(str1, str2))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}

