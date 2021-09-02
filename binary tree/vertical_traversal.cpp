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

map<int, vector<int>> verticalorder(struct node *root)
{
    queue<pair<node *, int>> q;
    map<int, vector<int>> m;
    if (root == NULL)
    {
        return m;
    }
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *temp = p.first;
        int hd = p.second;
        m[hd].push_back(temp->data);
        if (temp->left != NULL)
        {
            q.push(make_pair(temp->left, hd - 1));
        }
        if (temp->right != NULL)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }
    return m;
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

    map<int, vector<int>> v = verticalorder(p);
    for (auto &it : v)
    {
        for (auto &element : it.second)
        {
            cout << element << " ";
        }
    }
    return 0;
}
