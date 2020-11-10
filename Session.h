#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"
#include "Agent.h"
#include "json.hpp"

class Agent;


enum TreeType {
    Cycle,
    MaxRank,
    Root
};


class Session {
public:
    Session(const std::string &path);

    Session(const Session &other);

    //Session(const std::queue<int> &infectedQueue);

    void simulate();

    void addAgent(const Agent &agent);

    void addAgent(Agent *agent);

    void setGraph(const Graph &graph);

    void enqueueInfected(int);

    int dequeueInfected();

    TreeType getTreeType() const;

    const Graph &getGraph() const;

    const int &getCycleNum() const;

    const std::queue<int> &getInfectedQueue() const;

    sicknessStatus getNodeStatus(int) const;

    void infectNode(int nodeToInfect);

    void spreadVirus(int oldNode);

    const bool isInfectedQueueEmpty() const;

    void disconnectNode(int node);
    ~Session();

    void sickenNode(int sickNode);

private:
    Graph g;
    int cycleNum;
    TreeType treeType;
    std::vector<Agent *> agents;
    std::queue<int> infectedQueue;

};

class JsonReader {


private:

    nlohmann::json j_;
public:

    JsonReader(const std::string &path);

    nlohmann::json &getJSON();

    Graph getGraph();

    TreeType getType() const;

    void getAgents(Session &sess) const;
};

class JsonWriter {
public:
    static void writeJson(Graph g,const std::vector<int>&);
};

#endif
