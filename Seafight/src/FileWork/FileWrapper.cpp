#include "FileWrapper.hpp"

FileWrapper::FileWrapper(const std::string& filename, std::ios::openmode mode) : file(filename,mode) {
    if (!file) {
        throw FileOpeningException();
    };
};

FileWrapper::~FileWrapper() {
    if (file.is_open())
        file.close();
}

void FileWrapper::write(nlohmann::json& j) {
    if (!file.is_open() || !file.good()) {
        throw FileOpeningException();
    }
    file << j.dump(4);
}

void FileWrapper::read(nlohmann::json& j) {
    if (!file.is_open() || !file.good()) {
        throw FileOpeningException();
    }
    file >> j;
}

