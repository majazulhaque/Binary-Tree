#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int st, int end, int curr){
    for (int i = st; i <= end; i++)
    {
        if (inorder[i]== curr)
        {
            return i;
        }
        
    }
    return -1;
    
}

Node* buildTree(int preorder[], int inorder[], int st, int end){
    static int idx = 0;
    if (st > end)
    {
        return NULL;
    }
    

    int curr = preorder[idx];
    idx++;

    Node* node = new Node(curr);

    if (st == end)
    {
        return node;
    }
    

    int pos = search(inorder, st, end, curr);
    node->left = buildTree(preorder, inorder, st, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

    return node;
}

void printInorder(Node* root) {
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {

    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = buildTree(preorder, inorder, 0, 4);

    printInorder(root);


    return 0;
}