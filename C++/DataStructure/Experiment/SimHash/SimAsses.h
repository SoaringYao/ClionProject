//
// Created by admin on 2023/12/13.
//

#ifndef SIMHASH_SIMASSES_H
#define SIMHASH_SIMASSES_H

#include "OpenHashing.h"

// 特征向量计算
void CreateEigenvector(LHashTable H, int X[], const string& FileAddress);
double SAsses(const int X1[], const int X2[]);
double DAsses(const int X1[], const int X2[]);

// 文件操作函数
bool ReadWord(ifstream& fin, char str[]);

#endif  // SIMHASH_SIMASSES_H
