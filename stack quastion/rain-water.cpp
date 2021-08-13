// 3    0   0   2   4
//PANI KETALA AREA MA BHARAY

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n], maxl[n], maxr[n], sum[n], ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    maxl[0] = v[0];
    maxr[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
    {
        maxl[i] = max(maxl[i - 1], v[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxr[i] = max(maxr[i + 1], v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum[i] = min(maxl[i], maxr[i]) - v[i];
        ans = ans + sum[i];
    }
    cout << ans << endl;
}