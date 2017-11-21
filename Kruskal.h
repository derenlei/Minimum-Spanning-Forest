// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge{
  int point1, point2;
  int weight;
  int mandatory;
  // Sorted mandatory edges at the top of the queue above other sorted edges
  bool operator<(edge a,edge b){
    if(a.mandatory != b.mandatory) { return a.mandatory > b.mandatory }
    else { return a.weight > b.weight; }
  }
}


class Kruskal{
  priority_queue<edge> edges;
  vector<int> uf; // Test whether loop exists
  vector<edge> tree; //
  int totalWeight;
  int loopNum;

  // Union Find
  int root(int i);
  // Check if p and q have the same root (loop exists)
  bool find(int p, int q);
  // Set the id of q's root to the id of p's root
  void merge(int p, int q);
  // Add the edge to the tree
  void addEdge(edge);
  // sort the tree vector based on weight
  void sortTree();
  void printTree();
}



#endif
