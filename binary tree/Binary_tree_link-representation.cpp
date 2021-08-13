#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n; //creating a node pointer
    n=new node();   //allocate memory in heap
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}
int main()
{

    // BEFORE FUNCTION

    // struct node *p;
    // p=new node();
    // p->left=NULL;
    // p->right=NULL;

    // struct node *p1;
    // p1=new node();
    // p1->left=NULL;
    // p1->right=NULL;

    // struct node *p2;
    // p2=new node();
    // p2->left=NULL;
    // p2->right=NULL;

    // p->left=p1;
    // p->right=p2;

    //AFTER FUNCTION

    struct node *p=createNode(2);
    struct node *p1=createNode(1);
    struct node *p2=createNode(4);

    //link the root node
    p->left=p1;
    p->right=p2;
return 0;
}