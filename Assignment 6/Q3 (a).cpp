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
        next=nullptr;
        prev=nullptr;
        val=val1;
    }
    int size(ListNode* head){
        int cnt=0;
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        ListNode* temp=head;
        while(temp){
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