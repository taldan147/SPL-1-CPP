#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "Session.h"
#include <queue>
class Session;

class Tree{
public:

    Tree(int rootLabel); // constructor
    Tree(const Tree &other); // copy constructor
    const Tree& operator=(const Tree& other); // copy assignment operator
    Tree(Tree &&other); // move constructor
    const Tree& operator=(Tree&& other); // move assignment operator
    const int & getNode() const;
    const std::vector<Tree*> & getChildren() const;
    void addChild(const Tree& child);
    void addChild(Tree* child);
    void BFS(const Session &session);
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree* clone() const=0;
    void clearChildren();
    virtual ~Tree();
    const int & getRootLabel() const;

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
//    CycleTree(const CycleTree& other);
    virtual int traceTree();
    virtual Tree* clone() const;
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

#endif
