#include <iostream>
#include<climits>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumUtils(Node*root, int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int left = maxPathSumUtils(root->left, ans);
    int right = maxPathSumUtils(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                        max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;                
    
}
 
int maxPathSum(Node*root){
    int ans = INT_MIN;

    maxPathSumUtils(root, ans);

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);


    cout<<maxPathSum(root);

    return 0;
}