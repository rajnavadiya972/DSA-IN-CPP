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
    queue<node *> q;
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        v.push_back(temp->data);
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        q.pop();
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

//2nd part
// vector<int> levelorder(struct node *root)
// {
//     queue<node *> q;
//     vector<int> v;
//     if (root == NULL)
//     {
//         return v;
//     }
//     q.push(root);
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         v.push_back(temp->data);
//         if (temp->right != NULL)
//         {
//             q.push(temp->right);
//         }
//         if (temp->left != NULL)
//         {
//             q.push(temp->left);
//         }
//         q.pop();
//     }
//     return v;
// }

//3rd part
// vector<int> levelorder(struct node *root)
// {
//     queue<node *> q;
//     stack<int> s;
//     if (root == NULL)
//     {
//         return v;
//     }
//     q.push(root);
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         s.push(temp->data);
//         if (temp->left != NULL)
//         {
//             q.push(temp->left);
//         }
//         if (temp->right != NULL)
//         {
//             q.push(temp->right);
//         }
//         q.pop();
//     }
//     return v;
// }

//chelle stack ne print karavani\u aetle niche thi upar sudhi print thay


//4rd part
// vector<int> levelorder(struct node *root)
// {
//     queue<node *> q;
//     stack<int> s;
//     if (root == NULL)
//     {
//         return v;
//     }
//     q.push(root);
//     while (!q.empty())
//     {
//         node *temp = q.front();
//         s.push(temp->data);
//         if (temp->right != NULL)
//         {
//             q.push(temp->right);
//         }
//         if (temp->left != NULL)
//         {
//             q.push(temp->left);
//         }
//         q.pop();
//     }
//     return v;
// }

//chelle stack ne print karavani\u aetle niche thi upar sudhi print thay