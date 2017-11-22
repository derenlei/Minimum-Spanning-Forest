#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include "Kruskal.h"

using namespace std

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
  while(true){
    getline(cin, line);
    vector<string> words= strToVec(line);
    switch(words[0]){
      case "END": exit(0);
      case "LIST?":
        kruskal.printTree();
        break;
      case "COST?":
        cout << kruskal.totalWeight << endl;
        break;
      case "CYCLE?":
        if(loop){ cout << "YES" << endl; }
        else { cout << "NO" << endl; }
        break;
      case "COMPONENTS?":
        cout << kruskal.component() << endl;
        break;
      case: "BID":
        e.point1 = words[1];
        e.point2 = words[2]
        e.weight = words[3]
        e.mandatory = 0;
        kruskal.edges.push(e);
        break;
      case: "MANDAORY":
        e.point1 = words[1];
        e.point2 = words[2]
        e.weight = words[3]
        e.mandatory = 1;
        kruskal.edges.push(e);
        break;
      case: "SHORTEST_PATH?":
        //TODO

    }

    line = "";
  }
  return 0;
}
