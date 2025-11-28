#include <iostream>
using namespace std;

#define MAXLEN 100

struct Stack {
    char arr[MAXLEN];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack& S) {
    return S.top == -1;
}

void push(Stack& S, char x) {
    if (S.top < MAXLEN - 1) {
        S.arr[++S.top] = x;
    }
}

char pop(Stack& S) {
    if (!isEmpty(S)) return S.arr[S.top--];
    return '\0';
}

char peek(Stack& S) {
    if (!isEmpty(S)) return S.arr[S.top];
    return '\0';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

bool isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(char exp[]) {
    Stack s = init();
    char post[MAXLEN];
    int j=0;

    for(int i=0; exp[i]!='\0'; i++) {
        char ch = exp[i];

        if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) {
            post[j++] = ch;   // operand directly goes to output
        }
        else if(ch=='(') {
            push(s,ch);
        }
        else if(ch==')') {
            while(!isEmpty(s) && peek(s)!='(') {
                post[j++] = pop(s);
            }
            pop(s);  // pop the (
        }
        else if(isOperator(ch)) {
            while(!isEmpty(s) && isOperator(peek(s)) &&
                 ( precedence(peek(s))>precedence(ch) ||
                 (precedence(peek(s))==precedence(ch) && !isRightAssociative(ch)) )) {
                post[j++] = pop(s);
            }
            push(s,ch);
        }
    }

    while(!isEmpty(s)) {
        post[j++] = pop(s);
    }

    post[j] = '\0';

    cout << "Postfix : " << post << endl;
}

int main() {
    char exp[] = "a+b*(c-d)";
    cout << "Infix  : " << exp << endl;
    infixToPostfix(exp);
    return 0;
}

