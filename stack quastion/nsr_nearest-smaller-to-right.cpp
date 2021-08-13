#include <bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int> v)
{
    stack<int> s;
    vector<int> nsr;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            nsr.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < v[i])
        {
            nsr.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= v[i])
        {
            while (s.size() > 0 && s.top() >= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                nsr.push_back(-1);
            }
            else
            {
                nsr.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    reverse(nsr.begin(), nsr.end());
    return nsr;
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
    vector<int> ans = NSR(v);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}