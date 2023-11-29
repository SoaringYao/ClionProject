#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <ctype.h>
#include <string.h>

#include <fstream>
#include <iomanip>
#include <iostream>

#include "SqStack.h"
#include "function.h"
#include "word_read.h"

#define MAX_WEIGHT 65535

typedef int WeightType;  // 权值类型
typedef char **HuffCode;

using namespace std;

typedef struct {
  WeightType weight;
  int parent;
  int lchild, rchild;
} HTNode;  // 哈夫曼树结点类型

typedef HTNode *HuffTree;  // 存放哈夫曼树的三叉链表类型

// 哈夫曼树函数
void HuffmanTree(HuffTree &HT, const WeightType *W, int n);

void HuffmanCoding(HuffTree HT, HuffCode &HC, int n);

void load(word *phead, int *a);  // 将频度存入数组
int getlength(const int *a);     // 计算叶子数(有效频度个数)
void printHT(HuffTree HT, int n);

void printHC(char **HC, int n, word *phead);

void DestroyHC(char **HC, int n);

// 辅助函数
void Select(HuffTree &HT, int i, int &s1,
            int &s2);  // 选择HT[1..i]中权值最小和次小的结点序号
int Min(HuffTree HT, int n);  // 求哈夫曼树HT中n个权值的最小值
void Coding(HuffTree HT, int root, HuffCode &HC,
            SqStack &S);  // 先序遍历求每个字符的哈夫曼编码, 存入数组HC

#endif