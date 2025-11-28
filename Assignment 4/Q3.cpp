#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    
    // If queue has odd number of elements or is empty, no interleaving needed
    if (n <= 1 || n % 2 != 0) {
        cout << "Queue should have even number of elements for proper interleaving." << endl;
        return;
    }
    queue <int>q1;
    queue <int>q2;
    int half = n / 2;
    int i=0;
    for(;i<half;i++){
        q1.push(q.front());
        q.pop();
    }
    for(;i<n;i++){
        q2.push(q.front());
        q.pop();
    }
    for(i=0;i<n;i++){
        if(i%2==0) {q.push(q1.front()); q1.pop();}
        else {q.push(q2.front());q2.pop();}
    }
    

    
}
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main() {
    queue<int> q;
    
   
    vector<int> sample = {4, 7, 11, 20, 5, 9};
    
    for (int x : sample) {
        q.push(x);
    }
    
    cout << "Original queue: ";
    printQueue(q);
    
   
    
    interleaveQueue(q);
    
    cout << "Interleaved queue: ";
    printQueue(q);
    
    return 0;
}
