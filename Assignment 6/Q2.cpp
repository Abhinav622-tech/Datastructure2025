#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int v) {
        val = v;
        next = NULL;
    }
};

class CircularList {
public:
    ListNode* head;

    CircularList() {
        head = NULL;
    }

    // Insert at end (for testing)
    void insert(int v) {
        ListNode* n = new ListNode(v);

        if (head == NULL) {
            head = n;
            n->next = head;     // circular link
            return;
        }

        ListNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Print all elements in circular list
    void printAll() {
        if (head == NULL) {
            cout << "List is empty!";
            return;
        }

        if (head->next == head) {
            cout << head->val << "\t" << head->val;
            return;
        }

        cout << head->val << "\t";

        ListNode* temp = head->next;
        while (temp != head) {
            cout << temp->val << "\t";
            temp = temp->next;
        }

        cout << head->val;  // print again at end
    }
};

int main() {

    CircularList cl;

    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insert(40);

    cout << "Circular List Elements: ";
    cl.printAll();

    return 0;
}
