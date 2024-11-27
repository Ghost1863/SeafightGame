#ifndef ABILITY_COORDS_REQUIRED_EXCEPTION
#define ABILITY_COORDS_REQUIRED_EXCEPTION
#include <exception>
#include <string>

class AbilityCoordsRequiredException : public std::exception {
private:
    std::string message;

public:
    AbilityCoordsRequiredException();
    virtual const char* what() const noexcept override;
};
#endif