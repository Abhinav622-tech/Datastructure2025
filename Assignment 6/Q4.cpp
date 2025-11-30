#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int val1) {
        val = val1;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int val1, ListNode* next1, ListNode* prev1) {
        val = val1;
        next = next1;
        prev = prev1;
    }

    // CHECK IF DOUBLY LINKED LIST IS PALINDROME
    bool ispalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* temp = head;

        // reach last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // compare from both ends
        while (head != temp && temp->next != head) {
            if (temp->val != head->val) 
                return false;

            temp = temp->prev;
            head = head->next;
        }

        return true;
    }
};

// Function to insert at end of a DOUBLY linked list
void insertEnd(ListNode*& head, int val) {
    ListNode* n = new ListNode(val);

    if (head == NULL) {
        head = n;
        return;
    }

    ListNode* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// print list for checking
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = NULL;

    // Example 1: PALINDROME LIST
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 2);
    insertEnd(head, 1);

    cout << "List: ";
    printList(head);

    ListNode dummy(0);
    if (dummy.ispalindrome(head))
        cout << "It is a Palindrome.\n";
    else
        cout << "Not a Palindrome.\n";

    return 0;
}
