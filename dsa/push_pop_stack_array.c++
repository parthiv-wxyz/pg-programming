#include<iostream>
using namespace std;

class stack
{
private:
    int size;
    int top;
    int *s;
public:
    stack(int n)
    {
        size=n;
        top=-1;
        s=new int[size];
    }
    void push(int item)
    {
        if(top==size-1)
        {
            cout<<"\n stack overflow";
            return;
        }
        else
        {
            top++;
            s[top]=item;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"\n stack underflow";
            return -1;
        }
        int data=s[top];
        top--;
        return data;
    }
};

int main()
{
    int n;
    cout<<"\n enter the size of stack";
    cin>>n;
    stack s1(n);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<s1.pop();
    cout<<s1.pop();
}