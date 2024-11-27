#pragma once
#include <iostream>

struct Coordinates {
    int x;
    int y;

    bool operator==(const Coordinates& other) const {
        return x == other.x && y == other.y;
    }
};
