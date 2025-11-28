#include<iostream>
using namespace std;

#define MAXLEN 100 

struct Stack {
    int element[MAXLEN];  
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack& S) { //pass by referance
    return (S.top == -1);
}

bool isFull(Stack& S) {
    return (S.top == MAXLEN - 1);
}

int peek(Stack& S) {
    if (isEmpty(S)) {
        cout << "Empty Stack" << endl;
        return -1; 
    } else {
        return S.element[S.top];
    }
}

void push(Stack& S, int x) {
    if (isFull(S)) {
        cout << "Overflow" << endl;
    } else {
        S.top++;
        S.element[S.top] = x;
    }
}

void pop(Stack& S) {
    if (isEmpty(S)) {
        cout << "Underflow" << endl;
    } else {
        S.top--;
    }
}

void print(Stack& S) {
    for (int i = S.top; i >= 0; --i) {
        cout << S.element[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack myStack = init(); //initialized 
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    print(myStack); // 30 20 10
    pop(myStack);
    pop(myStack);
    pop(myStack);
    pop(myStack);
    peek(myStack);
    
   
    return 0;
}



