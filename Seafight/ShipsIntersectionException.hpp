#ifndef SHIPS_INTERSECTION_EXCEPTION_HPP
#define SHIPS_INTERSECTION_EXCEPTION_HPP

#include <exception>
#include <string>

class ShipsIntersectionException : public std::exception {
private:
    std::string message;

public:
    ShipsIntersectionException();
    virtual const char* what() const noexcept override;
};

#endif