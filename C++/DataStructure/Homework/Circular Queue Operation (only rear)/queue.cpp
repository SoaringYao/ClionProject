#include"queue.h"

//循环队列构造函数,初始化空队列
int Init_SqQueue(SqQueue &p)
{
	p.rear = (Queue*)malloc(sizeof(Queue));
	if(!p.rear)
	{
		printf("内存分配失败,创造空队列失败!\n");
		return 0;
	}

	p.rear->next = p.rear;           //尾指针的下一个还是自己,空队列自循环
	printf("创造空队列成功!\n");
	return 1;

}

//入队函数,表尾插入
int insert_SqQueue(SqQueue &p,Elemtype e)
{
	Queue *q;
	q = (Queue*)malloc(sizeof(Queue));
	if(!q)
	{
		printf("内存分配失败!\n");
		return 0;
	}
	
	q->date = e;
	q->next = p.rear->next;                     //构成循环，q的下一个是队列头,即原p.rear->next
	p.rear->next = q;                           //入队,插入到表尾之后	
	p.rear = q;                                 //更新表尾指针为q指针
	return 1;
}

//出队函数,表头出队
int del_SqQueue(SqQueue &p,Elemtype &e)
{
	if(p.rear == p.rear->next)
	{
		printf("队列为空!\n");
		return 0;
	}

	Queue *q;                                   //用来保存需要出队的元素指针
	q = p.rear->next->next;                     //rear.next是头节点,头结点下一个节点才是首数据地址
	p.rear->next->next = q->next;               //从队列里面删除q节点
	e = q->date;

	if(q == p.rear)                             //如果队列就一个元素,让队列自循环
		p.rear = p.rear->next;                  
	free(q);

	return 1;
}

//判断是否空队列函数
bool empty_SqQueue(SqQueue &p)
{
	if(p.rear == p.rear->next)
	{
		printf("这是一个空队列!\n");
		return true;
	}
	else
	{
		printf("这不是一个空队列!\n");
		return false;
	}
}

//遍历队列所有元素
void print_SqQueue(SqQueue &p)
{

	Queue *k;
	k = p.rear->next->next;
	while(k!=p.rear->next)
	{
		printf("%d ",k->date);
		k = k->next;
	}
	printf("\n");
}