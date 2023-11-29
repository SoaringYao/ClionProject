//
// Created by admin on 2023/11/19.
//

#ifndef HUFFMANCODECSYSTEM_HUFFMANCODEC_H
#define HUFFMANCODECSYSTEM_HUFFMANCODEC_H

#include "define.h"

HTNode *InitHTNode(int n);
void Select(HuffmanTree &HT, int i, int &s1, int &s2);
int Min(HuffmanTree HT, int n);
bool CreateHuffmanTree(HuffmanTree &HT, int n, const int *w);
bool CountTreeByToBeTran(Number &num, HuffmanTree &HT);
bool CountTreeByInput(Number &num, HuffmanTree &HT);
bool CountTreeByHuffTree(Number &num, HuffmanTree &HT);
bool outPut_CodeFile(Sqlist &CD);
void HuffmanCoding(HuffmanTree &HT, Sqlist &CD, Number &num);
void Coding(HuffmanTree &HT, int root, Sqlist &CD, Number &num, SqStack &S);
bool outPut_hfmTree(HuffmanTree HT, Number num);
bool DeCoding(HuffmanTree HT, Number num);
bool Check();
bool CodePrint();
void printHC(Sqlist &CD);
void TreePrint(HuffmanTree HT, Sqlist &CD, int i, int n);
void Print(HuffmanTree HT, Sqlist &CD, int i, int n, ofstream &outfile);

#endif  // HUFFMANCODECSYSTEM_HUFFMANCODEC_H
