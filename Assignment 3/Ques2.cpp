#include<iostream>
using namespace std;

#define MAXLEN 100 //we degfined the length

struct Stack {
    char element[MAXLEN];  //we create an structure of stack whcih has element[] array which stores stack elemnt and top 
    int top;//index of the topmost elemnt of stack;
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
void rev(Stack& S){
	for (int i = S.top; i>=0; --i) {
        cout << S.element[i] << " ";
    }
    cout << endl;
	
}

int main() {
    Stack myStack = init(); //initialized 
    push(myStack, 'D');
    push(myStack, 'A');
    push(myStack, 'T');
    push(myStack, 'A');
    push(myStack, 'B');
    push(myStack, 'A');
    push(myStack, 'S');
    push(myStack, 'E');

    
    cout<<"the original"<<endl;
    print(myStack); // 30 20 10
    cout<<"reverse"<<endl;
    rev(myStack);
    
   
    return 0;
}



