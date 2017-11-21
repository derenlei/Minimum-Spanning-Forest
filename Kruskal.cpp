// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <queue>
#include <vector>
#include "Kruskal.h"

using namespace std;

int Kruskal::root(int i){
  while (i != uf[i]){
    i = uf[i];
  }
  return i;
}

// Check if p and q have the same root (loop exists if adding p and q)
bool Kruskal::find(int p, int q){ return root(p) == root(q); }

// merge when adding an edge between x and y
void Kruskal::merge(int x, int y){
  int i = root(p);
  int j = root(q);
  uf[i] = j;
}
