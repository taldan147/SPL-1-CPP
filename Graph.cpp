//
// Created by spl211 on 04/11/2020.
//
#include "Graph.h"
#include "iostream"

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix), size(0){
    size = (int)edges.size();
}

int Graph::findNodeToInfect(int node) const {
    for (int i=0; i<size; i++){
        if (node != i && )
    }
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

    for (int i=0; i<size; i++){
        edges[i][nodeToDisconnect]=0;
        edges[nodeToDisconnect][i];
    }
    return *this;
}
