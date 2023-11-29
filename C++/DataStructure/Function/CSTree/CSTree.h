#ifndef __CSTREE_H__
#define __CSTREE_H__

#include <iostream>
#include <stack>
 
using namespace std;
 
#define MAXQSIZE  100  //最大队列长度
 
typedef struct CSNode{
    char data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
 
typedef struct {
    CSTree  *base;  // 动态分配存储空间
    int  front;    // 头指针，若队列不空，指向队列头元素
    int  rear;     // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

void InitQueue (SqQueue &Q);
bool EmptyQueue(SqQueue Q);
int  QueueLength (SqQueue Q);
CSTree GetHead(SqQueue Q);
void EnQueue(SqQueue&Q,CSTree e);
void DeQueue (SqQueue&Q);
// 创建结点
CSTree GetTreeNode(char ch);
void printTree(CSTree T, int n);
void CreatTree(CSTree &T);
int CountLeaf(CSTree T);
int TreeDepth(CSTree T);
void PreOrderTraverse(CSTree T);
void InOrderTraverse(CSTree T);
void LevelOrderTraverse(CSTree T);
void AllPath(CSTree T, SqQueue Q);

#endif