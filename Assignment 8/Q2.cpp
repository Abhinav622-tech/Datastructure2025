#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* buildBST(vector<int> &arr) {
    Node* root = nullptr;
    for (int val : arr) root = insert(root, val);
    return root;
}
/*bool search(Node* root, int key) {
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->data == key) {
            return true;               // key found
        }
        else if (key < curr->data) {
            curr = curr->left;         // move left
        }
        else {
            curr = curr->right;        // move right
        }
    }

    return false;   // key not found
}
 non recursive version*/

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

Node* maximum(Node* root) {
    
    while (root->right != nullptr) root= root->right;
    return root;
}

Node* minimum(Node* root) {
    
    while (root->left != nullptr) root = root->left;;
    return root;
}
/*  void findPredSucc(Node* root, int key, Node*& pred, Node*& succ) {
    if (!root) return;

    if (root->data == key) {
        if (root->left) pred = maximum(root->left);
        if (root->right) succ = minimum(root->right);
    }
    else if (key < root->data) {
        succ = root;
        findPredSucc(root->left, key, pred, succ);
    }
    else {
        pred = root;
        findPredSucc(root->right, key, pred, succ);
    }
} this is the recursive version  */


vector<int> getPredSucc(Node* root, int key) {
    Node* curr = root;
    Node* pred = nullptr;
    Node* succ = nullptr;

    while (curr != nullptr) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            if (curr->left) pred = maximum(curr->left);
            if (curr->right) succ = minimum(curr->right);
            break;
        }
    }

   
    return {pred->data, succ->data};
}

int main() {
    vector<int> arr = {6, 4, 8, 1, 5, 7, 9};
    Node* root = buildBST(arr);

    vector<int> result = getPredSucc(root, 10);
    cout << "Predecessor: " << result[0] << endl;
    cout << "Successor: " << result[1] << endl;

    return 0;
}
