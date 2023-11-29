//
// Created by admin on 2023/11/28.
//

#ifndef PIPELINE_ALGRAPH_ALGRAPH_H
#define PIPELINE_ALGRAPH_ALGRAPH_H

#define MAX_VERTEX_NUM 50

#include "define.h"

typedef float WeightType;  // 权值类型
typedef char VertexType;   // 顶点类型
typedef int GraphKind;     // 图的类型(有向/无向、网/图)

typedef struct ArcNode {
  int adjvex;//该边的邻接点编号
  WeightType weight;
  ArcNode *nextarc;//指向下一条边的指针
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
  AdjList vertices;  // 顶点
  int vexnum, arcnum;
  GraphKind kind;
} ALGraph;

//操作函数
void CreateALGraph(ALGraph &G);
int LocateVertex(ALGraph G, VertexType v);
void InsertArc(ALGraph &G, VertexType vi, VertexType vj, WeightType wt);
int FirstAdjVex(ALGraph G,VertexType v);
int NextAdjVex(ALGraph G,VertexType v,VertexType w);

#endif  // PIPELINE_ALGRAPH_ALGRAPH_H
