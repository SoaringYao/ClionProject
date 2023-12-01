//
// Created by admin on 2023/11/30.
// Open Addressing
//

#ifndef HASHTABLE_CLOSEDHASHING_H
#define HASHTABLE_CLOSEDHASHING_H

typedef char ElemType;
typedef int KeyType;

typedef struct {
  ElemType *elem;  // 记录存储基址
  int count;       // 记录数
  int size;        // 哈希表容量
} OHashTable;

bool SearchOHash(OHashTable H, KeyType k,int &p);
bool InsertOHash(OHashTable &H, ElemType e);
bool DeleteOHash(OHashTable &H, ElemType e);
#endif  // HASHTABLE_CLOSEDHASHING_H
