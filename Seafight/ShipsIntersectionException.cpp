#include "ShipsIntersectionException.hpp"

ShipsIntersectionException::ShipsIntersectionException() {
    message = "Ships are placed too close or out of bounds"; 
}

const char* ShipsIntersectionException::what() const noexcept {
    return message.c_str();
}
