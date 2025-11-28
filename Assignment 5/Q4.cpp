#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
    node(int data){
        this->data=data;
        next=nullptr;
    }
};
node * reverser(node *head){
    node *temp=head;
    node* prev=NULL;
    node* fore=NULL;
    while(temp){
        fore=temp->next;
        temp->next=prev;
        prev=temp;
        temp=fore;
    }
    return prev;
}

int main()
{
    
    return 0; 
}