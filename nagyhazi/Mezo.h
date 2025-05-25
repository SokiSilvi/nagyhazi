#pragma once
#include "memtrace.h"
#include <iostream>
#include <string>
#include "Pont.h"


class Mezo : public Pont {

    std::string id;
    bool stone, real, side, freem;

public:

    Mezo(int x, int y, std::string id, bool stone, bool real, bool side, bool freem) : Pont(x, y), id(id), stone(stone), real(real), side(side), freem(freem) {}
    Mezo() : Pont(-1, -1), id("NA"), stone(0), real(0), side(1), freem(0) {}
    void stoned() { this->stone = true; this->freem = false; }
    void catted() { this->freem = false; }
    void setfreem() { this->freem = true; }
    void sides() { this->side = true; }
    std::string getid() { return id; }
    bool getfreem() { return freem; }
    bool getside() { return side; }
    bool getstone() { return stone; }

    std::string drawline1() {
        if (not real) return "   ";
        else {
            if (not stone) return "|  ";
            else return "|||";
        }
    }
    std::string drawline2() {
        if (not real) return "   ";
        else {
            if (not stone) return "|__";
            else return "|||";
        }
    }

    bool operator==(Mezo masik) { return masik.getid() == this->getid(); }

};