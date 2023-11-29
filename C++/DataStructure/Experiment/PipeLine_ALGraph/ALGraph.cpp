//
// Created by admin on 2023/11/28.
//

#include "ALGraph.h"

void CreateALGraph(ALGraph& G) {
  VertexType vi, vj;
  ArcNode* p;
  int i, j;
  WeightType wt = 0;
  //cout << "请输入顶点个数,边数和图的类型:" << endl;
  cin >> G.vexnum >> G.arcnum >> G.kind;  // 输入顶点数和边数和图类型
  //cout << "请输入各顶点的值" << endl;
  for (int k = 0; k < G.vexnum; k++) {
    cin >> G.vertices[k].data;         // 顶点的值
    G.vertices[k].firstarc = nullptr;  // vi边链的头指针置空
  }
  //cout << "请输入两顶点和其边的权值:" << endl;
  for (int k = 0; k < G.arcnum; k++) {
    if (G.kind == 3 || G.kind == 4)  // 网
      cin >> vi >> vj >> wt;
    else
      cin >> vi >> vj;
    p = new ArcNode;
    i = LocateVertex(G, vi);
    j = LocateVertex(G, vj);
    p->weight = wt;
    // 该边的终点是j
    p->adjvex = j;
    // 将该边结点链接到i号顶点,vi->vj的下一条边是原本vi的第一条边
    p->nextarc = G.vertices[i].firstarc;
    // i号顶点的第一条边变为p
    G.vertices[i].firstarc = p;

    if (G.kind == 2 || G.kind == 4) {  // 无向
      p = new ArcNode;
      p->weight = wt;
      p->adjvex = i;
      p->nextarc = G.vertices[j].firstarc;
      G.vertices[j].firstarc = p;
    }  // end if
  }    // end for
}  // CreateALGraph

int LocateVertex(ALGraph G, VertexType v) {
  // 查找值为v的顶点在图G中的存储位置
  // 如果图G中存在顶点v，返回v的位置下标
  // 否则返回-1
  for (int i = 0; i < G.vexnum; i++)
    if (G.vertices[i].data == v) return i;
  return -1;
}  // LocateVertex

int FirstAdjVex(ALGraph G, VertexType v) {
  // 求存储下标为v的顶点的第一个邻接点
  // 如果这样的邻接点存在，返回它的下标;
  // 否则返回-1
  return G.vertices[v].firstarc != nullptr ? G.vertices[v].firstarc->adjvex
                                           : -1;
}  // FirstAdjVex

int NextAdjVex(ALGraph G, VertexType v, VertexType w) {
  // 求存储下标为v的顶点的下一个邻接点
  // 即在下标为v的顶点边链表中，找值为w的边结点的直接后继
  // 如果下一个邻接点不存在，返回-1
  ArcNode* p;
  p = G.vertices[v].firstarc;
  while (p && p->adjvex != w) p = p->nextarc;
  return !p || !p->nextarc ? -1 : p->nextarc->adjvex;
}  // NextAdjVex

void InsertArc(ALGraph& G, VertexType vi, VertexType vj, WeightType wt) {
  // 插入弧<vi,vj>，用带权图表示，wt为弧的权值
  ArcNode* p;
  int i, j;
  i = LocateVertex(G, vi);
  j = LocateVertex(G, vj);
  p = new ArcNode;
  p->weight = wt;
  p->adjvex = j;
  p->nextarc = G.vertices[i].firstarc;
  G.vertices[i].firstarc = p;
  if (G.kind == 2 || G.kind == 4) {  // 无向
    p = new ArcNode;
    p->weight = wt;
    p->adjvex = i;
    p->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p;
  }
}