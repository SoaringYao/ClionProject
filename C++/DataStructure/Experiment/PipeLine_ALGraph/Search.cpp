//
// Created by admin on 2023/11/28.
//

#include "Search.h"

int MinEdge(const WeightType lowcost[], int vexnum) {
  int i, k = 0;
  WeightType j;
  while (lowcost[k] == 0) {
    k++;
  }
  j = lowcost[k];
  for (i = k + 1; i < vexnum; i++) {
    if (lowcost[i] != 0 && lowcost[i] < j) {
      j = lowcost[i];
      k = i;
    }
  }
  return k;
}

void Prim(ALGraph G, int v0, int adjvex[]) {
  WeightType lowcost[MAX_VERTEX_NUM];
  int i, k;
  ArcNode* p;
  for (i = 0; i < G.vexnum; i++) {
    if (i != v0) {
      lowcost[i] = 999;
      adjvex[i] = v0;
    }
  }
  p = G.vertices[v0].firstarc;
  while (p) {
    lowcost[p->adjvex] = p->weight;
    p = p->nextarc;
  }
  lowcost[v0] = 0;
  for (i = 0; i < G.vexnum; i++) {
    k = MinEdge(lowcost, G.vexnum);//k是最小的边的邻接点的编号
    if (k >= G.vexnum) return;
    cout << "(" << G.vertices[adjvex[k]].data << "," << G.vertices[k].data
         << ")," << lowcost[k] << endl;
    lowcost[k] = 0;
    p = G.vertices[k].firstarc;
    while (p) {
      if (p->weight < lowcost[p->adjvex]) {
        adjvex[p->adjvex] = k;
        lowcost[p->adjvex] = p->weight;
      }  // end if
      p = p->nextarc;
    }  // end while
  }    // end for
}  // prim