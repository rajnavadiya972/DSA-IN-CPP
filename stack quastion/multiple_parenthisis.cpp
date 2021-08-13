// (3*6)-(9-3))  😀   (4-3)*(3+3)

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
    char peek(int index);
    bool isEmpty();
    bool isFull();
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
        cout << "push " << x << endl;
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
        cout << "pop " << x << endl;
        return x;
    }
}

char Stack::peek(int index)
{
    if (top < 0)
    {
        return '0';
    }
    else
    {
        char x = a[top-index+1];
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

char Stack::isTop()
{
    return a[top];
}

int matchpar(char a,char b){
    if (a==')' && b=='(')
    {
        return 1;
    }
    if (a=='}' && b=='{')
    {
        return 1;
    }
    if (a==']' && b=='[')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int Match(char* str){
    Stack s;
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if (matchpar(str[i],s.isTop()))
            {
                s.pop();
            }
            else{
                return 0;
            }
        }
    }
    if (s.isEmpty())
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int main()
{
    char* str="{(4-3)[{*](3+3)}}";
    if (Match(str))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}