#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <cstring>
#include <iostream>
#include "global.h"

using namespace std;

typedef struct car
{
    int atime;
    int ltime;
    char num[1000];
} car;

typedef struct sqstack
{
    car *base;
    car *top;
} sqstack;

// 队列
typedef struct SqQueue
{
    car *front; // 队头指针
    car *rear;  // 队尾指针
} SqQueue;

void Initstack(sqstack &s);

bool StackEmpty(sqstack s);

void PushStack(sqstack &s, car p);

car Pop_s(sqstack &s);

void InitQueue(SqQueue &Q, int Qplace);

void PushQueue(SqQueue &Q, car p);

car Pop_q(SqQueue &Q); // 出队

void Push(sqstack &s, SqQueue &Q, car p); // 停车（入栈或入队列）

void arrive(sqstack &s1, SqQueue &Q);

void leave(sqstack &s1, sqstack &s2, SqQueue &Q);

void traverse_S(sqstack s);

void traverse_Q(SqQueue Q);

#endif