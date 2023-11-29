//
// Created by admin on 2023/11/24.
//

#include "Search.h"

void system(){
  int areaNum;// 居民区个数
  float price;//管道单位长度价格
  float areaArray[MaxNum][MaxNum];//将表示居民区的无向图用邻接矩阵表示
goon:
  if(Read(areaNum,areaArray,price)){
    cout << "无向图读取完毕!" << endl;
  }
  if(Find(areaNum,areaArray,price)){
    cout << "管道铺设方案已找到!" << endl<<endl;
  }
  char choice;
  cout << "清空数据,重新输入?    YES(y) or NO(n) : ";
  cin >> choice;
  if (choice == 'y'){
    goto goon;
  }
  if (choice == 'n'){
    cout << "成功退出!"<<endl<<endl;
    exit(0);//退出程序
  }
}

bool Read(int &areaNum,float areaArray[MaxNum][MaxNum],float &price){
  cout << "*****管道铺设施工的最佳方案选择*****" << endl<<endl;
  int lineNum;// 管道条数
  int area1, area2;// 某管道的两个居民区
  float distance;
  int i, j;//指示
  FILE *f;
  if((f = fopen("../map.txt", "rb")) == nullptr)
  {
    cout<<"文件无法打开"<<endl;
    return false;
  }
  fscanf(f, "%d", &areaNum);
  fscanf(f, "%d", &lineNum);
  fscanf(f, "%f", &price);
  for (i = 0; i < areaNum; i++){
    for (j = 0; j < areaNum; j++){
      areaArray[i][j] = undefinedNum;
    }
  }
  cout << "正在从文件中读取无向图…………"<<endl;
  j = 1;//j表示第n条线路
  for (i = 0; i < lineNum; i++)
  {
    fscanf(f, "%d", &area1);
    fscanf(f, "%d", &area2);
    fscanf(f, "%f", &distance);
    areaArray[area1][area2] = distance;
    areaArray[area2][area1] = distance;
    j++;
  }
  fclose(f);
  return true;
}

bool Find(int &areaNum,float areaArray[MaxNum][MaxNum],float &price){
  int i, j;//指示
  char a[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'};
  float short_way[MaxNum];// 居民区i距离目前生成树的点集中某个居民区的最短路程
  float lower_distance = 0;//两居民区间的距离,最短总路线长度
  float min_way;// 目前生成树的点集外顶点到目前生成树的点集内顶点具有最短路径的边
  int temp_area;// 与目前生成树的点集路程最短的居民区
  int near_area[MaxNum];// 目前生成树的点集中能使距离下个居民区最近的居民区
  for (i = 1; i < areaNum; i++)//将第一个顶点0加入最小生成树的点集中
  {
    short_way[i] = areaArray[0][i];
    near_area[i] = 0;
  }
  short_way[i] = 0;
  near_area[i] = 0;
  cout << "居民小区管道铺设最优方案设计如下:"<<endl;
  for (i = 1; i < areaNum; i++)//第一个顶点0已加入生成树,循环将剩下的n-1个顶点加入生成树
  {
    min_way = undefinedNum;
    j = 1;
    temp_area = 1;
    while (j < areaNum)
    {
      if (short_way[j] != 0 && short_way[j] < min_way)
      {
        min_way = short_way[j];
        temp_area = j;
      }
      j++;
    }
    cout << "("<<a[near_area[temp_area]]<<","<<a[temp_area]<<")" << endl;
    short_way[temp_area] = 0;
    lower_distance += min_way;//计算最短总长度
    for (j = 0; j < areaNum; j++)//更新候选最短路径数组
      if (areaArray[temp_area][j] < short_way[j])
      {
        short_way[j] = areaArray[temp_area][j];
        near_area[j] = temp_area;
      }
  }
  cout << "最短总长度为: " << lower_distance << "米" << endl;
  cout << "最低总造价为: " << lower_distance * price << "元" << endl;
  return true;
}