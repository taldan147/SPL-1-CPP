#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

enum sicknessStatus {
    Clean,
    Infected,
    Sick
};

class Graph {
public:
    Graph(std::vector<std::vector<int>> matrix);

    bool isAllFullyInfected() const;

    sicknessStatus isSick(Graph *g);

    void infectNode(int nodeInd);

    bool isInfected(int nodeInd);

    const std::vector<std::vector<int>> &getEdges() const;

    int findNodeToInfect(int node) const;

    Graph &disconnectNode(int nodeToDisconnect);

    const sicknessStatus getNodeStatus(int i) const;

    std::vector<int> getSickNodes() const;


private:
    std::vector<std::vector<int>> edges;
    int size;
    std::vector<sicknessStatus> nodesStatuses;


};

#endif
