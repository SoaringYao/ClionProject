#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>
#define OK 1
#define ERROR 0

typedef struct CSNode
{
    char data;
    struct CSNode *firstchild;
    struct CSNode *nextsibling;
} CSNode, *CSTree;

typedef CSTree ElemType;

#include "SqStack.h"

// 初始化
void InitTree_CS(CSTree &T);
// 接受前序扩展序列建树
int CreateTree_CS(CSTree &T);
// 树的度
int Algo_1(CSTree T);
// 树的深度
int Algo_2(CSTree T);
// 树的叶子
int Algo_3(CSTree T);
// 树的边
void Algo_4(CSTree T);

#endif

// cout << "****叶子****" << endl;
// cout << "叶子结点分别为:" << endl;
// cout << "个数为:" << Algo_3(T) << endl
//      << endl;

// cout << "****边****" << endl;
// cout << "下面输出所有边:" << endl;
// Algo_4(T);
// cout << endl;

// cout << "****度****" << endl;
// cout << "树的度（结点的最大度）为:" << Algo_1(T) << endl
//      << endl;