#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    //声明一个顺序表
    SqList L;
    //初始化顺序表
    InitList_sq(L);
 
    int number = 0;
    ElemType e;
    
    cout<<"list length:";
    cin>>number;
 
    for(int i = 0; i < number; ++i)
    {
        cin>>e;//输入数据
        ListInsert_SortedSq(L, e);
    }
    ListPrint_Sq(L);

    cout<<"insert number:";
    cin>>e;
    ListInsert_SortedSq(L, e);
    ListPrint_Sq(L);
    
    DestroyList_sq(L);
    return  0;
}
