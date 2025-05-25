// nagyhazi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "memtrace.h"
//#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "mindenesheader.h"
#include "econio.h" 
#include "Tests.hpp"


int main()
{
    HelperFunctions h;
    //SetConsoleOutputCP(CP_UTF8);
    //ertekel(); 
    //animate();
    //bejelentkezes();

    h.fajlkiolvas("line-arts.txt");
    system("pause >nul");
    //std::cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012456789012345678901234567890123456789";
    //User felhasznalo = regisztracio(); 
    //ertekel(); 

    
    //ujjatek();
    bool go = true;
    while (go)
    {
        int valasztas = h.arrowfind(2, 6, "menu.txt", 3);

        if (valasztas == 0) h.ujjatek();
        if (valasztas == 1) h.fajlkiolvas("error.txt");
        if (valasztas == 2) { h.tablakinez(); }
        if (valasztas == 3) { 
            size_t count = 0; 
            comment** allcomments = h.read_comments(count); 
            h.walkcomments(reinterpret_cast<Kiolvasando**>(allcomments), static_cast<int>(count)); 
        }
        if (valasztas == 4) h.ertekel();
        if (valasztas == 5) h.usermodosit();
        if (valasztas == 6) {
            h.animate();
            go = false;
        }

    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


//random comment