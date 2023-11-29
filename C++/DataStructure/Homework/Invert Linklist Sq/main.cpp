#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    int i;
    LinkList L;
    L=CreateList();
    cout<<"创建的单链表为:";
    DispList(L);
    cout<<"\n逆置后的单链表为:";
    ListOppose(L);
    DispList(L);
    return 0;
}