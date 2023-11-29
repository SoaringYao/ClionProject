//
// Created by admin on 2023/11/28.
//

#ifndef PIPELINE_ALGRAPH_SEARCH_H
#define PIPELINE_ALGRAPH_SEARCH_H

#include"ALGraph.h"

int MinEdge(const WeightType lowcost[],int vexnum);
void Prim(ALGraph G,int v0, int adjvex[]);

#endif  // PIPELINE_ALGRAPH_SEARCH_H
