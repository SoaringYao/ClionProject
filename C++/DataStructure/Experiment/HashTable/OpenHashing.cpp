//
// Created by admin on 2023/11/30.
// Separate Chaining
//

#include "OpenHashing.h"

int Hash(KeyType k) {
  return ((k[0] - 96) * 100 + k[k.length() - 1]) % 41;
}  // Hash

LHptr SearchLHash(LHashTable H, const KeyType &k, LHptr &q) {
  // 在开散列哈希表H中查找关键字为k的元素，若查找成功，则返回该元素的位置指针，q指向前驱(无前驱时指向nullptr)
  // 如果查找不成功，返回nullptr，同时q指向链表尾部结点或nullptr
  LHptr p = H.elem[Hash(k)];
  q = nullptr;
  while (p && p->data.key != k) {
    q = p;
    p = p->next;
  }
  return p;
}  // SearchLHash

bool InsertLHash(LHashTable &H, const ElemType &e) {
  // 在开散列哈希表H中插入记录e，如果插入成功，返回true
  // 如果插入不成功(如已经有该关键码元素)，返回false
  LHptr q = nullptr;
  if (SearchLHash(H, e.key, q)) return false;
  auto s = new LHNode;
  s->data = e;
  s->next = nullptr;
  if (q)
    q->next = s;
  else
    H.elem[Hash(e.key)] = s;
  H.count++;
  return true;
}  // InsertLHash

bool DeleteLHash(LHashTable &H, ElemType e) {
  // 在开散列哈希表H中删除记录e，如果删除成功，返回true
  // 如果删除不成功，返回false
  LHptr q = nullptr;
  LHptr p = SearchLHash(H, e.key, q);
  if (!p) return false;
  if (q)
    q->next = p->next;
  else
    H.elem[Hash(e.key)] = p->next;
  delete p;
  H.count--;
  return true;
}  // DeleteLHash
