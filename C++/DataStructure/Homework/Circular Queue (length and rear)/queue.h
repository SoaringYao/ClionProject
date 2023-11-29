#ifndef __QUEUE_H__
#define __QUEUE_H_

#include<iostream>
#include <cstdlib>	
#define MaxQSize 7

typedef char ElemType;

typedef struct
{
	ElemType *base;
	int rear;
	int length;
}Queue;

using namespace std;

Queue InitQueue();

void EnQueue(Queue &Q,ElemType x);

ElemType DeQueue(Queue &Q,ElemType &e);

bool FullQueue(Queue &Q);

bool EmptyQueue(Queue &Q);

#endif
