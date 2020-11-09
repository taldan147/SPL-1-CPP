//
// Created by spl211 on 04/11/2020.
//

#ifndef ASSIGNMENT1_JSONREADER_H
#define ASSIGNMENT1_JSONREADER_H


#include <string>
#include "json.hpp"
#include <fstream>
#include <iostream>


class JsonReader {

private:
    nlohmann::json j_;

public:
    JsonReader(const std::string &path);
    nlohmann::json& getJSON();
};


#endif //ASSIGNMENT1_JSONREADER_H
