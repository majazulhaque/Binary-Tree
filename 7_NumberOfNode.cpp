#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int NumberOFNode(Node* root) {
    if (root == NULL)
    {
        return 0;
    }
    int leftsumtree = NumberOFNode(root->left);
    int rightsumtree = NumberOFNode(root->right);

    return leftsumtree + rightsumtree + 1;
    
}

int main(){

     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<NumberOFNode(root);

    return 0;
}