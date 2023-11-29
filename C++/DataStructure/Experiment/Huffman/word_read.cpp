#include "huffman.h"

void Count(word *&A) {
   char a[100];
   Read(a);
   InitWord(A);  // 初始化
   int i = 0;
   while (a[i]) {
      TravelWord(A, a[i]);
      i++;
   }
}

// read article
void Read(char *a) {
   int i = 0;
   ifstream fin;
   fin.open("../word.txt", ios::in);  // 读入字母为大写
   if (!fin.is_open()) {
      std::cerr << "cannot open the file";
   }
   while (fin.get(a[i])) {
      i++;
   }
   a[i] = 0;
   fin.close();
}

// InitList
void InitWord(word *&phead) {
   phead = new word;
   if (phead == nullptr) {
      std::cerr << "InitList error";
      exit(1);
   }
   phead->next = nullptr;
}

// 遍历链表，有则加一，无则创建
void TravelWord(word *phead, char a) {
   word *p = phead->next;
   word *q = phead;
   if (islower(a)) {
      a = char(int(a) + 32);
   }
   while (p) {
      if (p->ch == a) {
         p->num++;
         return;
      }
      p = p->next;
      q = q->next;
   }
   word *text = new word;
   text->ch = a;
   text->num = 1;
   q->next = text;
   text->next = nullptr;
}

// 清空链表
void DestroyWord(word *phead) { delete[] phead; }

// 打印
void print(word *phead) {
   word *p = phead->next;
   cout << "Word Frequency:" << endl;
   while (p) {
      cout << p->ch << ":" << p->num << endl;
      p = p->next;
   }
   cout << endl;
}
