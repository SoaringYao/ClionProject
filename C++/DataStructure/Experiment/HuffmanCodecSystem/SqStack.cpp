#include "SqStack.h"

void InitStack_sq(SqStack &S, int msize) {  // 构造一个容量是msize的顺序栈S
  S.elem = new ElemType[msize];
  S.stacksize = msize;
  S.top = -1;  // 顺序栈初始时空栈
}  // end InitStack_sq

void DestroyStack_sq(SqStack &S) {  // 销毁顺序栈
  delete[] S.elem;
  S.top = -1;
  S.stacksize = 0;
}

void Increment(SqStack &S, int incresize) {
  ElemType *a;
  a = new ElemType[S.stacksize + incresize];
  for (int i = 0; i <= S.top; i++) a[i] = S.elem[i];
  delete[] S.elem;
  S.elem = a;
  S.stacksize += incresize;
}

bool GetTop_sq(
    SqStack S,
    ElemType &e) {  // 若非空，用e返回栈顶值，返回true,否则返回false,不改变栈
  if (StackEmpty(S)) return false;
  e = S.elem[S.top];
  return true;
}

void Push_sq(SqStack &S, ElemType e) {  // 将e插入栈S，作为S新的栈顶元素
  if (S.top == S.stacksize - 1) Increment(S);
  S.elem[++S.top] = e;
}  // end Push_sq

bool Pop_sq(SqStack &S, ElemType &e) {  // 若顺序栈S非空，删除栈顶元素并赋予e，
                                        // 返回TRUE，栈空则返回FALSE
  if (S.top == -1) return false;
  e = S.elem[S.top--];
  return true;
}  // end Pop_sq

bool StackEmpty(SqStack S) {
  if (S.top == -1)
    return true;
  else
    return false;
}