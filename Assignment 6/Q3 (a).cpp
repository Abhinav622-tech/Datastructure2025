#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList {
public:
    ListNode* head;

    DoublyList() {
        head = nullptr;
    }

    // INSERT AT END
    void insert(int v) {
        ListNode* n = new ListNode(v);

        if (head == nullptr) {
            head = n;
            return;
        }

        ListNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    // PRINT LIST
    void printList() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        ListNode* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // SIZE OF LIST
    int size() {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

int main() {

    DoublyList dl;

    dl.insert(10);
    dl.insert(20);
    dl.insert(30);
    dl.insert(40);

    dl.printList();
    cout << "Size = " << dl.size() << endl;

    return 0;
}
