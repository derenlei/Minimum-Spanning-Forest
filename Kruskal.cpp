// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include "Kruskal.h"

using namespace std;

Kruskal::Kruskal(){
  totalWeight = 0;
  loop = false;
}

int Kruskal::index(int value){
  for(int i = 0; i < uf.size(); i++){
    if(uf[i].first == value){ return i; }
  }
  return -1; // if not exist
}

// Find root's index for value
int Kruskal::root(int value){
  while(value != uf[index(value)].second) {
    value = uf[index(value)].second;
  }
  return index(value);
}

// Check if p and q have the same root (loop exists if adding p and q)
bool Kruskal::find(int p, int q){ return root(p) == root(q); }

// merge when adding an edge between x and y
void Kruskal::merge(int x, int y){
  int i = root(p);
  int j = root(q);
  uf[i].second = uf[j].second;
}

// Add the top edge to the tree
void Kruskal::addEdge(){
  // Step 1: pop top edge from priority queue and
  // test whether it will cause a loop if it's not mandatory (bid)
  edge e = edges.pop();
  if(e.mandatory == 1){
    if(find(e.point1, e.point2)){ loop = true; }
  }
  // Step 2: if no loop or mandatory, add it to the tree vector and
  // add the totalWeight and uf
  if(!find(e.point1, e.point2) || e.mandatory == 1){
    totalWeight += e.weight;
    tree.push_back(e);
    if(index(e.point1) == -1) { uf.push_back(make_pair(e.point1,e.point1)); }
    if(index(e.point2) == -1) { uf.push_back(make_pair(e.point2,e.point2)); }
    merge(e.point1, e.point2);
  }
}

// Add all suitable edges from priority queue
void Kruskal::addEdges(){
  while(!tree.empty()){
    addEdge();
  }
}

// Number of connected components
int Kruskal::component(){
  set<int> roots;
  for(i = 0; i < uf.size(); i++){
    int root = root(uf[i].first);
    if(roots.find(root) != roots.end()){ roots.insert(root); }
  }
  return roots.size();
}

// sort the tree vector based on weight
void Kruskal::sortTree(){
  vector<edge> temp;
  while(tree.size() != 0){
    int min = tree[0].weight;
    int earseIndex = 0;
    for (int i = 0; i < tree.size(); i++){
      if(tree[i].weight < min) {
        min = tree[i].weight;
        eraseIndex = i;
      }
    }
    temp.push_back(min);
    tree.erase(tree.begin() + eraseIndex);
  }
  tree = temp;
}

void Kruskal::printTree(){
  sortTree();
  for(int i = 0; i < tree.size(); i++){
    int max = tree[i].point1, min = tree[i].point2;
    if(max < min){
      int temp = max;
      max = min;
      min = temp;
    }
    cout << "(" + min + "," + max + ") ";
  }
  cout << endl;
}
