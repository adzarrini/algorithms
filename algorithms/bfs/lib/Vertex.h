#include <vector>

#ifndef Vertex_H
#define Vertex_H

class Vertex {
private:
  bool discovered;
  int value;
  std::vector<Vertex*> edges;

public:
  Vertex();
  Vertex(int node);
  void addEdge(Vertex *v);
  bool isDiscovered();
  void discover();
  int getValue();
  void setValue(int value);
  std::vector<Vertex*> getEdges();

};

#endif
