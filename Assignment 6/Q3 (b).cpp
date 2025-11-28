#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int val1){
        val=val1;
        next=nullptr;
        prev=nullptr;
    }
    int size(ListNode* head){
        if(head==NULL) return 0;
        if(head->next==head) return 1;
        int cnt=1;
        ListNode* temp=head->next;
        while(temp!=head){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

};
int main()
{
    
    return 0; 
}