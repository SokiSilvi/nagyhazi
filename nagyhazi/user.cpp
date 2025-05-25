#include "memtrace.h"
#include "User.h"
#include "econio.h"
#include "mindenesheader.h"



Mezo* Man::lep(Mezo* tabla, int width, int length, User& masik, bool& gameover) {

    std::string coor;
    HelperFunctions h;
    bool lepett = false;
    while (not(lepett)) {

        std::cin >> coor;

        if (coor == "F11") {
            bool really = h.savechoice(*this, masik);
            if (really) {

                bool save = h.bipolar("returnno.txt", "returnyes.txt");
                if (save) h.tablament("nemkesz.txt", tabla, width, length, masik, *this);
                gameover = true;

            }
            lepett = true;
            break;
        }

        //std::cout << "\n \n A beirt koordinata " << coor << "volt"; 
        for (int i = 0; i < width * length; i++) {

            //std::cout << "\n a kovetkezo vizsgalt koordinata a " << tabla[i].getid() << "lesz ";
            if (tabla[i].getid() == coor && tabla[i].getfreem()) { tabla[i].stoned(); lepett = true; break; }

        }

    }
    return tabla;

}



Mezo* Cat::lep(Mezo* tabla, int width, int length, User& masik, bool& gameover) {

    bool lepett = false;
    HelperFunctions h;
    h.fajlkiolvas("controlcat.txt");
    Mezo next;
    econio_rawmode();
    while (not(lepett)) {

        int key = econio_getch();
        switch (key)
        {
        case(KEY_LEFT): { next = h.keresszomszed(tabla, this->where, 0, -1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_RIGHT): { next = h.keresszomszed(tabla, this->where, 0, 1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_UP): { next = h.keresszomszed(tabla, this->where, -1, 0, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_DOWN): { next = h.keresszomszed(tabla, this->where, 1, 0, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLDOWN): { next = h.keresszomszed(tabla, this->where, 1, 1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLUP): { next = h.keresszomszed(tabla, this->where, -1, -1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLLEFT): { next = h.keresszomszed(tabla, this->where, 1, -1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case((KEY_CTRLRIGHT)): { next = h.keresszomszed(tabla, this->where, -1, 1, length, width); lepett = h.catstepcorrect(next); tabla = h.tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLDELETE): {

            bool really = h.savechoice(*this, masik);
            if (really) {

                lepett = true;
                bool save = h.bipolar("returnno.txt", "returnyes.txt");
                if (save) h.tablament("nemkesz.txt", tabla, width, length, *this, masik);
                gameover = true;

            }
            break;

        }
        default:
            break;
        }


    }
    econio_normalmode();
    return tabla;

}
