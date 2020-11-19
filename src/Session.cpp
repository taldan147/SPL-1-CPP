#include "../include/Session.h"
//
// Created by spl211 on 04/11/2020.
//
Session::Session(const std::string &path) : g({}), cycleNum(0),treeType(Root), agents({}),infectedQueue()   {
    JsonReader jsonReader(path);
    g = jsonReader.getGraph();
    treeType = jsonReader.getType();
    jsonReader.getAgents(*this);
}

//copy cunstructor
Session::Session(const Session &other) : g(other.getGraph()), cycleNum(other.cycleNum), treeType(other.getTreeType()), agents({}),
                                         infectedQueue(other.getInfectedQueue()) {
    int agentSize = (int) other.agents.size();
    for (int i = 0; i < agentSize; i++) {
        addAgent(*other.agents[i]->clone());
    }
}

const Session &Session::operator=(const Session &other) { // copy assignment operator
    if (this != &other){
        clearAgents();

        g = other.g;
        cycleNum = other.cycleNum;
        treeType = other.treeType;
        infectedQueue = other.infectedQueue;
        for (Agent* agent : other.agents){
            addAgent(agent);
        }
    }
    return *this;
}

Session::Session(Session &&other) :g(other.g), cycleNum(other.cycleNum), treeType(other.treeType), agents(other.agents), infectedQueue(other.infectedQueue) { //move constructors
    clearQueue(other.infectedQueue);
    other.agents.clear();
}

const Session &Session::operator=(Session &&other) { //move assignment operator
    if (this != &other){
        clearAgents();
        g = other.g;
        cycleNum = other.cycleNum;
        treeType = other.treeType;
        infectedQueue = other.infectedQueue;
        clearQueue(other.infectedQueue);
        agents = other.agents;
        other.agents.clear();

    }
    return *this;
}

void Session::simulate() {
    do {
        int currAgentSize = (int) agents.size();
        for (int i = 0; i < currAgentSize; i++) {
            agents[i]->act(*this);
        }
        cycleNum++;
    } while (!g.isAllFullyInfected());

    JsonWriter::writeJson(g, g.getSickNodes());
}

void Session::addAgent(const Agent &agent) {
    Agent *newAgent = agent.clone();
    addAgent(newAgent);
}

void Session::addAgent(Agent *agent) {
    agents.push_back(agent);
}

void Session::setGraph(const Graph &graph) {
    g = graph;
}

void Session::enqueueInfected(int infectedNode) {
    infectedQueue.push(infectedNode);
}

int Session::dequeueInfected() {
    int first = infectedQueue.front();
    infectedQueue.pop();
    return first;
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

void Session::infectNode(int nodeToInfect) {
    g.infectNode(nodeToInfect);
}

void Session::spreadVirus(int oldNode) {
    int nodeToInfect = g.findNodeToInfect(oldNode);
    if (nodeToInfect != -1){
        Agent* newVirus = new Virus(nodeToInfect);
        addAgent(newVirus);
        infectNode(nodeToInfect);
    }
}

const bool Session::isInfectedQueueEmpty() const {
    return infectedQueue.empty();
}

void Session::disconnectNode(int node) {
    Graph &tmp = g.disconnectNode(node);
    setGraph(tmp);
}

sicknessStatus Session::getNodeStatus(int node) const {
    return g.getNodeStatus(node);
}

Session::~Session() {
    clearAgents();
}

const std::queue<int> &Session::getInfectedQueue() const {
    return infectedQueue;
}

void Session::clearAgents() {
    for (Agent *agent : agents) {
        if (agent) delete agent;
    }
    agents.clear();
}

void Session::sickenNode(int sickNode) {
    g.sickenNode(sickNode);
    enqueueInfected(sickNode);
}

void Session::clearQueue(std::queue<int> &q) {
    while (!q.empty()){
        q.pop();
    }
}








