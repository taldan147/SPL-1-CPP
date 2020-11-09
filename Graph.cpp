//
// Created by spl211 on 04/11/2020.
//
#include "Graph.h"
#include "iostream"

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix){
}

int Graph::findNodeToInfect(int node) const {

}

Graph::Graph(std::nullptr_t):edges(){

}

void Graph::infectNode(int nodeInd) {

}

bool Graph::isInfected(int nodeInd) {
    return false;
}

bool Graph::isAllFullyInfected() const {

    return Clean;
}

std::vector<Graph *> Graph::SplitIntoConnectedComponents() {
    return std::vector<Graph *>();
}

spread Graph::isSick(Graph *g) {
    return Clean;
}

Graph &Graph::disconnectNode(int nodeToDisconnect) {
    return ;
}
