#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> v)
{
    stack<int> s;
    vector<int> nsl;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.size() == 0)
        {
            nsl.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < v[i])
        {
            nsl.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= v[i])
        {
            while (s.size() > 0 && s.top() >= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                nsl.push_back(-1);
            }
            else
            {
                nsl.push_back(s.top());
            }
        }
        s.push(v[i]);
    }

    return nsl;
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = NSL(v);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}