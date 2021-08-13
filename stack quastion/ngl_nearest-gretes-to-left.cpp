//J loop func(i) hoy e stack thi thay

//NEXT LARGEST ELEMENT OR NREAREST GREATER TO LEFT

#include <bits/stdc++.h>
using namespace std;

vector<int> NGL(vector<int> v)
{
    stack<int> s;
    vector<int> ngl;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.size() == 0)
        {
            ngl.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > v[i])
        {
            ngl.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= v[i])
        {
            while (s.size() > 0 && s.top() <= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                ngl.push_back(-1);
            }
            else
            {
                ngl.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    return ngl;
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
    vector<int> ans = NGL(v);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}