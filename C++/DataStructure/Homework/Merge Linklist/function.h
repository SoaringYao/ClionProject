#include <iostream>
#define ElemType int

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

using namespace std;

void InitList_L(LinkList &L);
void ListInsert_L(LinkList &L, LNode *p, LNode *s);
LinkList CreateList();
int ListLength_L(LinkList L);
LNode *LocateItem_L(LinkList L, ElemType e);
void ListDelete_L(LinkList &L, LNode *p, ElemType &e);
void DisplayList(LinkList &L);

LinkList MergeLinkList(LinkList pa, LinkList pb);
LinkList Merge(LinkList LA, LinkList LB);
void Reverse(LinkList &pHead);
