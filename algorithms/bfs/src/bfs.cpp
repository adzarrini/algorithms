#include "../lib/Vertex.h"
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

void bfs(Vertex &vertex) {
  int time = 0;
  queue<Vertex*> nodes;
  nodes.push(&vertex);
  while(true) {
    Vertex *current = nodes.front();
    if(current -> isDiscovered()) break;
    current->discover();
    current->setStartTime(time);
    current->setFinishTime(time++);
    vector<Vertex*> edges = current->getEdges();
    vector<Vertex*>::iterator v;
    for(v = edges.begin(); v != edges.end(); v++) {
      if(!((*v)->isDiscovered())) {
        nodes.push(*v);
      }
    }
    nodes.pop();
  }
}
