#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"
#include "JsonReader.h"

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
    int getCycleNum();
    
private:
    Graph g;
    TreeType treeType;
    int cycleNum;
    std::vector<Agent*> agents;
    std::vector<std::vector<int>> createGraph(nlohmann::json &json);
};

#endif
