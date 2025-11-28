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



// ----------------------------
//      INORDER METHOD
// ----------------------------
bool isBSTUtil(Node* root, int &prev) {
    if (root == nullptr) return true;

    // Left subtree check
    if (!isBSTUtil(root->left, prev)) 
        return false;

    // Check current node
    if (root->data <= prev) 
        return false;

    prev = root->data;

    // Right subtree check
    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    int prev = INT_MIN; // store previous value in inorder
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(9);
    root->left->right = new Node(3);

    if (isBST(root))
        cout << "YES, it is a BST\n";
    else
        cout << "NO, it is NOT a BST\n";

    return 0;
}
