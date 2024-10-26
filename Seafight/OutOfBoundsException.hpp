#ifndef ATTACK_OT_OF_BOUNDS_HPP
#define ATTACK_OT_OF_BOUNDS_HPP

#include <exception>
#include <string>
class OutOfBoundsException : public std::exception {
private:
	std::string message;

public:
	OutOfBoundsException();
	virtual const char* what() const noexcept override;
};

#endif