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
int middle(node* head){
    if(head == NULL) return -1;

    // first pass: count nodes
    node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }

    int centre = cnt / 2;

    // second pass: reach the middle node
    temp = head;
    cnt = 0;
    while(temp){
        if(cnt == centre) return temp->data;
        cnt++;
        temp = temp->next;
    }
    return -1; // fallback, should not hit
}
node* convertvecttoll(vector <int> & arr){
    node* head= new node(arr[0]);
    node *mover=head;
    for (int i=1; i<arr.size();i++){
        node* temp= new node(arr[i]);
        mover->next=temp;
        mover=mover->next; //mover=temp;
    }
    return head;
}
int main()
{
    vector<int> arr={10,2,7,3,4};
    node* head=convertvecttoll(arr);
    int centre=middle(head);
    cout<<centre;
    return 0; 
}