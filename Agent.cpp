//
// Created by spl211 on 09/11/2020.
//

#include "Agent.h"

Agent::Agent() {

}

ContactTracer::ContactTracer() {

}

void ContactTracer::act(Session &session) {

}

Agent *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

Virus::Virus(int node) : nodeInd(node) {

}

void Virus::act(Session &session) {

}

Agent *Virus::clone() const {
    return new Virus(*this);
}
