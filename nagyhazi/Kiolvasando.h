#pragma once
#include "memtrace.h"
#include <string>
#include "Mezo.h"
#include "User.h"




class Kiolvasando {

    int tag;

public:

    Kiolvasando() : tag(1) {}
    virtual void prnt() {}

};


class comment : public Kiolvasando {

    std::string nev;
    double star;
    std::string szoveg;

public:

    comment(std::string nev, double csillag, std::string szoveg) : nev(nev), star(csillag), szoveg(szoveg) {};
    void prnt();

};


class BeolvasottTabla : public Kiolvasando {

    Mezo* tabla;
    Cat cica;
    Man man;
    int width;
    int length;

public:

    BeolvasottTabla(Mezo* tabla, User cica, User man, int width, int length) : tabla(tabla), cica(cica), man(man), width(width), length(length) {}
    void prnt();
    Cat getcica() { return cica; }
    Man getman() { return man; }

};