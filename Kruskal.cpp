// Name: Deren Lei
// Email: derenlei@umail.ucsb.edu

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <cstdlib>
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
  if(index(value) == -1) { return -1; }
  while(value != uf[index(value)].second) {
    value = uf[index(value)].second;
  }
  return index(value);
}

// Check if p and q have the same root (loop exists if adding p and q)
bool Kruskal::find(int p, int q){
  if(root(p) == -1 || root(q) == -1) { return false; }
  return root(p) == root(q);
}

// merge when adding an edge between p and q
void Kruskal::merge(int p, int q){
  int i = root(p);
  int j = root(q);
  uf[i].second = uf[j].second;
}

// Add the top edge to the tree
void Kruskal::addEdge(){
  // Step 1: pop top edge from priority queue and
  // test whether it will cause a loop if it's not mandatory (bid)

  edge e = edges.top();
  //cout << "Pop " << e.point1 << " " << e.point2 << " " << e.weight << endl;
  edges.pop();

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
  //cout << "Tree size " << edges.size() << endl;
  while(!edges.empty()){
    //cout << "Add edge ";
    addEdge();
  }
}

// Number of connected components
int Kruskal::component(){
  set<int> roots;
  //cout << uf.size();
  for(int i = 0; i < uf.size(); i++){
    int rootValue = root(uf[i].first);
    //cout << root(uf[i].first) << endl;
    if(roots.find(rootValue) == roots.end()){
      //cout << "Insert" << rootValue << endl;
      roots.insert(rootValue);
    }
  }
  return roots.size();
}

// sort the tree vector based on weight
void Kruskal::sortTree(){
  vector<edge> temp;
  while(tree.size() != 0){
    int min = tree[0].weight;
    int eraseIndex = 0;
    for (int i = 0; i < tree.size(); i++){
      if(tree[i].weight < min) {
        min = tree[i].weight;
        eraseIndex = i;
      }
    }
    temp.push_back(tree[eraseIndex]);
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
    cout << "(" << min << "," << max << ") ";
  }
  cout << endl;
}
/*
// Find all nodes connected to
vector< vector<int> > Kruskal::connections(int node, int weight){
  vector< vector<int> > connections; //< to, from, weight>
  for(int i = 0; i < tree.size(); i++){
    if(node == tree[i].point1) {
      vector<int> temp = {tree[i].point2, node, weight + tree[i].weight};
      connections.push_back(temp);
    }
    else if(node == tree[i].point2) {
      vector<int> temp = {tree[i].point1, node, weight + tree[i].weight};
      connections.push_back(temp);
    }
  }
  return connections;
}


void Kruskal::path(int start, int end){
  vector< vector<int> > nodes;
  vector< vector<int> > route; //< to, from, weight>
  int beginNode = start;
  int weight = 0;
  while(true){

    route = connections(beginNode, weight);

    // find the minimum weight one from route and store weight
    int minWeight = path[0][2];
    int beginNode = path[0][1];
    for(int i = 0; i < path.size()){
      if(path[i][2] < minWeight){
        minWeight = path[i][2];
        beginNode = path[i][1];
      }
    }
    weight = minWeight;



    if(beginNode == end) { break; }
  }
}
*/
