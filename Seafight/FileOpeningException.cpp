#include "FileOpeningException.hpp"

FileOpeningException::FileOpeningException() {
    message = "Unable to open file";
}

const char* FileOpeningException::what() const noexcept {
    return message.c_str();
}
