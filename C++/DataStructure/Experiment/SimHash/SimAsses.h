//
// Created by admin on 2023/12/13.
//

#ifndef SIMHASH_SIMASSES_H
#define SIMHASH_SIMASSES_H

#include "define.h"
#include "OpenHashing.h"

void CreateVectorSim(LHashTable H, int vector[]);
void CreateVectorDif(LHashTable H, int vector[]);
void CreateVectorMain(LHashTable H, int vector[]);
double X1(const int vector1[], const int vector2[]);
double X2(const int vector1[], const int vector2[]);
// 文件操作函数
bool ReadWord(ifstream &fin, char str[]);

#endif  // SIMHASH_SIMASSES_H
