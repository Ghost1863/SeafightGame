#include "AttackOutOfBoundsException.hpp"

AttackOutOfBoundsException::AttackOutOfBoundsException() {
	message = "Attack out of bounds";
}

const char* AttackOutOfBoundsException::what() const noexcept {
	return message.c_str();
}
