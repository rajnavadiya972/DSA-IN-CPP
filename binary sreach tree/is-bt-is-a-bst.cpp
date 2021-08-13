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

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        cout << root->data<<" ";
        postorder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node* prev=NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if ( prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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
    cout<<"\n"<<isBST(p)<<endl;
    return 0;
}