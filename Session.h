#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"
#include "Agent.h"
#include "json.hpp"

class Agent;



enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);

    Session(const std::queue<int> &infectedQueue);

    void simulate();
    void addAgent(const Agent& agent);
    void addAgent(Agent* agent);
    void setGraph(const Graph& graph);
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    const Graph & getGraph() const;
    const int & getCycleNum() const;

private:
    Graph g;
    int cycleNum;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectedQueue;
};

class JsonReader {

private:
    nlohmann::json j_;

public:
    JsonReader(const std::string &path);
    nlohmann::json& getJSON();
    Graph getGraph();
    TreeType getType() const;
    std::vector<Agent*> getAgents() const;
};

#endif
