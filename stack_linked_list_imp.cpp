//always set custom size bcz linked list infinity chale 😀

// struct node *f;
// f=new node();

#include <iostream>
using namespace std;

struct Node
{
    int val;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p;
    p = new Node();
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("FULL!!!!!\n");
    }
    else
    {
        struct Node *n = new Node();
        n->val = x;
        n->next = top;
        top = n;
        printf("push %d\n", x);
    }
    return top;
}

int pop(struct Node** top)
{
    if (isEmpty(*top))
    {
        printf("EMPTY!!!!!!!!\n");
        return 0;
    }
    else
    {
        struct Node *n = (*top);
        (*top) = (*top)->next;
        int x = n->val;
        free(n);
        return x;
    }
}

int peek(struct Node* top,int pos)
{
    struct Node* ptr=top;
    for (int i = 0; ((i < pos-1) && ptr!=NULL); i++)
    {
        ptr=ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->val;
    }
    else{
        return -1;
    }
}

int stackTop (struct Node* top){
    return top->val;
}
int stackBot (struct Node* top){
    struct Node* ptr=top;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->val;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 23);
    top = push(top, 67);
    top = push(top, 47);
    printf("peek %d\n",peek(top,3));
    printf("top %d\n",stackTop(top));
    printf("bot %d\n",stackBot(top));
    printf("pop %d\n",pop(&top));
    printf("pop %d\n",pop(&top));
    printf("pop %d\n",pop(&top));
    printf("peek %d\n",peek(top,1));

    return 0;
}