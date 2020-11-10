//
// Created by spl211 on 04/11/2020.
//

#include <fstream>
#include "Session.h"
#include <iostream>

JsonReader::JsonReader(const std::string &path) {
    std::string textRead;
    std::string jsonString = "";
    std::ifstream MyReadFile(path);

    while (getline(MyReadFile, textRead)) {
        jsonString += textRead;
    }

    MyReadFile.close();

    j_ = nlohmann::json::parse(jsonString);
}

nlohmann::json &JsonReader::getJSON() {
    return j_;
}

TreeType JsonReader::getType() const {
    std::string tree = j_["tree"];
    switch (tree[0]) {
        case 'M': {
            return MaxRank;
        }
        case 'C': {
            return Cycle;
        }
        case 'R': {
            return Root;
        }
        default: {
            break;
        }
    }
}

Graph JsonReader::getGraph() {
    std::vector<std::vector<int>> matrix = j_["graph"];
    return Graph(matrix);
}

void JsonReader::getAgents(Session& sess) const {
    std::vector<std::pair<std::string, int>> agentList = j_["agents"];
    std::vector<Agent *> toReturn;
    for (std::pair<std::string, int> agent: agentList) {
        if (agent.first.compare("V") == 0) {
            sess.addAgent(new Virus(agent.second));
            sess.infectNode(agent.second);
        }
        else{
            sess.addAgent(new ContactTracer);
        }
    }
}

void JsonWriter::writeJson(Graph g, const std::vector<int>& sickNodes) {
        nlohmann::json output=nlohmann::json{{"graph",g.getEdges()},{"infected",sickNodes}};
    std::ofstream o("./output.json");
    o << output.dump()<<std::endl;
    std::cout<<output.dump();
    o.close();
}


