#include <iostream>
#include <queue>
using namespace std;

// Stack using two queues
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) { cout << "Empty\n"; return; }
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
};

// Stack using one queue
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int s = q.size();
        for (int i = 0; i < s-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Empty\n"; return; }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {
    StackTwoQ s1;
    StackOneQ s2;

    s1.push(10); s1.push(20); s1.push(30);
    cout << "Top (two queues): " << s1.top() << "\n";

    s2.push(5); s2.push(15); s2.push(25);
    cout << "Top (one queue): " << s2.top() << "\n";
}
