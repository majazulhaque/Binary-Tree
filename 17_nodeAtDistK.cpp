#include <iostream>
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

void printsubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printsubtreeNodes(root->left, k - 1);
    printsubtreeNodes(root->right, k - 1);
}

int printnodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printsubtreeNodes(root, k);
        return 0;
    }
    int dl = printnodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printnodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    printnodesAtK(root, root->left, 1);

    return 0;
}