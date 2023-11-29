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
    
    separateOddAndEven(L);
    
    cout << "奇数在左侧，偶数在右侧：" << endl;
    for (int i=0;i<L.length;i++)
    {
        cout << L.elem[i] << " ";
    }
    
    return 0;
}
