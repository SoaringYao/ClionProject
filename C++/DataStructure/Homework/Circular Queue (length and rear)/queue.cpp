#include "queue.h"

Queue InitQueue(){
	Queue Q;
	Q.base=new ElemType[MaxQSize];
	Q.rear=0;
	Q.length=0;
	return Q;
}

bool FullQueue(Queue &Q)
{
	if(Q.length==MaxQSize)                  
		return true;
	return false;
}

bool EmptyQueue(Queue &Q)
{
	if(Q.length==0)                 
		return true;
	return false;
}

void EnQueue(Queue &Q,ElemType e)
{
	if(FullQueue(Q))
	{
		cout<<"FULL"<<endl;
		exit(EXIT_FAILURE);
	}
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxQSize;
	Q.length++;
}

ElemType DeQueue(Queue &Q,ElemType &e)
{
	ElemType head;
	if(EmptyQueue(Q)) {                                  
		cout<<"EMPTY"<<endl;
		exit(0);
	}
	head=Q.base[(Q.rear+MaxQSize-Q.length+1)%MaxQSize];
	Q.length--;
	if(!EmptyQueue(Q))
	{
		return head;
	}
	exit(-1);
}