#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

//带头结点的循环单链表队列,只有一个尾指针
struct Queue{
	Elemtype date;
	Queue *next;
};

typedef struct 
{
	Queue *rear;

}SqQueue;

int Init_SqQueue(SqQueue &p);

//入队函数,表尾插入
int insert_SqQueue(SqQueue &p,Elemtype e);

//出队函数,表头出队
int del_SqQueue(SqQueue &p,Elemtype &e);

//判断是否空队列函数
bool empty_SqQueue(SqQueue &p);

//遍历队列所有元素
void print_SqQueue(SqQueue &p);

#endif