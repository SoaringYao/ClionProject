#include <iostream>
#include "function.h"

int main()
{
    LinkList a;
    cout<<"a:"<<endl;
    a=CreateList();
    LinkList b;
    cout<<"b:"<<endl;
    b=CreateList();
    LinkList c;
    c=CombineList(a,b);
    cout<<"c:"<<endl;
    DispList(c);
    return 0;
}