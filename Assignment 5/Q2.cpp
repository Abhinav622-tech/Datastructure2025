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
node* counterremover(node* head,int key){
    if(head==NULL){return head;}
    int cnt=0;
    node*  temp=head;
    node* prev=NULL;
    while(temp){
        if(temp->data==key&& temp==head){
            cnt++;
            temp=temp->next;
            head=temp;
        }
        else if(temp->data==key){
            cnt++;
            prev->next=temp->next;
            temp=temp->next;

        } else{
        prev=temp;
        temp=temp->next;}
    }
    cout<<"counter of "<<key<<" = "<<cnt<<endl;
    return head;
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
void traversell(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={1,2,1,2,1,3,1};
    node* head=convertvecttoll(arr);
    traversell(head);
    head=counterremover(head,1);
    traversell(head);
    return 0; 
}