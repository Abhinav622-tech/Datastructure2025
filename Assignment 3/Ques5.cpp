#include <iostream>
#include <cctype>  // for isdigit
using namespace std;

#define MAXLEN 100

struct Stack {
    int arr[MAXLEN];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool empty(Stack& S) { return S.top == -1; }

void push(Stack& S, int x) {
    if (S.top < MAXLEN - 1) S.arr[++S.top] = x;
}

int pop(Stack& S) {
    if (!empty(S)) return S.arr[S.top--];
    return 0;  // default
}

int evalPostfix(const char* exp) {
    Stack S = init();

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            // convert char digit ? int and push
            push(S, ch - '0');
        }
        else {
            // operator ? pop 2 operands
            int val2 = pop(S); // right
            int val1 = pop(S); // left

            switch (ch) {
                case '+': push(S, val1 + val2); break;
                case '-': push(S, val1 - val2); break;
                case '*': push(S, val1 * val2); break;
                case '/': push(S, val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int j=0; j<val2; j++) result *= val1;
                    push(S, result);
                    break;
                }
            }
        }
    }
    return pop(S);  // final result
}

int main() {
    char exp[] = "62-3*";  // postfix for (6-2)*3
    cout << "Postfix: " << exp << endl;
    cout << "Result : " << evalPostfix(exp) << endl;
    return 0;
}
