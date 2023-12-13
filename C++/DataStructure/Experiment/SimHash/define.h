//
// Created by admin on 2023/12/13.
//

#ifndef SIMHASH_DEFINE_H
#define SIMHASH_DEFINE_H

#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

#include "OpenHashing.h"
#include "SimAsses.h"
#include "system.h"

using namespace std;

typedef int Datatype;
typedef char *KeyType;

typedef struct {
  KeyType key;
  Datatype Data;  // 记录关键字出现的次数
} ElemType;       // 包含关键字和数据

typedef struct LHNode {  // 哈希表结点
  ElemType data;         // 查找表单元
  LHNode *next;          // 后继
} *LHptr;

typedef struct {
  LHptr *elem;
  int count;   // 记录数
  int size;    // 容量
} LHashTable;  // 链地址存储法

#endif  // SIMHASH_DEFINE_H
