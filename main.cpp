#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <cstdlib>
#include "Kruskal.h"

using namespace std;

vector<string> strToVec(string sentence){
  vector<string> vec;
  string element = "";
  for(int i=0; i < sentence.length(); i++){
    if(sentence[i] == ' '){
      vec.push_back(element);
      element = "";
    }
    else if (i == sentence.length() - 1){
      element += sentence[i];
      vec.push_back(element);
    }
    else{
      element += sentence[i];
    }
  }
  return vec;
}

int main(){
  Kruskal kruskal;
  string line;
  edge e;
  while(true){
    getline(cin, line);
    vector<string> words= strToVec(line);
      if (words[0] == "BID"){
        e.point1 = atoi(words[1].c_str());
        e.point2 = atoi(words[2].c_str());
        e.weight = atoi(words[3].c_str());
        e.mandatory = 0;
        kruskal.edges.push(e);
      }
      else if (words[0] == "MANDATORY"){
        e.point1 = atoi(words[1].c_str());
        e.point2 = atoi(words[2].c_str());
        e.weight = atoi(words[3].c_str());
        e.mandatory = 1;
        kruskal.edges.push(e);
      }
      else if (words[0] == "COST?"){
        kruskal.addEdges();
        cout << kruskal.totalWeight << endl;
      }
      else if (words[0] == "COMPONENTS?"){
        kruskal.addEdges();
        cout << kruskal.component() << endl;
      }
      else if (words[0] == "CYCLE?"){
        kruskal.addEdges();
        if(kruskal.loop){ cout << "YES" << endl; }
        else { cout << "NO" << endl; }
      }
      else if (words[0] == "LIST?"){
        kruskal.addEdges();
        kruskal.printTree();
      }
      else if (words[0] == "END"){ exit(0); }
      else if (words[0] == "SHORTEST_PATH?"){
        kruskal.addEdges();
        //TODO
      }
      line = "";
    }
    return 0;
}
