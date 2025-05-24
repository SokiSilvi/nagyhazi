#include "core.h"
#include "econio.cpp"

void BeolvasottTabla::prnt() {

    std::cout << "The cat was " << cica.getname() << "\n" << "The man was " << man.getname() << "\n\n";
    tablarajzol(tabla, width, length, cica);

}Mezo* Man::lep(Mezo* tabla, int width, int length, User& masik, bool& gameover) {

    std::string coor;
    bool lepett = false;
    while (not(lepett)) {

        std::cin >> coor;

        if (coor == "F11") {
            bool really = savechoice(*this, masik);
            if (really) {

                bool save = bipolar("returnno.txt", "returnyes.txt");
                if (save) tablament("nemkesz.txt", tabla, width, length, masik, *this);
                gameover = true;

            }
            lepett = true;
            break;
        }

        //std::cout << "\n \n A beirt koordinata " << coor << "volt"; 
        for (int i = 0; i < width * length; i++) {

            //std::cout << "\n a kovetkezo vizsgalt koordinata a " << tabla[i].getid() << "lesz ";
            if (tabla[i].getid() == coor && tabla[i].getfree()) { tabla[i].stoned(); lepett = true; break; }

        }

    }
    return tabla;

}

Mezo* Cat::lep(Mezo* tabla, int width, int length, User& masik, bool& gameover) {

    bool lepett = false;
    fajlkiolvas("controlcat.txt");
    Mezo next;
    econio_rawmode();
    while (not(lepett)) {

        int key = econio_getch();
        switch (key)
        {
        case(KEY_LEFT): { next = keresszomszed(tabla, this->where, 0, -1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_RIGHT): { next = keresszomszed(tabla, this->where, 0, 1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_UP): { next = keresszomszed(tabla, this->where, -1, 0, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_DOWN): { next = keresszomszed(tabla, this->where, 1, 0, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLDOWN): { next = keresszomszed(tabla, this->where, 1, 1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLUP): { next = keresszomszed(tabla, this->where, -1, -1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLLEFT): { next = keresszomszed(tabla, this->where, 1, -1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case((KEY_CTRLRIGHT)): { next = keresszomszed(tabla, this->where, -1, 1, length, width); lepett = catstepcorrect(next); tabla = tableuncat(tabla, width, length, this->where, next); if (lepett) where = next; break; }
        case(KEY_CTRLDELETE): {

            bool really = savechoice(*this, masik);
            if (really) {

                lepett = true;
                bool save = bipolar("returnno.txt", "returnyes.txt");
                if (save) tablament("nemkesz.txt", tabla, width, length, *this, masik);
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