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

bool empty(Stack& S) { return S.top == -1; }

void push(Stack& S, char x) {
    if (S.top < MAXLEN - 1) S.arr[++S.top] = x;
}

char pop(Stack& S) {
    if (!empty(S)) return S.arr[S.top--];
    return '\0';
}

char top(Stack& S) {
    if (!empty(S)) return S.arr[S.top];
    return '\0';
}

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOp(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

bool rightAssoc(char op) { return (op == '^'); }

void in2post(char exp[]) {
    Stack s = init();
    char post[MAXLEN];
    int j=0;

    for(int i=0; exp[i]!='\0'; i++) {
        char ch = exp[i];

        if(isalnum(ch)) {               // operand
            post[j++] = ch;
        }
        else if(ch=='(') {
            push(s,ch);
        }
        else if(ch==')') {
            while(!empty(s) && top(s)!='(')
                post[j++] = pop(s);
            pop(s); 
        }
        else if(isOp(ch)) {
            while(!empty(s) && isOp(top(s)) &&
                 ( prec(top(s))>prec(ch) ||
                 (prec(top(s))==prec(ch) && !rightAssoc(ch)) )) {
                post[j++] = pop(s);
            }
            push(s,ch);
        }
    }

    while(!empty(s)) post[j++] = pop(s);

    post[j] = '\0';
    cout << "Postfix: " << post << endl;
}

int main() {
    char exp[] = "a+b*(c-d)";
    cout << "Infix : " << exp << endl;
    in2post(exp);
    return 0;
}

