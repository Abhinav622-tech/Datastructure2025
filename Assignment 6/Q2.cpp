#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val1){
        val=val1;
        next=nullptr;
    }

    void printallelemnt(ListNode* head){
        if(head==NULL) return;
        if(head->next==head) {cout<<head->val<<"\t"<<head->val; return; }
        ListNode* temp=head->next;
        cout<<head->val<<"\t";
        while(temp!=head){
            cout<<temp->val<<"\t";
            temp=temp->next;
        }
        cout<<head->val;
        return;

    }

};
int main()
{
    
    return 0; 
}