#include<iostream>
using namespace std;

#define MAXLEN 100 //we degfined the length

struct Stack {
    char element[MAXLEN]; 
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack& S) { //pass by Adress
    return (S.top == -1);
}

bool isFull(Stack& S) {
    return (S.top == MAXLEN - 1);
}

int topElement(Stack& S) {
    if (isEmpty(S)) {
        cout << "Empty Stack" << endl;
        return -1; // Sentinel value
    } else {
        return S.element[S.top];
    }
}

void push(Stack& S, char x) {
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
    for (int i = 0; i<=S.top; ++i) {
        cout << S.element[i] << " ";
    }
    cout << endl;
}
bool isBalanced(char *exp) {
    Stack S = init();
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(') {
            push(S, ch);
        } 
        else if (ch == ')') {
            if (isEmpty(S)) return false;   
            pop(S);
        }
    }
    return isEmpty(S); 
}

int main() {
	
    char expr[] = "((a+b)*(c-d)))";

    if (isBalanced(expr)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}
