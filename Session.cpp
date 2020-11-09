#include "Session.h"
//
// Created by spl211 on 04/11/2020.
//
 Session::Session(const std::string &path):g(nullptr){
    JsonReader jsonReader(path);
    g = jsonReader.getGraph();
    treeType=jsonReader.getType();
}

void Session::simulate() {

}

void Session::addAgent(const Agent &agent) {

}

void Session::setGraph(const Graph &graph) {
        g=graph;
}

void Session::enqueueInfected(int) {

}

int Session::dequeueInfected() {
    return 0;
}

TreeType Session::getTreeType() const {
    return treeType;
}

const Graph & Session::getGraph() const {
    return g;
}

const int &Session::getCycleNum() const {
    return cycleNum;
}


