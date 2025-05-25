#pragma once
#include "memtrace.h"
#include <string>
#include "Mezo.h"
#include "User.h"




class Kiolvasando {

public:

    Kiolvasando() {} 
    virtual void prnt() {}
    virtual ~Kiolvasando() {}

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
    // Constructor
    BeolvasottTabla(Mezo* tabla, User cica, User man, int width, int length)
        : tabla(tabla), cica(cica), man(man), width(width), length(length) {
    }

    // Copy constructor (deep copy)
    BeolvasottTabla(const BeolvasottTabla& other)
        : cica(other.cica), man(other.man), width(other.width), length(other.length) {
        if (other.tabla) {
            tabla = new Mezo[width * length];
            for (int i = 0; i < width * length; ++i)
                tabla[i] = other.tabla[i];
        }
        else {
            tabla = nullptr;
        }
    }

    // Copy assignment operator (deep copy)
    void swap(BeolvasottTabla& other) noexcept {
        std::swap(tabla, other.tabla);
        std::swap(cica, other.cica);
        std::swap(man, other.man);
        std::swap(width, other.width);
        std::swap(length, other.length);
    }

    // Copy assignment operator using copy-and-swap
    BeolvasottTabla& operator=(BeolvasottTabla other) {
        swap(other);
        return *this;
    }

    // Move constructor
    BeolvasottTabla(BeolvasottTabla&& other) noexcept
        : tabla(other.tabla),
        cica(std::move(other.cica)),
        man(std::move(other.man)),
        width(other.width),
        length(other.length) {
        other.tabla = nullptr;
        other.width = 0;
        other.length = 0;
    }

    BeolvasottTabla& operator=(BeolvasottTabla&& other) noexcept {
        if (this != &other) {
            delete[] tabla; // free current resource
            tabla = other.tabla;
            cica = std::move(other.cica);
            man = std::move(other.man);
            width = other.width;
            length = other.length;

            other.tabla = nullptr;
            other.width = 0;
            other.length = 0;
        }
        return *this;
    }

    Mezo* getTable() {
        return tabla;
    }

    // Destructor
    ~BeolvasottTabla() {
        delete[] tabla;
    }

    void prnt();
    Cat getcica() { return cica; }
    Man getman() { return man; }
};
