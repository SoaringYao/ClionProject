#include <iostream>
#define ElemType int

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;

using namespace std;

/*
void InitList_L(LinkList &L)
{ // 初始化链表L
    L = NULL;
} // end InitList_L
*/

int ListLength_L(LinkList L)
{ // 求链表L的长度
    LinkList p = L;
    int k = 0;
    while (p)
    {
        k++;
        p = p->next;
    } // while
    return k;
} // end ListLength_L

Lnode *LocateItem_L(LinkList L, ElemType e)
{ // 在链表L中查找元素e
    LinkList p = L;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
} // end LocateItem_L

void ListOppose(LinkList &L)
{
    LinkList q, p, s;
    p = L;
    p = p->next;
    L->next = NULL;
    while (p) // 因为 while 中有 p = p->next 所以终止条件不用写成 p->next
    {
        q = p;
        p = p->next;
        q->next = L->next; // q 节点指向现在的 L 的首元结点
        L->next = q;
    }
}

void ListInsert_L(LinkList &L, Lnode *p, Lnode *s)
{ // 在链表L中，在p所指结点前插入s所指的结点
    if (p == L)
    { // p是第一个结点
        s->next = L;
        L = s;
    } // if
    else
    { // p不是第一个结点
        LinkList q = L;
        while (q && q->next != p)
            q = q->next; // 找后继是p 的结点
        if (q)
        {
            q->next = s;
            s->next = p;
        } // 在p前插入s
        else
            cout << "p不是L中的结点";
    } // else
} // end ListInsert_L

LinkList CreateList(void)
{ // 创建单链表 L
    LinkList head,L,p;
    int data;
    L=NULL;
    cout<<"Input a integer:";
    cin>>data;
    while(data!=0)
    {
        p= new Lnode;
        p->data=data;
        p->next=L;
        L=p;
        cout<<"Input a integer:";
        cin>>data;
    }
    head=new Lnode;
    head->next = L;
    return head;
}

void ListDelete_L(LinkList &L, Lnode *p, ElemType &e)
{ // 在链表L中，删除p所指结点
    if (p == L)
        L = p->next; // p是第一个结点
    else
    { // p不是第一个结点
        LinkList q = L;
        while (q && q->next != p)
            q = q->next; // 找后继是p的结点
        if (q)
            q->next = p->next; // 使p的原前驱直接指向p的后继
        else
            cout << "p不是L中的结点"; // p不在L中
    }                                 // else
    e = p->data;
    delete p; // 保存被删除的元素值，释放空间
} // end ListDelete_L

void DispList(LinkList &L)
{ // 打印单链表 L
    LinkList p = L->next;
    while (p)
    {
        cout << p->data<<" ";
        p = p->next;
    }
    cout << endl;
}
