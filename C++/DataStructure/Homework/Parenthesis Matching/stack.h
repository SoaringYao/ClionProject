#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

#define STACK_INIT_SIZE 10
#define STACK_INCREMNET_SIZE 10

typedef char ElemType;
typedef struct
{ 
    ElemType *elem; 
    int top; 
    int stacksize; 
    int increment; 
}SqStack;

using namespace std;

void InitStack_sq(SqStack &S);
void Increment(SqStack &S);
bool StackEmpty(SqStack S);
void Push_sq(SqStack &S, ElemType e);
bool Pop_sq(SqStack &S, ElemType &e);

#endif 