#ifndef WRAPPER_H
#define WRAPPER_H

#include "nlohmann/json.hpp"
#include "FileOpeningException.hpp"
#include "FileWasDamagedException.hpp"
#include <iostream>
#include <fstream>

class FileWrapper {
private:
    mutable std::fstream file;
public:
    FileWrapper(const std::string& filename, std::ios::openmode mode);

    ~FileWrapper();

    void write(nlohmann::json& j);
    void read(nlohmann::json& j);
};

#endif