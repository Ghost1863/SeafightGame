#include "AbilityCoordsRequiredException.hpp"

AbilityCoordsRequiredException::AbilityCoordsRequiredException() {
    message = "No coordinates provided to ability";
}

const char* AbilityCoordsRequiredException::what() const noexcept {
    return message.c_str();
}
