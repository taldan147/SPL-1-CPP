#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"
#include "JsonReader.h"
#include "Agent.h"

class Agent;



enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);
    void simulate();
    void addAgent(const Agent& agent);
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
    std::vector<int> infectedQueue;
    Graph createGraph(nlohmann::json &json);
};

#endif
