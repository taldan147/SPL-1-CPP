//
// Created by spl211 on 04/11/2020.
//
#include "Graph.h"
#include "iostream"

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix), size(0),nodesStatuses({}){
    size = (int)edges.size();
    nodesStatuses=std::vector<sicknessStatus>(size);
}

int Graph::findNodeToInfect(int node) const {
    for (int i=0; i<size; i++){
        if (node != i &&  edges[node][i] == 1 && nodesStatuses[i] == Clean)
            return i;
    }
    return -1;
}



void Graph::infectNode(int nodeInd) {
    nodesStatuses[nodeInd] = Sick;
}

bool Graph::isInfected(int nodeInd) {
    return nodesStatuses[nodeInd]!=Clean;
}

bool Graph::isAllFullyInfected() const {
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++) {
            if (nodesStatuses[i] != nodesStatuses[j])
                return false;
        }
    }
    return true;
}



sicknessStatus Graph::isSick(Graph *g) {
    return Clean;
}

Graph &Graph::disconnectNode(int nodeToDisconnect) {

    for (int i=0; i<size; i++){
        edges[i][nodeToDisconnect]=0;
        edges[nodeToDisconnect][i];
    }
    return *this;
}



const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

const sicknessStatus Graph::getNodeStatus(int i) const {
    nodesStatuses[i];
}

std::vector<int> Graph::getSickNodes() const {
    std::vector<int> toReturn;
    for (int i = 0; i < size; ++i) {
        if(nodesStatuses[i]==Sick)
            toReturn.push_back(i);
    }
    return std::vector<int>();
}
