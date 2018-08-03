#include <vector>

#ifndef Vertex_H
#define Vertex_H

class Vertex {
private:
  bool discovered;
  int value;
  int startTime;
  int finishTime;
  std::vector<Vertex*> edges;

public:
  Vertex();
  Vertex(int node);
  void addEdge(Vertex &v);
  bool isDiscovered();
  void discover();
  int getValue();
  void setValue(int value);
  int getStartTime();
  void setStartTime(int startTime);
  int getFinishTime();
  void setFinishTime(int finishTime);
  std::vector<Vertex*> getEdges();
};

#endif
