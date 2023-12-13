//
// Created by admin on 2023/12/13.
//

#include "system.h"

void system() {
  LHashTable H;
  double Similarity;  // Similarity
  double Distance;    // Geometric Distance
  int SimVec[17];
  int DifVec[17];
  int MainVec[17];

  CreateHash(H);
  CreateEigenvector(H, SimVec, "../file/similar.c");
  CreateEigenvector(H, DifVec, "../file/different.c");
  CreateEigenvector(H, MainVec, "../file/main.c");

  cout << endl;

  Similarity = SAsses(SimVec, MainVec);
  cout << "S_(Sim&Main):" << Similarity << endl;
  Distance = DAsses(SimVec, MainVec);
  cout << "D_(Sim&Main):" << Distance << endl << endl;

  Similarity = SAsses(DifVec, MainVec);
  cout << "S_(Dif&Main):" << Similarity << endl;
  Distance = DAsses(DifVec, MainVec);
  cout << "D_(Dif&Main):" << Distance << endl;
}
