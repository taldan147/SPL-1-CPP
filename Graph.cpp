//
// Created by spl211 on 04/11/2020.
//
#include "Graph.h"
using namespace std;
Graph::Graph(std::vector<std::vector<int>> matrix):edges(){
    edges = matrix;
}

Graph::Graph(std::nullptr_t):edges(){

}

void Graph::infectNode(int nodeInd) {

}

bool Graph::isInfected(int nodeInd) {
    return false;
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}


