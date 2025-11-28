#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int val1){
        val=val1;
        next=nullptr;
        prev=nullptr;
    }
    ListNode(int val1, ListNode* next1,ListNode* prev1){
        val=val1;
        next=next1;
        prev=prev1;
    }
    bool ispalindrome(ListNode* head){
        if(head==NULL or head->next==NULL) return true;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        while(head!=temp && temp->next!=head){
            if(temp->val!=head->val) return false;
            temp=temp->prev;
            head=head->next;
        }
        return true;
    }
};
int main()
{
    
    return 0; 
}