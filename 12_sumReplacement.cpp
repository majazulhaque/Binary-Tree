#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void sumReplace(Node*root){
    if (root == NULL)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
    
}

void printpreorder(Node*root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
    
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printpreorder(root);
    cout<<endl;
    sumReplace(root);
    cout<<endl;
    printpreorder(root);

    return 0;
}