#include <iostream>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

void printLinklist(struct node *p){
    while (p!=NULL)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}

int main()
{
    struct node *f;
    struct node *s;
    struct node *t;

    f=new node();
    s=new node();
    t=new node();
    // f = (struct node *)malloc(sizeof(struct node));
    // s = (struct node *)malloc(sizeof(struct node));
    // t = (struct node *)malloc(sizeof(struct node));

    f->val=11;
    f->next=s;

    s->val=21;
    s->next=t;

    t->val=31;
    t->next=NULL;

    printLinklist(f);
    return 0;
}