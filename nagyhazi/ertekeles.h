//#pragma once


#ifndef ERTEELES_H
#define ERTEKELES_H

#include <string>
#include <iostream>
#include <fstream>




void osszesito() {

    std::ifstream fajl("osszesito.txt");
    int ertekeles;
    double atlag;
    fajl >> ertekeles;
    fajl >> atlag;
    std::cout << " From " << ertekeles << " reviews we are rated " << atlag << " stars/5";
    fajl.close();

}

int csillag(double star) {

    std::ifstream fajl("csillag.txt");
    std::string fajlsor;
    while (std::getline(fajl, fajlsor)) {

        int i = 0;
        for (; i < star - 1; i++) std::cout << fajlsor;
        for (double j = 0; j <= (star - i); j += 0.1) std::cout << fajlsor[1 + 10 * j];
        std::cout << "\n";

    }
    std::cout << "\n \n" << star;

    return star;

}



#endif // !ERTEELES_H




