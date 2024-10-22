#ifndef ATTACK_OT_OF_BOUNDS_HPP
#define ATTACK_OT_OF_BOUNDS_HPP

#include <exception>
#include <string>
class AttackOutOfBoundsException : public std::exception {
private:
	std::string message;

public:
	AttackOutOfBoundsException();
	virtual const char* what() const noexcept override;
};

#endif