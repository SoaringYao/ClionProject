#ifndef WORD_READ_H
#define WORD_READ_H

#include "huffman.h"
typedef struct word {
   char ch;
   int num;
   word *next;
} word;

// 统计单词频度
void Read(char *a);

void InitWord(word *&phead);

void Count(word *&A);

void TravelWord(word *phead, char a);

void DestroyWord(word *phead);

void print(word *phead);

#endif