#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val1) {
        val = val1;
        next = nullptr;
    }

    ListNode(int val1, ListNode* next1) {
        val = val1;
        next = next1;
    }

    // CHECK IF LINKED LIST IS CIRCULAR
    bool iscircular(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {

    // -----------------------
    // NON-CIRCULAR LINKED LIST
    // -----------------------
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    ListNode obj(0);
    cout << "List 1 Circular? " 
         << (obj.iscircular(head1) ? "Yes" : "No") 
         << endl;

    // -----------------------
    // CIRCULAR LINKED LIST
    // -----------------------
    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(20);
    head2->next->next = new ListNode(30);

    // make a loop
    head2->next->next->next = head2;  // last node pointing to head

    cout << "List 2 Circular? " 
         << (obj.iscircular(head2) ? "Yes" : "No") 
         << endl;

    return 0;
}
