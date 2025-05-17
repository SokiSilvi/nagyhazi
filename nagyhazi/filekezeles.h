//#pragma once

#ifndef FILEKEZELES_H
#define FILEKEZELES_H

#include "ertekeles.h" 
#include <string>
#include <fstream>


void fajlkiolvas(std::string fajlnev) {

    std::fstream fajl(fajlnev);
    std::string fajlsor;
    while (std::getline(fajl, fajlsor)) std::cout << fajlsor << "\n";
    fajl.close();

}

int valaszto(int elsovalasz, int maxvalasz, int jelenlegi, const char* fajlnev, int ertekeles) {

    std::ifstream fajl(fajlnev);
    std::string fajlsor;
    int sor = 0;
    if (jelenlegi > maxvalasz) jelenlegi = 0;
    if (jelenlegi < 0) jelenlegi = maxvalasz;
    jelenlegi += elsovalasz;
    while (std::getline(fajl, fajlsor)) {

        std::cout << fajlsor;
        if (sor == jelenlegi) std::cout << "  <--";
        if (jelenlegi == ertekeles + elsovalasz && sor == ertekeles + elsovalasz) osszesito();
        std::cout << "\n";
        sor++;

    }
    fajl.close();

    return jelenlegi - elsovalasz;

}

#endif // !FILEKEZELES_H


