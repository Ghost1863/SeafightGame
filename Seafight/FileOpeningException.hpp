#ifndef FILE_OPENING_EXCEPTION_HPP
#define FILE_OPENING_EXCEPTION_HPP

#include <exception>
#include <string>

class FileOpeningException : public std::exception {
private:
    std::string message;

public:
    FileOpeningException();
    virtual const char* what() const noexcept override;
};

#endif