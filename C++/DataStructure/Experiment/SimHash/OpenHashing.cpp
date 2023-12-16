//
// Created by admin on 2023/12/13.
//

#include "OpenHashing.h"

void CreateHash(LHashTable &H) {
  KeyType keyword[23];  // typedef char *KeyType 此处为23个指针数组
  LHptr p;
  char ch;
  int n;
  int i, j;
  ifstream fin("../file/keywords.txt", ios::in);

  keyword[0] = new char[30];  // 给指针数组分配空间

  for (i = 1; i < 23; i++) {
    keyword[i] = new char[10];
  }

  fin.get(keyword[0], 26);
  // 将"const char *keywords[] = "存入keyword[0],关键字从1开始存储

  i = 1, j = 0;
  while (!fin.eof()) {
    fin.get(ch);

    if (ch >= 97 && ch <= 122) {
      keyword[i][j] = ch;
      j++;

    } else {
      keyword[i][j] = '\0';
      j = 0;
      i++;
    }
  }

  H.size = 43;
  H.count = 0;
  H.elem = new LHptr[H.size];  // 初始化为所有结点指针的头指针
  for (i = 0; i < H.size; i++) {
    H.elem[i] = new LHNode;  // 为单个结点分配空间
    H.elem[i]->next = nullptr;
  }
  for (i = 1; i < 18; i++) {
    n = Hash(keyword[i]);
    p = new LHNode;
    p->next = nullptr;
    p->data.Data = 0;  // 计数
    p->data.key = new char[10];
    // p->data.key=keyword[i];
    strcpy(p->data.key, keyword[i]);

    if (!H.elem[n]->next) {
      H.elem[n]->next = p;
    } else {
      p->next = H.elem[n]->next;
      H.elem[n]->next = p;
    }
    // cout<<" "<<p->data.key<<n;
  }
  /* p=H.elem[0]->next;
   while(p){
      cout<<" "<<p->data.key;
      p=p->next;
   }*/
  fin.close();
}

int Hash(KeyType key) {
  int n;
  n = (key[0] * 100 + FindLast(key)) % 41;
  return n;
}

void SearchHash(LHashTable H, int n, KeyType key) {
  LHptr p;
  p = H.elem[n]->next;
  while (p) {
    // if(!key.compare(p->data.key)){
    if (!strcmp(key, p->data.key)) {  // 等于则返回0
      p->data.Data++;
      break;
    }
    p = p->next;
  }
}

char FindLast(const KeyType key) {
  int i = 0;
  char ch;
  while (key[i] != '\0') {
    ch = key[i];
    i++;
  }
  return ch;
}