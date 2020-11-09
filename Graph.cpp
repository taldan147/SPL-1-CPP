//
// Created by spl211 on 04/11/2020.
//
#include "Graph.h"
#include "iostream"

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix){
    for (int i = 0; i <edges.size() ; ++i) {
        for (int j = 0; j < edges[i].size(); ++j) {
            std::cout << edges[i][j];
        }
        std::cout<<"\n";
    }
}

Graph::Graph(std::nullptr_t):edges(){

}

void Graph::infectNode(int nodeInd) {

}

bool Graph::isInfected(int nodeInd) {
    return false;
}
