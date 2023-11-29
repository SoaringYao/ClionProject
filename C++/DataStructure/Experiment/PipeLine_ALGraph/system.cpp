//
// Created by admin on 2023/11/28.
//

#include "system.h"

void system(){
  int adjvex[MAX_VERTEX_NUM];
  ALGraph G;
  G.kind =3;
  CreateALGraph(G);
  Prim(G,0,adjvex);
}
