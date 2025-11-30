#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val1) {
        val = val1;
        next = nullptr;
        prev = nullptr;
    }

    // SIZE of circular doubly linked list
    int size(ListNode* head) {
        if (head == NULL) return 0;
        if (head->next == head) return 1;

        int cnt = 1;
        ListNode* temp = head->next;

        while (temp != head) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};

class CircularDoublyList {
public:
    ListNode* head;

    CircularDoublyList() {
        head = NULL;
    }

    // Insert at end
    void insert(int val) {
        ListNode* n = new ListNode(val);

        if (!head) {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }

        ListNode* last = head->prev;

        last->next = n;
        n->prev = last;
        n->next = head;
        head->prev = n;
    }

    // Print list
    void print() {
        if (!head) {
            cout << "List empty\n";
            return;
        }

        ListNode* temp = head;
        cout << "List: ";

        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // Return size
    int getSize() {
        ListNode node(0);  // dummy object to use size()
        return node.size(head);
    }
};

int main() {
    CircularDoublyList cd;

    cd.insert(10);
    cd.insert(20);
    cd.insert(30);
    cd.insert(40);

    cd.print();

    cout << "Size = " << cd.getSize() << endl;

    return 0;
}
