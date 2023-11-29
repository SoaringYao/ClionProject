#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

void DelPrior(LNode *s){
	int a;
	LNode *p,*q;//q为要删除结点，即s的前驱；p为q的前驱结点 
	p=q=s;
	while(q->next!=s){
		q=q->next;
	}
	while(p->next!=q)
	p=p->next;
	a=q->data;
	p->next=s;
	free(q);
}


LinkList Creat_CircularList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    scanf("%d",&n);//接收结点总数
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        if(rear==NULL)
            rear=head=nw;
        else
        {
            rear->next=nw;
            rear=nw;
        }
    }
    if(rear)
        rear->next=head;
    return head;
}

void PrintCircularList(LinkList s)
{
    LNode *p;
    for(p=s;p->next!=s;p=p->next)
        printf("%d ",p->data);
    printf("%d",p->data);
}

LNode * SetPointerS(LinkList H,int x)
{
    int i;
    LNode *s=H;
    for(i=1;i<x;i++)
        s=s->next;
    return s;
 }
