#include "stack.h"

void InitStack_sq(SqStack &S)
{ // 构造一个容量是msize的顺序栈S
    int msize = STACK_INIT_SIZE;
    S.elem = new ElemType[msize];
    S.stacksize = msize;
    S.top = -1; // 顺序栈初始时空栈
} // end InitStack_sq

void Push_sq(SqStack &S, ElemType e)
{ // 将e插入栈S，作为S新的栈顶元素
    if (S.top == S.stacksize - 1)
        Increment(S);
    S.elem[++S.top] = e;
} // end Push_sq

bool Pop_sq(SqStack &S, ElemType &e)
{ // 若顺序栈S非空，删除栈顶元素并赋予e， 返回TRUE，栈空则返回FALSE
    if (S.top == -1)
        return false;
    e = S.elem[S.top--];
    return true;
} // end Pop_sq

void Increment(SqStack &S)
{
    ElemType *a; 
    S.increment=STACK_INCREMNET_SIZE;
    a=new ElemType[S.stacksize+S.increment]; 
    for(int i=0;i<=S.top;i++)
    a[i]=S.elem[i]; 
    delete [] S.elem; 
    S.elem=a; 
    S.stacksize+=S.increment;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}