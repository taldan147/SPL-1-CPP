#include "Session.h"
//
// Created by spl211 on 04/11/2020.
//
 Session::Session(const std::string &path):g(nullptr), cycleNum(0), treeType(Root), agents({}), infectedQueue({}){
    JsonReader jsonReader(path);
    g = createGraph(jsonReader.getJSON());

}

void Session::simulate() {
    while (g.isAllFullyInfected()){
        for (Agent* agent: agents){
            agent->act(*this);
        }
        cycleNum++;
    }
}

void Session::addAgent(const Agent &agent) {
    Agent* newAgent = agent.clone();
    addAgent(newAgent);
}

void Session::addAgent(Agent* agent){
    agents.push_back(agent);
}

void Session::setGraph(const Graph &graph) {
        g=graph;
}

void Session::enqueueInfected(int infectedNode) {
    infectedQueue.push_back(infectedNode);
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

Graph Session::createGraph(nlohmann::json& json) {
    std::vector<std::vector<int>> graph=json["graph"];
    return graph;
}
