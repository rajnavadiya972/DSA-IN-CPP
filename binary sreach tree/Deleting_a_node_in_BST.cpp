#include <bits/stdc++.h>
using namespace std;

//       4
//     /   \
//    2     5
//  /   \
// 1     3

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n; //creating a node pointer
    n = new node(); //allocate memory in heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        cout << root->data << " ";
        postorder(root->right);
    }
}

struct node *inOredwePredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    //search for the node to be deleted
    if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    //deletion strategy when node is found
    else
    {
        iPre = inOredwePredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(5);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(3);

    //link the root node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    postorder(p);
    deleteNode(p, 4);
    cout << "\n";
    postorder(p);
    return 0;
}