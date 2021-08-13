// 0   1   1   0
// 1   1   1   1
// 1   1   1   1
// 1   1   0   0

//max area gotvano

#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> v)
{
    stack<pair<int, int>> s;
    vector<int> nsl;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.size() == 0)
        {
            nsl.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first < v[i])
        {
            nsl.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                nsl.push_back(-1);
            }
            else
            {
                nsl.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }

    while (!s.empty())
    {
        s.pop();
    }
    return nsl;
}

vector<int> NSR(vector<int> v)
{
    stack<pair<int, int>> s;
    vector<int> nsr;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            nsr.push_back(4);
        }
        else if (s.size() > 0 && s.top().first < v[i])
        {
            nsr.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                nsr.push_back(4);
            }
            else
            {
                nsr.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }
    reverse(nsr.begin(), nsr.end());
    while (!s.empty())
    {
        s.pop();
    }
    return nsr;
}

int MAH(vector<int> v, int n)
{
    vector<int> width(n);
    vector<int> left(n);
    vector<int> right(n);
    vector<int> area(n);
    right = NSR(v);
    left = NSL(v);
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
        area[i] = v[i] * width[i];
    }
    return *(max_element(area.begin(), area.end()));
}

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    vector<int> v(n, 0);
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            v[j] = (a[i][j] == 0) ? 0 : (v[j] + a[i][j]);
        }
        ans[i] = MAH(v, n);
    }
    cout << *(max_element(ans.begin(), ans.end())) << endl;
}