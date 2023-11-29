#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__

#include <iostream>

using namespace std;

#define Status int
#define QElemType int
#define MaxQSize 100

// 循环队列数据结构
typedef struct
{
    QElemType data[MaxQSize]; // 数据域
    int front, rear;          // 队头队尾指针
} SqQueue;

/***************************基本操作函数**************************/
// 初始化函数
Status InitQueue(SqQueue &Q);
// 判断队空函数
bool QueueEmpty(SqQueue Q);
// 入队函数
bool EnQueue(SqQueue &Q, QElemType e);
// 出队函数
bool DeQueue(SqQueue &Q, QElemType &e);
// 取队头
bool GetHead(SqQueue &Q, QElemType &e);

/**************************功能实现函数****************************/
// 入队功能函数 调用EnQueue函数
void EnterToQueue(SqQueue &Q);
// 出队函数 调用DeQueue函数
void DeleteFromQueue(SqQueue &Q);
// 获得队头元素 调用GetHead函数
void GetHeadOfQueue(SqQueue Q);
// 菜单
void menu();

#endif