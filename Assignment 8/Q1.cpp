#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    };
  static int index = -1;
Node* buildBinaryTree(vector<int> &preorder){

index ++;
Node*root = new Node(preorder[index]);
if(preorder[index]==-1){
    return NULL;}
    else {
        root->left = buildBinaryTree(preorder);
        root->right = buildBinaryTree(preorder);

    }
    return root;
}
//preorder traversal
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
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
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    else {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void levelOrder(Node* root){
queue<Node*> q;
q.push(root);
while(q.size()>0){
    Node*curr = q.front();
    q.pop();
    cout<<curr->data<<" ";
    if(curr->left!=NULL){
        q.push(curr->left);
    }
    if(curr->right!=NULL){
        q.push(curr->right);
}
}
}
int  main(){
vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildBinaryTree(preorder);

    cout << "Preorder: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;
return 0;

}
