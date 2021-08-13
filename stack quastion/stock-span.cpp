//INPUT  100 80 60 70 60 75 85
//OUTPUT  1   1  1  2  1  4  6

//CONSICUTIVLY SMALLER LEFT SIDE

#include <bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int> v)
{
    stack<pair<int,int>> s;
    vector<int> ngl;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.size() == 0)
        {
            ngl.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > v[i])
        {
            ngl.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= v[i])
        {
            while (s.size() > 0 && s.top().first <= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                ngl.push_back(-1);
            }
            else
            {
                ngl.push_back(s.top().second);
            }
        }
        s.push({v[i],i});
    }
    return ngl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> ans=stock(v);
    for (int i = 0; i < n; i++)
    {
        cout<<i-ans[i]<<" ";
    }
return 0;
}