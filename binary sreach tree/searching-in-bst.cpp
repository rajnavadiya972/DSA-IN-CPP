#include <bits/stdc++.h>
using namespace std;

//        50
//     /      \
//    40        60
//  /   \     /    \
// 20    45  55    70

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *searchIter(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

struct node *createNode(int data)
{
    struct node *n; //creating a node pointer
    n = new node(); //allocate memory in heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
int main()
{
    struct node *p = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(45);
    struct node *p5 = createNode(55);
    struct node *p6 = createNode(70);

    //link the root node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    struct node *ans;
    ans = search(p, 45);
    cout << (ans == NULL ? 0 : ans->data) << endl;
    ans = searchIter(p, 4);
    cout << (ans == NULL ? 0 : ans->data) << endl;
    return 0;
}