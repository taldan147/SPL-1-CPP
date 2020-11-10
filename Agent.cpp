//
// Created by spl211 on 09/11/2020.
//

#include "Agent.h"

Agent::Agent() {

}

Agent::~Agent() {

}

ContactTracer::ContactTracer() : Agent(){

}

void ContactTracer::act(Session &session) {
    if (!session.isInfectedQueueEmpty()) {
        int nodeToTrace = session.dequeueInfected();
        Tree* root = Tree::createTree(session, nodeToTrace);
        root->BFS(session);
        int nodeToDisconnect = root->traceTree();
        session.disconnectNode(nodeToDisconnect);
        //deletes the BFS tree after we disconnect the node
        delete root;
    }

}

Agent *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

Virus::Virus(int node) : Agent(), nodeInd(node) {

}

void Virus::act(Session &session) {
    if (session.getNodeStatus(nodeInd) != Sick)
        session.sickenNode(nodeInd);
    session.spreadVirus(nodeInd);
}

Agent *Virus::clone() const {
    return new Virus(*this);
}
