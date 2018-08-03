#include "Vertex.h"

Vertex::Vertex() {
  discovered = false;
}

Vertex::Vertex(int value) {
  Vertex();
  this->setValue(value);
}

void Vertex::addEdge(Vertex &v) {
  edges.push_back(&v);
}

bool Vertex::isDiscovered() {
  return discovered;
}

void Vertex::discover() {
  discovered = true;
}

int Vertex::getValue() {
  return value;
}

void Vertex::setValue(int value) {
  this->value = value;
}

int Vertex::getStartTime() {
  return startTime;
}

void Vertex::setStartTime(int startTime) {
  this->startTime = startTime;
}

int Vertex::getFinishTime() {
  return finishTime;
}

void Vertex::setFinishTime(int finishTime) {
  this->finishTime = finishTime;
}

std::vector<Vertex*> Vertex::getEdges() {
  return edges;
}
