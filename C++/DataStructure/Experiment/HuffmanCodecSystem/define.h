//
// Created by admin on 2023/11/19.
//

#ifndef HUFFMANCODECSYSTEM_DEFINE_H
#define HUFFMANCODECSYSTEM_DEFINE_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "SqStack.h"

using namespace std;

#define MAXSIZE 65535
#define MAX_WEIGHT 65535
#define OK 1

typedef struct {
  int weight;
  int parent, lchild, rchild;
} HTNode;

typedef struct HuffmanTree {
  HTNode *node;
  int leafNum, nodeNum;
  int root;
} HuffmanTree;

typedef struct {
  int num;  // 出现次数
  char ch;  // 字符
} ElemType_1;

typedef struct {
  ElemType_1 data[MAXSIZE];
  int length;
} Number;  // Frequency

typedef struct {
  char data;
  string code;
} ElemType_2;

typedef struct {
  ElemType_2 *chars;
  int length;
} Sqlist;  // Code

#endif  // HUFFMANCODECSYSTEM_DEFINE_H
