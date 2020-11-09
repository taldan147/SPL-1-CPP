//
// Created by spl211 on 04/11/2020.
//

#include <fstream>
#include "Session.h"

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
    std::string tree=j_["tree"];
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


