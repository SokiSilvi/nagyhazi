// nagyhazi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "memtrace.h"
//#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "mindenesheader.h"
#include "econio.h" 
//#include "Tests.hpp"

#include "gtest_lite.h"
#include <sstream>


int main()
{

    GTINIT(std::cin);

    // Teszt az alap�rtelmezett Mezo konstruktorhoz
    TEST(Mezo, DefaultConstructor) {
        Mezo mezo;
        EXPECT_EQ(-1, mezo.getx()) << "Hib�s x koordin�ta az alap�rtelmezett konstruktorban";
        EXPECT_EQ(-1, mezo.gety()) << "Hib�s y koordin�ta az alap�rtelmezett konstruktorban";
        EXPECT_STREQ("NA", mezo.getid().c_str()) << "Hib�s ID az alap�rtelmezett konstruktorban";
        EXPECT_FALSE(mezo.getstone()) << "A stone �rt�k nem false alap�rtelmezetten";
        EXPECT_FALSE(mezo.getfreem()) << "A freem �rt�k nem false alap�rtelmezetten";
        EXPECT_TRUE(mezo.getside()) << "A side �rt�k nem true alap�rtelmezetten";
    } END

        // Teszt a Mezo konstruktorhoz param�terekkel
        TEST(Mezo, ParameterizedConstructor) {
        Mezo mezo(1, 2, "A2", true, true, false, true);
        EXPECT_EQ(1, mezo.getx()) << "Hib�s x koordin�ta";
        EXPECT_EQ(2, mezo.gety()) << "Hib�s y koordin�ta";
        EXPECT_STREQ("A2", mezo.getid().c_str()) << "Hib�s ID";
        EXPECT_TRUE(mezo.getstone()) << "A stone �rt�k nem true";
        EXPECT_TRUE(mezo.getfreem()) << "A freem �rt�k nem true";
        EXPECT_FALSE(mezo.getside()) << "A side �rt�k nem false";
    } END

        // Teszt a Mezo �llapotv�ltoztat� f�ggv�nyekhez
        TEST(Mezo, StateChanges) {
        Mezo mezo(0, 0, "A0", false, true, false, true);
        mezo.stoned();
        EXPECT_TRUE(mezo.getstone()) << "A stoned() nem �ll�totta be a stone-t true-ra";
        EXPECT_FALSE(mezo.getfreem()) << "A stoned() nem �ll�totta a freem-et false-ra";

        mezo.setfreem();
        EXPECT_TRUE(mezo.getfreem()) << "A setfreem() nem �ll�totta a freem-et true-ra";

        mezo.catted();
        EXPECT_FALSE(mezo.getfreem()) << "A catted() nem �ll�totta a freem-et false-ra";

        mezo.sides();
        EXPECT_TRUE(mezo.getside()) << "A sides() nem �ll�totta a side-ot true-ra";
    } END

        // Teszt a HelperFunctions::keresszomszed f�ggv�nyhez
        TEST(HelperFunctions, Keresszomszed) {
        HelperFunctions h;
        Mezo* tabla = new Mezo[9];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::string id = std::string(1, 'A' + i) + std::to_string(j);
                tabla[i * 3 + j] = Mezo(i, j, id, false, true, false, true);
            }
        }
        Mezo center = tabla[4]; // B1 (1,1)
        Mezo szomszed = h.keresszomszed(tabla, center, 0, 1, 3, 3); // Jobbra: B2
        EXPECT_STREQ("B2", szomszed.getid().c_str()) << "Hib�s szomsz�d jobbra";
        szomszed = h.keresszomszed(tabla, center, -1, 0, 3, 3); // Fel: A1
        EXPECT_STREQ("A1", szomszed.getid().c_str()) << "Hib�s szomsz�d felfel�";
        szomszed = h.keresszomszed(tabla, center, 0, -1, 3, 3); // Balra: B0
        EXPECT_STREQ("B0", szomszed.getid().c_str()) << "Hib�s szomsz�d balra";
        szomszed = h.keresszomszed(tabla, center, 1, 0, 3, 3); // Lefel�: C1
        EXPECT_STREQ("C1", szomszed.getid().c_str()) << "Hib�s szomsz�d lefel�";
        delete[] tabla;
    } ENDM

        // Teszt a HelperFunctions::catstepcorrect f�ggv�nyhez
        TEST(HelperFunctions, CatStepCorrect) {
        HelperFunctions h;
        Mezo valid(1, 1, "B1", false, true, false, true);
        Mezo invalid(-1, -1, "NA", false, false, false, false);
        EXPECT_TRUE(h.catstepcorrect(valid)) << "�rv�nyes l�p�st hib�snak �t�lt";
        EXPECT_FALSE(h.catstepcorrect(invalid)) << "�rv�nytelen l�p�st �rv�nyesnek �t�lt";
    } END


        /*

        // Teszt a HelperFunctions::tableuncat f�ggv�nyhez
        TEST(HelperFunctions, TableUncat) {
        HelperFunctions h;
        Mezo* tabla = new Mezo[9];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::string id = std::string(1, 'A' + i) + std::to_string(j);
                tabla[i * 3 + j] = Mezo(i, j, id, false, true, false, true);
            }
        }
        Mezo now = tabla[4]; // B1
        now.catted();
        Mezo next = tabla[5]; // B2
        tabla = h.tableuncat(tabla, 3, 3, now, next);
        EXPECT_FALSE(tabla[4].getfreem()) << "A r�gi poz�ci� nem lett felszabad�tva";
        EXPECT_FALSE(tabla[5].getfreem()) << "Az �j poz�ci� nem lett elfoglalva";
        delete[] tabla;
    } ENDM */

        // Teszt a HelperFunctions::cicanemlephet f�ggv�nyhez

        /*
        TEST(HelperFunctions, CicaNemLephet) {
        HelperFunctions h;
        Mezo* tabla = new Mezo[9];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::string id = std::string(1, 'A' + i) + std::to_string(j);
                tabla[i * 3 + j] = Mezo(i, j, id, false, true, false, true);
            }
        }
        Cat cat("test@example.com", "TestCat", "pass123", tabla[4]); // B1
        EXPECT_FALSE(h.cicanemlephet(cat, tabla, 3, 3)) << "A macska l�phet, m�gis nem l�phetk�nt van jelezve";
        for (int i = 0; i < 9; i++) {
            if (i != 4) tabla[i].stoned();
        }
        EXPECT_TRUE(h.cicanemlephet(cat, tabla, 3, 3)) << "A macska nem l�phet, m�gis l�phetk�nt van jelezve";
        delete[] tabla;
    } END */

        // Teszt a BeolvasottTabla oszt�lyhoz

        /*
        TEST(BeolvasottTabla, Constructor) {
        Mezo* tabla = new Mezo[9];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::string id = std::string(1, 'A' + i) + std::to_string(j);
                tabla[i * 3 + j] = Mezo(i, j, id, false, true, false, true);
            }
        }
        User cat_user("cat@example.com", "TestCat", "pass123");
        User man_user("man@example.com", "TestMan", "pass123");
        Cat cat(cat_user, tabla[4]);
        Man man(man_user);
        BeolvasottTabla bt(tabla, cat, man, 3, 3);
        EXPECT_STREQ("TestCat", bt.getcica().getname().c_str()) << "Hib�s macska n�v";
        EXPECT_STREQ("TestMan", bt.getman().getname().c_str()) << "Hib�s ember n�v";
        delete[] tabla;
    } ENDM */

        GTEND(std::cout);


    HelperFunctions h;
    //SetConsoleOutputCP(CP_UTF8);
    //ertekel(); 
    //animate();
    //bejelentkezes();

    h.fajlkiolvas("line-arts.txt");
    return 0;
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
    return 0;
    
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