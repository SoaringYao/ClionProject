//
// Created by admin on 2023/11/30.
// Separate Chaining
//

#include "OpenHashing.h"

LHptr SearchLHash(LHashTable H, KeyType k, LHptr &q) {
  LHptr p;
  p = H.elem[Hash(k)];
  q = nullptr;
  while (p && p->data.key != k) {
    q = p;
    p = p->next;
  }
  return p;
}  // SearchLHash

bool InsertLHash(LHashTable &H, ElemType e) {}  // InsertLHash

bool DeleteLHash(LHashTable &H, ElemType e) {}  // DeleteLHash

int Hash(KeyType k) { return ((k[0] - 96) * 100 + k[k.length() - 1]) % 41; }