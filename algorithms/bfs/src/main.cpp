#include <iostream>
#include <fstream>
#include "../lib/Vertex.h"
#include "./bfs.cpp"

using namespace std;

void parseGraph(vector<Vertex> &graph, const string filePath);
void printGraph(vector<Vertex> &graph);

int main() {
  const string FILE_PATH = "data/input.txt";
  cout << "Hello World!\n\n" << endl;
  vector<Vertex> graph;
  parseGraph(graph, FILE_PATH);
  cout << "Parsing completed!" << endl;
  printGraph(graph);
  bfs(graph[7]);
  cout << "BFS completed!" << endl;
  printGraph(graph);
  return 0;
}

void parseGraph(vector<Vertex> &graph, const string filePath) {
  cout << "File Path: " << filePath << endl;
  ifstream in (filePath);
  if(!in) {
    cerr << "Error: " << strerror(errno) << endl;
  }
  int numVertices;
  in >> numVertices;
  graph.reserve(numVertices);
  int vertexVal, numEdges, edge;
  for (int i = 0; i < numVertices; i++) {
    Vertex vertex(i);
    graph.push_back(vertex);
  }
  for (int i = 0; i < numVertices; i++) {
    in >> vertexVal >> numEdges;
    for(int j = 0; j < numEdges; j++) {
      in >> edge;
      graph[vertexVal].addEdge(graph[edge]);
    }
  }
}

void printGraph(vector<Vertex> &graph) {
  cout << "Graph Size: " << graph.size() << endl << endl;
  vector<Vertex>::iterator g;
  for(g = graph.begin(); g != graph.end(); g++) {
    cout << "Vertex: " << g -> getValue() << endl;
    cout << "Number of Edges: ";
    cout << g -> getEdges().size() << endl;
    cout << "Edges: ";
    vector<Vertex*>::iterator e;
    for(e = g -> getEdges().begin(); e != g -> getEdges().end(); e++) {
      cout << (*e) -> getValue() << " ";
    }
    cout << "\n";
    string discover = (g -> isDiscovered()) ? ("true") : ("false");
    cout << "Discovered: " << discover << endl;
    if(g->isDiscovered()) {
      cout << "Discovery Time: " << g -> getStartTime() << endl;
      cout << "Finish Time: " << g -> getFinishTime() << endl;
    }
    cout << "\n";
  }
}
