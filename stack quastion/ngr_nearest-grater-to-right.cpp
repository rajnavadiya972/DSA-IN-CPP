//J loop func(i) hoy e stack thi thay

//NEXT LARGEST ELEMENT OR NREAREST GREATER TO RIGHT

#include <bits/stdc++.h>
using namespace std;

vector<int> NGR(vector<int> v)
{
    stack<int> s;
    vector<int> ngr;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            ngr.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > v[i])
        {
            ngr.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= v[i])
        {
            while (s.size() > 0 && s.top() <= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                ngr.push_back(-1);
            }
            else
            {
                ngr.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    reverse(ngr.begin(), ngr.end());
    return ngr;
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
    vector<int> ans = NGR(v);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}