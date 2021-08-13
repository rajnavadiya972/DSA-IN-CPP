//      18  19  24  15  16
// MINIMUM ELEMENT

#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int min_ele;

int getele()
{
    if (s.size() == 0)
    {
        return -1;
    }
    else
    {
        return min_ele;
    }
}

void push(int a)
{
    if (s.size() == 0)
    {
        s.push(a);
        min_ele = a;
    }
    else
    {
        if (a >= min_ele)
        {
            s.push(a);
        }
        else if (a < min_ele)
        {
            s.push(2 * a - min_ele);
            min_ele = a;
        }
    }
}

void pop()
{
    if (s.size() == 0)
    {
        return;
    }
    else
    {
        if (s.top() >= min_ele)
        {
            s.pop();
        }
        else if (s.top() < min_ele)
        {
            min_ele = (2 * min_ele - s.top());
            s.pop();
        }
    }
}

int main()
{
    push(3);
    push(10);
    push(5);
    push(1);
    push(9);
    push(0);
    push(6);
    int ans = getele();
    cout << ans << endl;
    pop();
    pop();
    ans = getele();
    cout << ans << endl;
    pop();
    pop();
    ans = getele();
    cout << ans << endl;
    pop();
    ans = getele();
    cout << ans << endl;
}