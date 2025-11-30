#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = NULL;
    }
};

class SinglyList {
public:
    Node* head;
    SinglyList() {
        head = NULL;
    }

    // (a) INSERT AT BEGINNING
    void insertBegin(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // (b) INSERT AT END
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

    // (c) INSERT AFTER a specific value
    void insertAfter(int key, int val) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Key not found.\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // (c) INSERT BEFORE a specific value
    void insertBefore(int key, int val) {
        if (head == NULL) return;

        // if key is at head
        if (head->data == key) {
            insertBegin(val);
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Key not found.\n";
            return;
        }

        Node* n = new Node(val);
        prev->next = n;
        n->next = curr;
    }

    // (d) DELETE FROM BEGINNING
    void deleteBegin() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) DELETE FROM END
    void deleteEnd() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // (f) DELETE SPECIFIC NODE
    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        // delete head
        if (head->data == key) {
            deleteBegin();
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Node not found.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // (g) SEARCH NODE AND RETURN POSITION
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value not found.\n";
    }

    // (h) DISPLAY LIST
    void display() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyList sl;
    int choice, val, key;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Insert Before a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                sl.insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                sl.insertEnd(val);
                break;

            case 3:
                cout << "Insert after which value? ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> val;
                sl.insertAfter(key, val);
                break;

            case 4:
                cout << "Insert before which value? ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> val;
                sl.insertBefore(key, val);
                break;

            case 5:
                sl.deleteBegin();
                break;

            case 6:
                sl.deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                sl.deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                sl.search(key);
                break;

            case 9:
                sl.display();
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
