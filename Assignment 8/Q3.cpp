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


bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}
Node* getInorderSuccessor(Node* root){
    while(root!=NULL&& root->left != NULL){
        root= root->left;
    }
    return root;
}


Node* delNode(Node* root ,int key){
    if(root==NULL) {
        return NULL;
    }

if(key<root->data){
    root->left = delNode(root->left,key);
}
else if (key > root->data){
    root->right = delNode(root->right,key);
}
else{
    if(root->left==NULL){
        Node*temp=root->right;
        delete root;
        return temp;
    }
    else  if(root->right==NULL){
        Node*temp=root->left;
        delete root;
        return temp;
    }
    else{
        Node* IS =getInorderSuccessor(root->right);
        root->data=IS->data;
        root->right= delNode(root->right,IS->data);
    }
}
return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;

    }
    else {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int maxDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}
int minDepth(Node* root) {
    if (root == NULL) return 0;

    // If one of the child is NULL, we must go to the other child
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);

    // Both children exist → choose minimum
    return 1 + min(minDepth(root->left), minDepth(root->right));
}




int main() {
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout<<"Inorder before deletion: ";
    inorder(root);
    cout<<endl;
    root= delNode(root,6);
    cout<<"Inorder after deletion: ";
    inorder(root);
    cout<<endl;
    cout<<"Max depth of tree: "<< maxDepth(root)<<endl;
    cout<<"Min depth of tree: "<< minDepth(root)<<endl;

    return 0;
}
