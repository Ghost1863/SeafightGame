#include "FileWasDamagedException.hpp"

FileWasDamagedException::FileWasDamagedException() {
    message = "File was damaged (save is invalid)";
}

const char* FileWasDamagedException::what() const noexcept {
    return message.c_str();
}
