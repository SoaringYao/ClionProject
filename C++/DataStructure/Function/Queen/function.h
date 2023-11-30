// Code file created by C Code Develop

#ifndef FUNCTION_H_H
#define FUNCTION_H_H

#include "stdio.h"
#include "stdlib.h"

#define N 8 
int X[N];//存放解向量
int B[2*N-1],C[2*N-1];//+1-1斜率方向有皇后的标记
int A[N];//某一列是否有皇后的标记

void queen(int i);
void mark(int i,int j, int flag);
int place(int i,int j);

#endif
