#include <bits/stdc++.h>
using namespace std;

struct adts
{
    int total;
    int use;
    int *p;
};

void generater(struct adts *a, int tsize, int usize)
{
    a->total = tsize;
    a->use = usize;
    a->p = new int((a->total) * sizeof(int));
}

void getData(struct adts *a)
{
    for (int i = 0; i < a->use; i++)
    {
        int n;
        cout << "Enter person " << i + 1 << " marks" << endl;
        cin >> n;
        (a->p)[i] = n;
    }
}

void setData(struct adts *a)
{
    for (int i = 0; i < a->use; i++)
    {
        cout << "Enter person " << i + 1 << " marks is " << (a->p)[i] << endl;
    }
}

int main()
{
    struct adts marks;
    generater(&marks, 10, 5);
    getData(&marks);
    setData(&marks);
    return 0;
}