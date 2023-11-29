#include "queue.h"

int main(){
	Queue Q=InitQueue();
	
	char c[20];
	int i,j,len;
	ElemType e;
	cout<<"输入入队元素:";
	cin>>c;
	for(i=0;c[i]!='\0';i++)
	{
		EnQueue(Q,c[i]);
		len=Q.length;
	}
	cout<<"出队后队列头元素的值为：";
	for(j=0;j<len;j++)
	{
		cout<<DeQueue(Q,e)<<" ";
	}
	return 0; 
	
}
