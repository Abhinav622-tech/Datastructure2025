#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class SinglyList {
public:
    Node* head;

    SinglyList() {
        head = NULL;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    // Count occurrences
    int countOccurrences(int key) {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Delete ALL occurrences of key
    void deleteAll(int key) {

        // Delete occurrences at head
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Delete remaining nodes
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    SinglyList s;

    // Hardcoded list: 10 -> 20 -> 30 -> 20 -> 40 -> 20 -> 50
    s.insertEnd(10);
    s.insertEnd(20);
    s.insertEnd(30);
    s.insertEnd(20);
    s.insertEnd(40);
    s.insertEnd(20);
    s.insertEnd(50);

    int key = 20;

    cout << "Original List: ";
    s.display();

    int count = s.countOccurrences(key);
    cout << "Occurrences of " << key << " = " << count << endl;

    s.deleteAll(key);

    cout << "List after deleting all occurrences of " << key << ": ";
    s.display();

    return 0;
}
