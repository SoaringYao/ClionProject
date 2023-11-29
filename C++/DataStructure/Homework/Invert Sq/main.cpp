#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    int i;
    SqList L;
    InitList_sq(L);
    createdata(L);
    cout<<"创建的顺序表为:";
    ListPrint_Sq(L);
 
    ListOppose(L);
    cout<<"颠倒后的顺序表为:";
    ListPrint_Sq(L);
    DestroyList_sq(L);
    
    return 0;
}