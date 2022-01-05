#include <iostream>
using namespace std;
#include <math.h>
#include<queue>

// structure of a tree
struct node
{
    int key;
    node *left;
    node *right;

    node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};
// INORDER TRAVERSEL
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << (root->key) << " ";
    inorder(root->right);
}
// PREORDER TRAVERSEL
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << (root->key) << " ";
    preorder(root->left);
    preorder(root->right);
}
// POSTORDER TRAVERSAL
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << (root->key) << " ";
}

// HEIGHT OF THE BINARY TREE
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
// PRINT NODES AT DISTANCE K
void printnodeatk(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << (root->key) << " ";
    }
    else
    {
        printnodeatk(root->left, k - 1);
        printnodeatk(root->right, k - 1);
    }
}

// LEVEL ORDER TRAVERSAL
void printlevel(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
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

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl
         << height(root) << endl;

    printnodeatk(root, 1);
    cout<<endl;

    printlevel(root);
}