#ifndef ABILITY_RESULT
#define ABILITY_RESULT

#include <string>

class AbilityResult {
public:
    virtual std::string getMessage() = 0;
    virtual ~AbilityResult() {};
};

class ShipDestroyedResult : public AbilityResult {
private:
    std::string message;

public:
    ShipDestroyedResult() : message("Ship has been destroyed.") {};
    std::string getMessage() override {
        return message;
    }
};


class SegmentDetectedResult : public AbilityResult {

private:
    std::string message;

public:
    SegmentDetectedResult() : message("\033[0;32;40mSegment has been detected.\033[0m") {}
    std::string getMessage() override {
        return message;
    }
};


class SegmentNotFoundResult : public AbilityResult {
private:
    std::string message;

public:
    SegmentNotFoundResult() : message("\033[0;31;40mSegment(s) was(were) not found.\033[0m") {}
    std::string getMessage() override {
        return message;
    }
};

class ShipNotDestroyedResult : public AbilityResult {
private:
    std::string message;

public:
    ShipNotDestroyedResult() : message("Ship was not destroyed.") {}
    std::string getMessage() override {
        return message;
    }
};

class DamageIncreasedResult : public AbilityResult {
private:
    std::string message;

public:
    DamageIncreasedResult() : message("\033[0;32;40mDamage increased (now 2).\033[0m") {}
    std::string getMessage() override {
        return message;
    }
};

#endif