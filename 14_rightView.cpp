#include <iostream>
#include <queue>
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

// METHOD==1

// void rightView(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);
//     int prev = 0;

//     while (!q.empty())
//     {
//         Node *node = q.front();
//         q.pop();

//         if (node != NULL)

//         {
//             prev = node->data;
//             if (node->left)
//             {
//                 q.push(node->left);
//             }
//             if (node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//         else if
//             (!q.empty())
//             {
//                 q.push(NULL);
//                 cout << prev << " ";
//             }
//             else{
//                 cout<< prev << " ";
//             }
//     }
// }

// METHOD===2

void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->left->right = new Node(9);

    rightView(root);

    return 0;
}