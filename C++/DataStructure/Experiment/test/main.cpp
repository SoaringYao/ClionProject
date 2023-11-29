//
// Created by admin on 2023/11/18.
//
#include <cstdio>
#include <iostream>

typedef struct word {
   char ch;
   int num;
   word *next;
} word;

using namespace std;

void InitWord(word *&phead) {
   phead = new word;
   if (phead == nullptr) {
      std::cerr << "InitList error";
      exit(1);
   }
   phead->next = nullptr;
};

int main() {
   char ch;
   int num = 0;
   word *phead;
   InitWord(phead);
   word *q = phead;
   cin >> ch;
   cin >> num;
   while (ch != '\r') {
      word *text = new word;
      text->ch = ch;
      text->num = num;
      q->next = text;
      text->next = nullptr;
      cin >> ch;
      cin >> num;
      getchar();
   }
   while (phead->next != nullptr) {
      cout << phead->next->ch << " " << phead->next->num << endl;
      phead = phead->next;
   }
}
