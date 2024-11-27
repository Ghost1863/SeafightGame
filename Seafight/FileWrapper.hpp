#ifndef WRAPPER_H
#define WRAPPER_H

#include "nlohmann/json.hpp"
#include "FileOpeningException.hpp"
#include <iostream>
#include <fstream>

class FileWrapper {
    mutable std::fstream file;
public:
    FileWrapper(const std::string& filename);

    ~FileWrapper();

    void write(nlohmann::json& j);
    void read(nlohmann::json& j);
};

#endif