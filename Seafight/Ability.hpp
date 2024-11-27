#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "UserParams.hpp"
#include<chrono>
#include<random>

enum class AbilityResult { ShipDestroyed, SegmentDetected,SegmentNotFound,ShipNotDestroyed };

class Ability {
public:
	virtual AbilityResult useAbility() = 0;
	virtual ~Ability() {}
};

#endif 
	