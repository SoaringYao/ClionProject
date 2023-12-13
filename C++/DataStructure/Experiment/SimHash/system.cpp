//
// Created by admin on 2023/12/13.
//

#include "system.h"

void system(){
  LHashTable H;
  double x1, x2;
  int vector1[17];
  int vector2[17];
  int vector3[17];

  CreateHash(H);
  CreateVectorSim(H, vector1);
  CreateVectorDif(H, vector2);
  CreateVectorMain(H, vector3);

  x1 = X1(vector1, vector3);
  cout << x1 << endl;
  x2 = X2(vector1, vector3);
  cout << x2 << endl;

  x1 = X1(vector2, vector3);
  cout << x1 << endl;
  x2 = X2(vector2, vector3);
  cout << x2 << endl;
}
