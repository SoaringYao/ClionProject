//
// Created by admin on 2023/11/30.
//

#ifndef HASHTABLE_OPENHASHING_H
#define HASHTABLE_OPENHASHING_H

#include "define.h"
typedef string KeyType;

typedef struct{
  KeyType key;
}ElemType;

typedef struct LHNode{
  ElemType data;
  LHNode *next;  // 记录数
} *LHptr;

typedef struct {
  LHptr *elem;
  int count;  // 记录数
  int size;   // 哈希表容量
} LHashTable;

int Hash(KeyType k);
LHptr SearchLHash(LHashTable H, KeyType k, LHptr &q);
bool InsertLHash(LHashTable &H, ElemType e);
bool DeleteLHash(LHashTable &H, ElemType e);

#endif  // HASHTABLE_OPENHASHING_H
