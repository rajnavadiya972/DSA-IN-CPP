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

void insert(node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *ptr = createNode(key);
    if (key < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
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

    insert(p, 7);
    cout << p->right->right->data;
    return 0;
}