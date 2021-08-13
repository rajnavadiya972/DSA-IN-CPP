//      18  19  24  15  16
// MINIMUM ELEMENT

#include <bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;

int getele()
{
    if (ss.size() == 0)
    {
        return -1;
    }
    else
    {
        return ss.top();
    }
}

void push(int a)
{
    s.push(a);
    if (ss.size() == 0 || ss.top() >= a)
    {
        ss.push(a);
    }
}

void pop()
{
    if (s.size() == 0)
    {
        return;
    }
    int ans = s.top();
    s.pop();
    if (ss.top() == ans)
    {
        ss.pop();
    }
}
int main()
{
    push(3);
    push(5);
    push(2);
    int ans=getele();
    cout<<ans<<endl;
    pop();
    ans=getele();
    cout<<ans<<endl;
}