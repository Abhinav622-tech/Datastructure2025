#include <bits/stdc++.h>

using namespace std;

void firstNonRepeatingCharacter(string & str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        
        freq[ch]++;
        
        q.push(ch);

        
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }

    cout << endl;
}

int main() {
    string input = "aabc";
    
    cout << "Input stream: " << input << endl;
    cout << "First Non-Repeating Characters: ";
    firstNonRepeatingCharacter(input);

    return 0;
}