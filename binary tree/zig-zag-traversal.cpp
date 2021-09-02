#include <bits/stdc++.h>
using namespace std;

//       4
//     /   \
//    1     6
//  /   \
// 5     2

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

vector<int> levelorder(struct node *root)
{
    stack<node *> s1;
    stack<node *> s2;
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *temp = s1.top();
            v.push_back(temp->data);
            if (temp->right != NULL)
            {
                s2.push(temp->right);
            }
            if (temp->left != NULL)
            {
                s2.push(temp->left);
            }
            s1.pop();
        }
        while (!s2.empty())
        {
            node *temp = s2.top();
            v.push_back(temp->data);
            if (temp->left != NULL)
            {
                s1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                s1.push(temp->right);
            }
            s2.pop();
        }
    }
    return v;
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
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    //link the root node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    vector<int> v = levelorder(p);
    for (auto &it : v)
    {
        cout << it << " ";
    }
    return 0;
}