// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;

struct edge{
  int point1, point2;
  int weight;
  int mandatory; // 0 or 1
  // Sorted mandatory edges at the top of the queue above other sorted edges
  friend bool operator< (const edge &a, const edge &b){
      if(a.mandatory != b.mandatory) { return a.mandatory > b.mandatory; }
      else { return a.weight > b.weight; }
  }
};

class Kruskal{
  public:
    priority_queue<edge> edges;
    // Test whether loop exists; first is value, second is its root value
    vector< pair<int, int> > uf;
    vector<edge> tree;
    int totalWeight;
    bool loop;

    Kruskal();
    // Add all suitable edges from priority queue
    void addEdges();
    // List out the edges
    void printTree();
    // Number of connected components
    int component();
    // print Shorted path from point1 to point2
    void path();
  private:
    // Union Find
    int index(int value); // find value's index in pair vector
    int root(int value);
    // Check if p and q have the same root (loop exists)
    bool find(int p, int q);
    // Set the id of q's root to the id of p's root
    void merge(int p, int q);
    // Add the top edge to the tree
    void addEdge();
    // sort the tree vector based on weight
    void sortTree();
};

#endif
