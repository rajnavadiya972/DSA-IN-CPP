// ARRAY [  6    2   5   4   5   1   6  ] BILDING HEIGHT
// AEVU RECTANGALE BANAVANU  AREA MAX THAY WIDTH = 1 😀

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
            nsr.push_back(7);
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
                nsr.push_back(7);
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

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> width(n);
    vector<int> left(n);
    vector<int> right(n);
    vector<int> area(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    right = NSR(v);
    left = NSL(v);
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
        area[i] = v[i] * width[i];
        cout << width[i] << " ";
    }
    cout << "\n" <<*(max_element(area.begin(), area.end())) << endl;
}