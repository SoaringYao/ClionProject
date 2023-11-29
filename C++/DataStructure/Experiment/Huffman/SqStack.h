#ifndef SQSTACK_H
#define SQSTACK_H

#define STACK_INIT_SIZE 10
#define STACK_INCREMNET_SIZE 10

typedef char ElemType;
typedef struct {
  ElemType *elem;
  int top;
  int stacksize;
} SqStack;

using namespace std;

void InitStack_sq(SqStack &S, int msize = STACK_INIT_SIZE);

void DestroyStack_sq(SqStack &S);

void Increment(SqStack &S, int incresize = STACK_INCREMNET_SIZE);

bool GetTop_sq(SqStack S, ElemType &e);

void Push_sq(SqStack &S, ElemType e);

bool Pop_sq(SqStack &S, ElemType &e);

bool StackEmpty(SqStack S);

#endif