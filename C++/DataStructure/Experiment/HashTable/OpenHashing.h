//
// Created by admin on 2023/11/30.
//

#ifndef HASHTABLE_OPENHASHING_H
#define HASHTABLE_OPENHASHING_H

#include "define.h"
typedef string KeyType;

typedef struct{
  KeyType key;
  int frequency;// 记录关键字出现的次数
}ElemType;

typedef struct LHNode{
  ElemType data;
  LHNode *next;  // 指向下一个结点
} *LHptr;

typedef struct {
  LHptr *elem;
  int count;  // 记录数
  int size;   // 哈希表容量
} LHashTable;

int Hash(KeyType k);
LHptr SearchLHash(LHashTable H, const KeyType& k, LHptr &q);
bool InsertLHash(LHashTable &H, const ElemType& e);
bool DeleteLHash(LHashTable &H, const ElemType& e);

#endif  // HASHTABLE_OPENHASHING_H
