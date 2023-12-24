//
// Created by admin on 2023/12/19.
//

#include "function.h"

void InitList_L(LinkList &L) {  // 初始化链表L
  L = NULL;
}  // end InitList_L

int ListLength_L(LinkList L) {  // 求链表L的长度
  LinkList p = L;
  int k = 0;
  while (p) {
    k++;
    p = p->next;
  }  // while
  return k;
}  // end ListLength_L

LNode *LocateItem_L(LinkList L, ElemType e) {  // 在链表L中查找元素e
  LinkList p = L;
  while (p && p->data != e) {
    p = p->next;
  }
  return p;
}  // end LocateItem_L

void Reverse(LinkList &pHead) {
  LinkList pre = nullptr;  // 确保倒置后尾结点指向空
  LinkList cur = pHead->next;
  LinkList next;

  while (cur) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  pHead->next = pre;
}

void ListInsert_L(LinkList &L, LNode *p, LNode *s) {
  // 在链表L中，在p所指结点前插入s所指的结点
  if (p == L) {  // p是第一个结点
    s->next = L;
    L = s;
  }       // if
  else {  // p不是第一个结点
    LinkList q = L;
    while (q && q->next != p) q = q->next;  // 找后继是p 的结点
    if (q) {
      q->next = s;
      s->next = p;
    }  // 在p前插入s
    else
      cout << "p不是L中的结点";
  }  // else
}    // end ListInsert_L

LinkList CreateList() {  // 创建单链表 L
  LinkList head, L, p;
  int data;
  L = nullptr;
  cout << "Input a integer:";
  cin >> data;
  while (data != 0) {
    p = new LNode;
    p->data = data;
    p->next = L;
    L = p;
    cout << "Input a integer:";
    cin >> data;
  }
  head = new LNode;
  head->next = L;
  return head;
}

void ListDelete_L(LinkList &L, LNode *p, ElemType &e) {
  // 在链表L中，删除p所指结点
  if (p == L)
    L = p->next;  // p是第一个结点
  else {          // p不是第一个结点
    LinkList q = L;
    while (q && q->next != p) q = q->next;  // 找后继是p的结点
    if (q)
      q->next = p->next;  // 使p的原前驱直接指向p的后继
    else
      cout << "p不是L中的结点";  // p不在L中
  }                              // else
  e = p->data;
  delete p;  // 保存被删除的元素值，释放空间
}            // end ListDelete_L

void DisplayList(LinkList &L) {  // 打印单链表 L
  LinkList p = L->next;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

LinkList MergeLinkList(LinkList pa, LinkList pb) {
  LinkList a = pa->next;
  LinkList b = pb->next;
  LinkList c = pa;
  LinkList pc = c;

  while (a && b) {
    if (a->data <= b->data) {
      c->next = a;
      a = a->next;
      c = c->next;
    } else if (b->data < a->data) {
      c->next = b;
      b = b->next;
      c = c->next;
    }
  }

  if (a && b == nullptr) {
    c->next = a;
  }

  else if (b && a == nullptr) {
    c->next = b;
  }
  return pc;
}

LinkList Merge(LinkList LA, LinkList LB) {
  LA = LA->next;
  LB = LB->next;
  LinkList head, p;
  // 哨兵节点
  head = p = new LNode;
  // 初始化
  head->next = nullptr;
  // 比较两个链表的元素，按从小到大顺序合并到 head 节点
  while (LA && LB) {
    if (LA->data < LB->data) {
      p->next = LA;
      LA = LA->next;
    } else {
      p->next = LB;
      LB = LB->next;
    }
    p = p->next;
  }
  // 将剩余元素接到链表后
  if (LA) {
    p->next = LA;
  }
  if (LB) {
    p->next = LB;
  }
  return head;
}