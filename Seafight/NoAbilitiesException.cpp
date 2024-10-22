#include "NoAbilitiesException.hpp"

NoAbilitiesException::NoAbilitiesException() {
    message = "No abilities available";
}

const char* NoAbilitiesException::what() const noexcept {
    return message.c_str();
}
