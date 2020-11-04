//
// Created by spl211 on 04/11/2020.
//
#include "Tree.h"


Tree::Tree(int rootLabel) {

}

void Tree::addChild(const Tree &child) {

}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    return nullptr;
}

int Tree::getNode() {
    return node;
}

Tree::~Tree() {
    delete node

}

CycleTree::CycleTree(int rootLabel, int currCycle) {

}

int CycleTree::traceTree() {
    return 0;
}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

int MaxRankTree::traceTree() {
    return 0;
}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}

int RootTree::traceTree() {
    return getNode();
}
