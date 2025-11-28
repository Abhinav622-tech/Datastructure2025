#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int val1){
        val=val1;
        next=nullptr;
    }
    ListNode(int val1, ListNode* next1){
        val=val1;
        next=next1;
    }
    bool iscircular(ListNode* head){
        if(head==NULL || head->next==NULL) return false;
        if(head->next==head) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return true;
        }
        return false;
    }
    
};
int main()
{
    
    return 0; 
}