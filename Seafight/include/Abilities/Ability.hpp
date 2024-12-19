#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "UserParams.hpp"
#include "AbilityResult.hpp"
#include<chrono>
#include<random>

//enum class AbilityResult { ShipDestroyed, SegmentDetected,SegmentNotFound,ShipNotDestroyed };

class Ability {
public:
	virtual std::unique_ptr<AbilityResult> useAbility() = 0;
	virtual ~Ability() {}
};

#endif 
	