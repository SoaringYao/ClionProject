#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#define LIST_INIT_SIZE 100
#define LIST_INC_SIZE 20
typedef int Status;
typedef int ElemType;

using namespace std;
typedef struct
{
    ElemType *elem;
    int length; // data space
    int listsize;
    int incrementsize;
} SqList;

void InitList_sq(SqList &L, int msize = LIST_INIT_SIZE)
{ // 构造一个容量是msize的顺序表L
    L.elem = new ElemType[msize];
    L.listsize = msize; // 顺序表的最大容量
    L.length = 0;       // 顺序表初始时的元素数是0
} // end InitList_sq

void DestroyList_sq(SqList &L)
{ // 销毁顺序表L
    delete[] L.elem; // 释放数组空间
    L.length = 0;
    L.listsize = 0;
} // end DestroyList_sq

void Increment(SqList &L, int inc_size = LIST_INC_SIZE)
{ // 增加顺序表L的容量为listsize+inc_size
    int *a;
    a = new int[L.listsize + inc_size];
    if (!a)
    {
        cout << "wrong!";
        return;
    }
    for (int i = 0; i < L.length; i++)
    {
        a[i] = L.elem[i];
    }
    delete[] L.elem;        // 释放原数组空间
    L.elem = a;             // 将新的数组赋予顺序表的指针
    L.listsize += inc_size; // 顺序表的容量增加inc_size
} // end ListInsert_sq

void GetItem_sq(SqList L, int i, int &e)
{ // 将顺序表L中位序为i的元素值赋予e.
    e = L.elem[i - 1];
} // end GetItem_sq

void ListInsert_sq(SqList &L, int i, int e)
{ // 在顺序表L中位序为i的元素前插入一个新的元素e.同时需要考虑i的合法性和满状态
    if (i < 1 || i > L.length + 1)
    {
        cout << "invalid i!";
        return;
    }
    if (L.length == L.listsize)
        Increment(L); // 当前L已满
    for (int j = L.length - 1; j >= i - 1; j--)
    { // 由后往前逐个后移元素
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e; // 在L.elem[i-1]放入e
    ++L.length;
} // end ListInsert_sq

bool ListEmpty_sq(SqList L)
{
    return (L.length == 0);
}

bool ListFull_sq(SqList L)
{
    return (L.length == L.listsize);
}

int ListLength_sq(SqList L)
{
    return L.length;
}

int LocateItem_sq(SqList L, int e)
{ // 在顺序表L中查找第一个值为e的元素，若找到则 返回位序，否则返回0.
    for (int i = 1; i <= L.length; i++)
    { // 依次查找每个元素
        if (L.elem[i - 1] == e)
            return i; // 找到位序为i的元素
    }
    return 0;// 没有找到值为e的元素
} // end LocateItem_sq

Status ListInsert_SortedSq(SqList &L,ElemType e)
{
    ElemType *p = L.elem, *q;
    if(L.length >= L.listsize)
    {
        Increment(L);
    }
    while(*p < e && p <= L.elem+L.length-1)
        ++p;
    for(q = L.elem+L.length-1; q >= p; q--)
        *(q+1) = *q;
    *p = e;
    ++L.length;
    return 1;
}

void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//遍历元素用的指针
 
    for(int i = 0; i < L.length; ++i){
        if(i == L.length - 1){
            cout<<*(p+i)<<" ";
        }
        else{
            cout<<*(p+i)<<" ";
        }
    }
    cout<<endl;
}

void createdata(SqList &L)
{
    int number = 0;
    ElemType e;
    
    cout<<"list length:";
    cin>>number;
 
    for(int i = 0; i < number; ++i)
    {
        cin>>e;//输入数据
        ListInsert_SortedSq(L, e);
    }
}

Status ListOppose(SqList &L)
{   // 颠倒顺序表中的数据元素
    int i;
    ElemType x;
    for(i=0; i< L.length/2; i++)       // 只需要遍历原表的一半就可以实现数据元素位置的交换
    {
        x = L.elem[i];
        // printf("L 的第%d个数据元素为:%d\n", i, L.elem[i]);
        L.elem[i] = L.elem[L.length-i-1];        // 数据元素交换->逆置
        L.elem[L.length-i-1] = x;                
    }
    return 1;
}//ListOppose

#endif // FUNCTION_H_INCLUDED