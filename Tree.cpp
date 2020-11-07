//
// Created by spl211 on 04/11/2020.
//
#include "Tree.h"


Tree::Tree(): node(0), children({}) {} //default constructor


Tree::Tree(int rootLabel) : node(rootLabel), children({}) {

}

void Tree::addChild(const Tree &child) {
    addChild(child.clone());
}
void Tree::addChild(Tree *child) {
    children.push_back(child);
    delete child;
}





Tree::~Tree() {
    for (auto i : children){
        if (i) delete i;
    }

}

Tree::Tree(const Tree &other) { // copy constructor
      node = other.node;
      children = {};
      for (int i=0; i<other.getChildren().size(); i++){
          addChild(other.children[i]->clone());
      }
}



const Tree &Tree::operator=(const Tree &other) { //copy assignment operator
    if (this != &other){
        for (Tree* child : children){
            if (child) delete child;
        }
        children.clear();
        node = other.node;
        for (Tree* child: other.children){
            Tree* newChild(child);
            addChild(*newChild);
        }
    }
    return *this;
}

Tree::Tree(Tree &&other) { // move constructor
    node = other.node;
    children = other.children; // Do I need to delete something?!

}
// need to check exactly if node and children in the stack
const Tree &Tree::operator=(Tree && other) { // move assignment operator
    for (Tree* child : children){
        if (child) delete child;
    }
    node = other.node;
    children = other.children;
    return *this;
}


// TODO change the argument
void Tree::BFS(const Session &session, const std::vector<std::vector<int>> edges, Tree* parent,std::vector<bool> visited) {

    visited[parent->node] = true;
    for (int i=0; i<edges.size(); i++ ){
        if (edges[parent->node][i] == 1 & !visited[i]){
            Tree* child = createTree(session, i);
            parent->addChild(child);
            BFS(session, edges, child, visited);
        }
    }


}

const std::vector<Tree *> &Tree::getChildren() const{
    return children;
}

const int &Tree::getNode() const {
    return node;
}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree* tree;
    switch (session.getTreeType()) {
        case Root:
            tree = new RootTree(rootLabel);
            return tree;
        case MaxRank:
            tree = new MaxRankTree(rootLabel);
            return tree;
        case Cycle:
            tree = new CycleTree(rootLabel, session.getCycle());
            return tree;
    }
    return nullptr;
}


CycleTree::CycleTree(int rootLabel, int currCycle): Tree(rootLabel), currCycle(currCycle) {

}

int CycleTree::traceTree() {
    int cNode;
    int cycle = currCycle;
    Tree* currTree = this;
    std::vector<Tree*> currChildren = currTree->getChildren();
    while(currChildren.size()>0 & cycle>0){
        currTree = currChildren[0];
        cNode = currTree->getNode();
    }
    return cNode;
}
Tree *CycleTree::clone() const{
    return new CycleTree(*this);
}

CycleTree::CycleTree(const CycleTree &other): Tree(other), currCycle(currCycle) { //copy constructor

}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}


int MaxRankTree::traceTree() {
    int maxRankNode = node;
    int maxRank = children.size();
    std::queue<Tree*> q;
    q.push(this);
    while (!q.empty()){
        if (q.front()->getChildren().size()>maxRank) {
            maxRankNode = q.front()->getNode();
            maxRank = q.front()->getChildren().size();
        }
        for (int i =0; i<q.front()->getChildren().size(); i++){
            q.push(q.front()->getChildren()[i]);
        }
        q.pop();

    }
    return maxRankNode;


}



Tree *MaxRankTree::clone() const{
    return new MaxRankTree(*this);
}



RootTree::RootTree(int rootLabel) : Tree(rootLabel) { //finished

}



int RootTree::traceTree() { // finished
    return node;
}

Tree *RootTree::clone() const{
    return new RootTree(*this);
}

