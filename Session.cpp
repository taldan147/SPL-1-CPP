#include "Session.h"
//
// Created by spl211 on 04/11/2020.
//
 Session::Session(const std::string &path):g(nullptr){
    JsonReader jsonReader(path);
    g = createGraph(jsonReader.getJSON());
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
    return ;
}

const Graph & Session::getGraph() const {
    return g;
}

const int &Session::getCycle() const {
    return cycle;
}

std::vector<std::vector<int>> Session::createGraph(nlohmann::json& json) {
    std::vector<std::vector<int>> graph=json["graph"];
    return graph;
}

int Session::getCycleNum() {
    return 0;
}
