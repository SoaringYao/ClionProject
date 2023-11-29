#include"queue.h"

int main()
{
	SqQueue l1;
	Elemtype num;

	Init_SqQueue(l1);				//创造空队列l1
	empty_SqQueue(l1);					//调用判空函数判断队列是否为空

	for(int i=0;i<10;i++)
	{
		insert_SqQueue(l1,i);			//把0-9入队l1
		print_SqQueue(l1);
	}

	printf("现在");
	empty_SqQueue(l1);					//调用判空函数判断队列是否为空
	
	printf("现在开始出队:\n");
	for(int i=0;i<10;i++)
	{
		del_SqQueue(l1,num);			//把0-9入队l1
		print_SqQueue(l1);
	}
	
	printf("现在");
	empty_SqQueue(l1);					//调用判空函数判断队列是否为空

	return 0;
}