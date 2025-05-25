#include "memtrace.h"
#include "Kiolvasando.h"
#include "mindenesheader.h"

void BeolvasottTabla::prnt() {
    HelperFunctions h;
    std::cout << "The cat was " << cica.getname() << "\n" << "The man was " << man.getname() << "\n\n";
    h.tablarajzol(tabla, width, length, cica);

}


void comment::prnt() {
    HelperFunctions h;
    for (int i = 0; i < 50; i++) std::cout << "\n";
    for (int i = 0; i < 100; i++) std::cout << "~";
    std::cout << "\n  " << nev << "\n";
    for (size_t i = 0; i < nev.size() + 2; i++) std::cout << "_";
    h.csillag(star, false);
    std::cout << szoveg;
    //fajlkiolvas("commentsection.txt");
    for (int i = 0; i < 100; i++) std::cout << "~";

}