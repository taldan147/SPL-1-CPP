//
// Created by spl211 on 04/11/2020.
//
#include "../include/Tree.h"

Tree::Tree(int rootLabel) : node(rootLabel), children({}) {}

void Tree::addChild(const Tree &child) {
    addChild(child.clone());
}

void Tree::addChild(Tree *child) {
    children.push_back(child);
}

Tree::~Tree() {
    clearChildren();
}

Tree::Tree(const Tree &other) : node(other.node), children({}) { // copy constructor
    for (int i = 0; i < (int) other.getChildren().size(); i++) {
        addChild(other.children[i]->clone());
    }
}

const Tree &Tree::operator=(const Tree &other) { //copy assignment operator
    if (this != &other) {
        clearChildren();
        children.clear();
        node = other.node;
        for (Tree *child: other.children) {
//            Tree *newChild(child);
            addChild(child);
        }
    }
    return *this;
}

Tree::Tree(Tree &&other) : node(other.node), children(other.children) { // move constructor
    // Do I need to delete something?!
}

// need to check exactly if node and children in the stack
const Tree &Tree::operator=(Tree &&other) { // move assignment operator
    if (this != &other){
        clearChildren();
        children.clear();
        node = other.node;
        children = other.children;
    }
    return *this;
}


void Tree::BFS(const Session &session) {
    std::vector<std::vector<int>> edges = session.getGraph().getEdges();
    int size=(int)edges.size();
    std::vector<bool> visited(edges.size(), false);
    std::queue<Tree *> q;
    Tree *currTree;
    q.push(this);
    visited[node] = true;
    while (!q.empty()) {
        currTree = q.front();
        q.pop();
        for (int i = 0; i < size; i++) {
            if (edges[currTree->getNode()][i] == 1 && !visited[i]) {
                visited[i] = true;
                Tree *newChild = createTree(session, i);
                currTree->addChild(newChild);
                q.push(newChild);
            }
        }
    }
}

const std::vector<Tree *> &Tree::getChildren() const {
    return children;
}

const int &Tree::getNode() const {
    return node;
}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree *tree;
    switch (session.getTreeType()) {
        case Root:
            tree = new RootTree(rootLabel);
            return tree;
        case MaxRank:
            tree = new MaxRankTree(rootLabel);
            return tree;
        case Cycle:
            tree = new CycleTree(rootLabel, session.getCycleNum());
            return tree;
    }
    return nullptr;
}

void Tree::clearChildren() { // delete recursively the Tree
    int size = (int) children.size();
    for (int i = 0; i < size; i++) {
        delete children[i];
        children[i] = nullptr;
    }
}

CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {}

int CycleTree::traceTree() {
    int cNode=-1;
    int cycle = currCycle;
    Tree *currTree = this;
    std::vector<Tree *> currChildren = currTree->getChildren();
    while (cycle > 0 && !currChildren.empty()) {
        currTree = currChildren[0];
        currChildren=currTree->getChildren();
        cNode = currTree->getNode();
        cycle--;
    }
    if (cNode == -1) {
        cNode = node;
    }
    return cNode;
}

Tree *CycleTree::clone() const {
    return new CycleTree(*this);
}

// can we delete this copy constructor??
CycleTree::CycleTree(const CycleTree &other) : Tree(other), currCycle(other.currCycle) {}//copy constructor

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}

int MaxRankTree::traceTree() {
    int maxRankNode = node;
    int maxRank = children.size();
    std::queue<Tree *> q;
    q.push(this);
    while (!q.empty()) {
        if ((int) q.front()->getChildren().size() > maxRank) {
            maxRankNode = q.front()->getNode();
            maxRank = q.front()->getChildren().size();
        }
        for (int i = 0; i < (int) q.front()->getChildren().size(); i++) {
            q.push(q.front()->getChildren()[i]);
        }
        q.pop();
    }
    return maxRankNode;
}

Tree *MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {} //finished

int RootTree::traceTree() { // finished
    return node;
}

Tree *RootTree::clone() const {
    return new RootTree(*this);
}

