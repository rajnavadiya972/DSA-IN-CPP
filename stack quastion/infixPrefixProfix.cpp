//  INFIX           a+b     😀😀😀😀😀😀
//  PREFIX          +a,b    😀😀😀😀😀😀
//  POSTFIX         a,b+    😀😀😀😀😀😀

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

class Stack
{
    int top;

public:
    char a[MAX];
    Stack() { top = -1; }
    bool push(char x);
    char pop();
    bool isEmpty();
    char isTop();
};

bool Stack::push(char x)
{
    if (top >= MAX - 1)
    {
        return false;
    }
    else
    {
        a[++top] = x;
        // cout << "push " << x << endl;
        return true;
    }
}

char Stack::pop()
{
    if (top < 0)
    {
        return '0';
    }
    else
    {
        char x = a[top--];
        // cout << "pop " << x << endl;
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

char Stack::isTop()
{
    return a[top];
}

int prec(char ch)
{
    if (ch=='-' || ch=='+')
    {
        return 1;
    }
    else if (ch=='/' || ch=='*')
    {
        return 2;
    }
    else{
        return 0;
    }
}

int ofOpr(char ch){
    if (ch=='-' || ch=='+' || ch=='/' || ch=='*')
    {
        return 1;
    }
    else{
        return 0;
    }
}

char* infixToPostfix(const char* inf){
    Stack s;
    int i=0,j=0;
    char* pos;
    pos=new char[strlen(inf)];
    while (inf[i]!='\0')
    {
        if (!ofOpr(inf[i]))
        {
            pos[j]=inf[i];
            i++;
            j++;
        }
        else{
            if (prec(inf[i])>prec(s.isTop()))
            {
                s.push(inf[i]);
                i++;
            }
            else{
                pos[j]=s.pop();
                j++;
            }
        }
    }
    while (!s.isEmpty())
    {
        pos[j]=s.pop();
        j++;
    }
    pos[j]='\0';
    return pos;
}

int main()
{
    const char* a="a-b*d+c";
    cout<<infixToPostfix(a)<<endl;
    return 0;
}