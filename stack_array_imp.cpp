#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek(int index);
    bool isEmpty();
    bool isFull();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        return false;
    }
    else
    {
        a[++top] = x;
        cout << "push " << x << endl;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        return 0;
    }
    else
    {
        int x = a[top--];
        cout << "pop " << x << endl;
        return x;
    }
}

int Stack::peek(int index)
{
    if (top < 0)
    {
        return 0;
    }
    else
    {
        int x = a[top-index+1];
        return x;
    }
}

bool Stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    class Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    s.pop();
    s.pop();
    cout << s.peek(2) << endl;
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    return 0;
}