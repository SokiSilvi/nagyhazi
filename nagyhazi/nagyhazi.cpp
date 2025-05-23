// nagyhazi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "mindenesheader.h"
#include "econio.h" 


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //ertekel(); 
    //animate();
    //bejelentkezes();

    fajlkiolvas("line-arts.txt");
    system("pause >nul");
    //std::cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012456789012345678901234567890123456789";
    //User felhasznalo = regisztracio(); 
    //ertekel(); 

    
    //ujjatek();

    while (true)
    {
        int valasztas = arrowfind(2, 6, "menu.txt", 3);

        if (valasztas == 0) ujjatek(); 
        if (valasztas == 1) fajlkiolvas("error.txt");
        if (valasztas == 3) walkcomments();
        if (valasztas == 4) ertekel();
        if (valasztas == 5) usermodosit();
        if (valasztas == 6) animate();  

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
