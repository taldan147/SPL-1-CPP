#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
enum spread{
    AllInfected,
    PartiallyInfected,
    Clean
};

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);

    Graph(nullptr_t);
    bool isAllFullyInfected() const;
    spread isSick(Graph* g);
    std::vector<Graph*> SplitIntoConnectedComponents();

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    const std::vector<std::vector<int>> & getEdges() const;
private:
    std::vector<std::vector<int>> edges;
};

#endif
