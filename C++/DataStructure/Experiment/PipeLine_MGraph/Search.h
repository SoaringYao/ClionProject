//
// Created by admin on 2023/11/24.
//

#ifndef PIPELINE_MGRAPH_SEARCH_H
#define PIPELINE_MGRAPH_SEARCH_H

#include <iostream>

#define undefinedNum 9999//默认初始化数据的值
const int MaxNum = 100;//存储图数据的数组的最大值

using namespace std;

bool Read(int &areaNum,float areaArray[MaxNum][MaxNum],float &price);
bool Find(int &areaNum,float areaArray[MaxNum][MaxNum],float &price);
void system();

#endif  // PIPELINE_MGRAPH_SEARCH_H
