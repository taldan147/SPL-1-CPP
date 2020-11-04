//
// Created by spl211 on 04/11/2020.
//

#include "JsonReader.h"

JsonReader::JsonReader(const std::string &path) {
    std::string textRead;
    std::string jsonString="";
    std::ifstream MyReadFile(path);

    while (getline (MyReadFile, textRead)) {
        jsonString+=textRead;
    }

    MyReadFile.close();

    j_=nlohmann::json::parse(jsonString);
}

nlohmann::json& JsonReader::getJSON() {
    return j_;
}
