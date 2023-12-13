//
// Created by admin on 2023/12/13.
//

#ifndef SIMHASH_OPENHASHING_H
#define SIMHASH_OPENHASHING_H

#include "define.h"

void CreateHash(LHashTable &H);
int Hash(KeyType key);
void SearchHash(LHashTable H, int n, KeyType key);
char FindLast(KeyType key);

#endif  // SIMHASH_OPENHASHING_H
