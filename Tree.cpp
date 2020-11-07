//
// Created by spl211 on 04/11/2020.
//
#include "Tree.h"


Tree::Tree(): node(0), children({}) {} //default constructor


Tree::Tree(int rootLabel) : node(rootLabel), children({}) {

}

void Tree::addChild(const Tree &child) {

}
void Tree::addChild(Tree *child) {
    children.push_back(child);
    delete child;
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



Tree::~Tree() {
    for (auto i : children){
        if (i) delete i;
    }

}

Tree::Tree(const Tree &other) { // copy constructor
    node = other.node;
    children = {};
    for (int i=0; i<other.children.size(); i++){
        //Tree* newChild = other.children[i];
        Tree* newChild = other.children[i]->clone();
        addChild(*newChild);
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
Tree *CycleTree::clone() {
    Tree* newTree = new CycleTree(this->node, this->currCycle);
    for (int i=0; i<this->children.size(); i++){
        Tree* copy = this->children[i]->clone();
        newTree->addChild(*copy);
    }
    return newTree;
}

CycleTree::CycleTree(const CycleTree &other): Tree(other), currCycle(currCycle) {

}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

int MaxRankTree::traceTree() {
    return 0;
}

Tree *MaxRankTree::clone() {
    Tree* newTree = new MaxRankTree(this->node);
    for (int i=0; i<this->children.size(); i++){
        Tree* copy = this->children[i]->clone();
        newTree->addChild(*copy);
    }
    return newTree;

}

MaxRankTree::MaxRankTree(MaxRankTree &other): Tree(other) { // copy constructor M

}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) { //finished

}

int RootTree::traceTree() { // finished
    return node;
}

Tree *RootTree::clone() {
    Tree* newTree = new MaxRankTree(this->node);
    for (int i=0; i<this->children.size(); i++){
        Tree* copy = this->children[i]->clone();
        newTree->addChild(*copy);
    }
    return newTree;
}

RootTree::RootTree(RootTree &other):Tree(other) { // copy constructor RootTree

};