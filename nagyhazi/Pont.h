#pragma once
#include "memtrace.h"
#include <iostream>

class Pont {

    int x, y;

public:

    Pont(int x, int y) : x(x), y(y) {}
    void get() { std::cout << x << y; }
    int getx() { return x; }
    int gety() { return y; }

};