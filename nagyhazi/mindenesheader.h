#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include "econio.h"






class Pont {

    int x, y;

public:

    Pont(int x, int y) : x(x), y(y) {}
    void get() { std::cout << x << y; }
    int getx() { return x; }
    int gety() { return y; }

};

class Mezo : public Pont {

    std::string id;
    bool stone, real, side, free;

public:

    Mezo(int x, int y, std::string id, bool stone, bool real, bool side, bool free) : Pont(x, y), id(id), stone(stone), real(real), side(side), free(free) {}
    Mezo() : Pont(-1, -1), id("NA"), stone(0), real(0), side(1), free(0) {}
    void stoned() { stone = true; free = false; }
    void catted() { free = false; }
    void setfree() { free = true; }
    void side() { side = true; }
    std::string drawline1() {
        if (not real) return "   ";
        else {
            if (not stone) return "|  ";
            else return "|||";
        }
    }
    std::string drawline2() {
        if (not real) return "   ";
        else {
            if (not stone) return "|__";
            else return "|||";
        }
    }
    virtual Mezo& toplefth() { throw "BHPG3H"; }
    virtual Mezo& toprighth() { throw "BHPG3H"; }
    virtual Mezo& toph() { throw "BHPG3H"; }
    virtual Mezo& bottomlefth() { throw "BHPG3H"; }
    virtual Mezo& bottomrighth() { throw "BHPG3H"; }
    virtual Mezo& bottomh() { throw "BHPG3H"; }
    virtual Mezo& lefth() { throw "BHPG3H"; }
    virtual Mezo& righth() { throw "BHPG3H"; }
};

class Middle : public Mezo {

    Mezo& topleft, topright, top, bottomleft, bottomright, bottom, left, right;

public:

    Middle(Mezo mezo, Mezo topleft, Mezo topright, Mezo top, Mezo bottomleft, Mezo bottomright, Mezo bottom, Mezo left, Mezo right) : Mezo(mezo), topleft(topleft), topright(topright), top(top), bottomleft(bottomleft), bottomright(bottomright), bottom(bottom), left(left), right(right) {}
    Mezo& toplefth() { return topleft; }
    Mezo& toprighth() { return topright; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { return bottomleft; }
    Mezo& bottomrighth() { return bottomright; }
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { return left; }
    Mezo& righth() { return right; }
};



class TopLeft : public Mezo {

    Mezo& bottomright, bottom, right;

public:

    TopLeft(Mezo mezo, Mezo bottomright, Mezo bottom, Mezo right) : Mezo(mezo), bottomright(bottomright), bottom(bottom), right(right) {}
    Mezo& toplefth() { throw "BHPG3H"; }
    Mezo& toprighth() { throw "BHPG3H"; }
    Mezo& toph() { throw "BHPG3H"; }
    Mezo& bottomlefth() { throw "BHPG3H"; }
    Mezo& bottomrighth() { return bottomright; } 
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { throw "BHPG3H"; }
    Mezo& righth() { return right; }
};

class TopRight : public Mezo {

    Mezo& bottomleft, bottom, left;

public:

    TopRight(Mezo mezo, Mezo topleft, Mezo top, Mezo left) : Mezo(mezo), bottomleft(topleft), bottom(top), left(left) {} 
    Mezo& toplefth() { throw "BHPG3H"; }
    Mezo& toprighth() { throw "BHPG3H"; }
    Mezo& toph() { throw "BHPG3H"; }
    Mezo& bottomlefth() { { return bottomleft; } }
    Mezo& bottomrighth() { throw "BHPG3H"; }
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { return left; }
    Mezo& righth() { throw "BHPG3H"; }
};

class BottomLeft : public Mezo {

    Mezo& topright, top, right;

public:

    BottomLeft(Mezo mezo, Mezo topright, Mezo top, Mezo right) : Mezo(mezo), topright(topright), top(top), right(right) {} 
    Mezo& toplefth() { throw "BHPG3H"; }
    Mezo& toprighth() { return topright; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { throw "BHPG3H"; }
    Mezo& bottomrighth() { throw "BHPG3H"; }
    Mezo& bottomh() { throw "BHPG3H"; }
    Mezo& lefth() { throw "BHPG3H"; }
    Mezo& righth() { return right; }
};

class BottomRight : public Mezo {

    Mezo& topleft, top, left;

public:

    BottomRight(Mezo mezo, Mezo topleft, Mezo top, Mezo left) : Mezo(mezo), topleft(topleft), top(top), left(left) {}
    Mezo& toplefth() { return topleft; }
    Mezo& toprighth() { throw "BHPG3H"; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { throw "BHPG3H"; }
    Mezo& bottomrighth() { throw "BHPG3H"; }
    Mezo& bottomh() { throw "BHPG3H"; }
    Mezo& lefth() { return top; }
    Mezo& righth() { throw "BHPG3H"; }
};

class Top : public Mezo {

    Mezo& bottomleft, bottomright, bottom, left, right;

public:

    Top(Mezo(mezo), Mezo bottomleft, Mezo bottomright, Mezo bottom, Mezo left, Mezo right) : Mezo(mezo), bottomleft(bottomleft), bottom(bottom), bottomright(bottomright), left(left), right(right) {}
    Mezo& toplefth() { throw "BHPG3H"; }
    Mezo& toprighth() { throw "BHPG3H"; }
    Mezo& toph() { throw "BHPG3H"; }
    Mezo& bottomlefth() { return bottomleft; }
    Mezo& bottomrighth() { return bottomright; }
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { return left; }
    Mezo& righth() { return right; }
};

class Bottom : public Mezo {

    Mezo& topleft, topright, top, left, right;

public:

    Bottom(Mezo mezo, Mezo topleft, Mezo topright, Mezo top, Mezo right, Mezo left) : Mezo(mezo), topleft(topleft), topright(topright), top(top), left(left), right(right) {}
    Mezo& toplefth() { return topleft; }
    Mezo& toprighth() { return topright; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { throw "BHPG3H"; }
    Mezo& bottomrighth() { throw "BHPG3H"; }
    Mezo& bottomh() { throw "BHPG3H"; }
    Mezo& lefth() { return left; }
    Mezo& righth() { return right; }
};

class Right : public Mezo {

    Mezo& topleft, top, bottomleft, bottom, left;

public:

    Right(Mezo mezo, Mezo topleft, Mezo top, Mezo bottomleft, Mezo bottom, Mezo left) : Mezo(mezo), topleft(topleft), top(top), bottomleft(bottomleft), bottom(bottom), left(left) {}
    Mezo& toplefth() { return topleft; }
    Mezo& toprighth() { throw "BHPG3H"; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { return bottomleft; }
    Mezo& bottomrighth() { throw "BHPG3H"; }
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { return left; }
    Mezo& righth() { throw "BHPG3H"; }
};

class Left : public Mezo {

    Mezo& topright, top, bottomright, bottom, right;

public:

    Left(Mezo mezo, Mezo topright, Mezo top, Mezo bottomright, Mezo bottom, Mezo right) : Mezo(mezo), topright(topright), top(top), bottomright(bottomright), bottom(bottom), right(right) {}
    Mezo& toplefth() { throw "BHPG3H"; }
    Mezo& toprighth() { return topright; }
    Mezo& toph() { return top; }
    Mezo& bottomlefth() { throw "BHPG3H"; }
    Mezo& bottomrighth() { return bottomright; }
    Mezo& bottomh() { return bottom; }
    Mezo& lefth() { throw "BHPG3H"; }
    Mezo& righth() { return right; }
};








class User {

    std::string email;
    std::string nickname;
    std::string password;
    int games;

public:

    User(std::string email, std::string nickname, std::string password) : email(email), nickname(nickname), password(password), games(0) {}
    User() : email("JohnDoe@gmail.com"), nickname("JohnDoe"), password("JohnDoe123") {}
    void setjatszott(int jatszottt) { games = jatszottt; }
    void setpass(std::string pass) { password = pass; }
    std::string getname() { return nickname; }
    std::string getmail() { return email; }
    virtual void lep() {}

};

class Man : public User {

public:

    Man(std::string email, std::string nickname, std::string password) : User(email, nickname, password) {}
    Man(User user) : User(user) {}
    Man() : User() {}
    void lep() {}

};

class Cat : public User {

    Mezo where;

public:

    Cat(std::string email, std::string nickname, std::string password, Mezo where) : User(email, nickname, password), where(where) {}
    Cat(User user, Mezo where) : User(user), where(where) {}
    Cat(User user) : User(user), where(-1, -1, "NA", 0, 0, 0, 0) {}
    Cat() : User(), where(-1, -1, "NA", 0, 0, 0, 0) {}
    void lep() {}
    void drawline() { std::cout << "|OO"; }   

};










void fajlkiolvas(std::string fajlnev) {

    std::fstream fajl(fajlnev);
    std::string fajlsor;
    while (std::getline(fajl, fajlsor)) std::cout << "\n" << fajlsor; 
    fajl.close();

}

void osszesito() {

    std::ifstream fajl("osszesito.txt");
    int ertekeles;
    double atlag;
    fajl >> ertekeles;
    fajl >> atlag;
    std::cout << " From " << ertekeles << " reviews we are rated " << atlag << " stars/5";
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



int arrowfind(int elsovalasz, int maxvalasz, const char* fajlnev, int ertekeles) {

    int jelenlegi = 0;
    econio_rawmode();
    fajlkiolvas("cica line-art.txt");
    jelenlegi = valaszto(elsovalasz, maxvalasz, jelenlegi, fajlnev, ertekeles); 

    while (true) {

        int key = econio_getch();
        if (key == KEY_UP) {

            jelenlegi--;
            for (int i = 0; i < 25; i++) std::cout << "\n";
            fajlkiolvas("cica line-art.txt");
            jelenlegi = valaszto(elsovalasz, maxvalasz, jelenlegi, fajlnev, ertekeles);

        }
        if (key == KEY_DOWN) {

            jelenlegi++;
            for (int i = 0; i < 25; i++) std::cout << "\n";
            fajlkiolvas("cica line-art.txt");
            jelenlegi = valaszto(elsovalasz, maxvalasz, jelenlegi, fajlnev, ertekeles);

        }
        if (key == KEY_ENTER) {

            econio_normalmode();
            return jelenlegi;

        }
        if (key == KEY_ESCAPE) { econio_normalmode(); return -1; }

    }
    econio_normalmode();
    return jelenlegi;

}





void csillag(double star) { 

    fajlkiolvas("ertekelj.txt");

    std::ifstream fajl("csillag.txt");
    std::string fajlsor;
    std::cout << "\n \n";
    while (std::getline(fajl, fajlsor)) {

        int i = 0;
        for (; i < star - 1; i++) std::cout << fajlsor;
        for (double j = 0; j <= (star - i); j += 0.1) std::cout << fajlsor[1 + 10 * j];
        std::cout << "\n";

    }
    std::cout << "\n \n" << star;

}

void animate() {

    std::ifstream listafajl("animations.txt");
    std::string fajlnev;
    while (std::getline(listafajl, fajlnev)) {
        for (int i = 0; i < 25; i++) std::cout << "\n";
        std::fstream fajl(fajlnev);
        std::string fajlsor;
        while (std::getline(fajl, fajlsor)) std::cout << fajlsor << "\n";
        fajl.close();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    system("pause >nul");
    fajlkiolvas("lasagna recipe.txt");
    system("pause >nul");

}



bool bipolar(std::string paratlan, std::string paros) {

    //std::cout << "beleleptunk a bipolar fuggvenybe";

    bool polar = false;
    if (polar) { fajlkiolvas(paros); }
    else { fajlkiolvas(paratlan); }
    econio_rawmode();
    while (true)
    {

        int key = econio_getch();
        if (key == KEY_TAB) polar = !polar;
        if (polar) fajlkiolvas(paros);
        else fajlkiolvas(paratlan);
        if (key == KEY_ENTER) break;
    }
    econio_normalmode();
    return polar;
}



bool modositFelhasznalo(const std::string& fajlNev, const std::string& becenev, int funkcio, const std::string& ujErtek) {
    std::ifstream input(fajlNev);
    if (!input) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << fajlNev << std::endl;
        return false;
    }

    std::ostringstream tartalomBuf;
    tartalomBuf << input.rdbuf();
    std::string tartalom = tartalomBuf.str();
    input.close();

    std::istringstream ss(tartalom);
    std::ostringstream ujTartalom;
    std::string sor;

    bool modositott = false;

    while (std::getline(ss, sor)) {
        if (sor.find("e-mail cím:") == 0) {
            std::string emailSor = sor;
            std::string becenevSor, jelszoSor, jatszottSor;

            std::getline(ss, becenevSor);
            std::getline(ss, jelszoSor);
            std::getline(ss, jatszottSor);

            std::string aktBecenev = becenevSor.substr(strlen("Becenév: "));
            if (aktBecenev == becenev) {
                // Módosítás itt történik
                switch (funkcio) {
                case -1: return true;
                case 1:
                    jelszoSor = "Jelszo: " + ujErtek;
                    break;
                case 2:
                    emailSor = "e-mail cím: " + ujErtek;
                    break;
                case 3: {
                    std::string jatszottStr = jatszottSor.substr(strlen("Jatszott: "));
                    int szam = std::stoi(jatszottStr);
                    ++szam;
                    jatszottSor = "Jatszott: " + std::to_string(szam);
                    break;
                }
                default:
                    std::cerr << "Ismeretlen funkció: " << funkcio << std::endl;
                    return false;
                }

                modositott = true;
            }

            // Írjuk vissza a blokkokat
            ujTartalom << emailSor << '\n'
                << becenevSor << '\n'
                << jelszoSor << '\n'
                << jatszottSor << '\n';
        }
        else {
            ujTartalom << sor << '\n'; // ritkán, de lehet üres sorok is
        }
    }

    if (!modositott) {
        std::cerr << "Nem találtam a becenevet: " << becenev << std::endl;
        return false;
    }

    std::ofstream output(fajlNev);
    if (!output) {
        std::cerr << "Nem sikerült írni a fájlba." << std::endl;
        return false;
    }

    output << ujTartalom.str();
    output.close();

    return true;
}



std::string keresEmailCim(const std::string& fajlNev, const std::string& becenev) {
    std::ifstream input(fajlNev);

    std::string sor;
    while (std::getline(input, sor)) {
        if (sor.find("e-mail cím:") == 0) {
            std::string email = sor.substr(strlen("e-mail cím: "));
            std::string becenevSor;
            std::getline(input, becenevSor);

            std::string aktBecenev = becenevSor.substr(strlen("Becenév: "));
            if (aktBecenev == becenev) {
                return email;
            }

            // Ha nem egyezik, átugorjuk a maradék két sort (Jelszo, Jatszott)
            std::string tmp;
            std::getline(input, tmp); 
            std::getline(input, tmp);
        }
    }

    std::cerr << "Nem találtam a becenevet: " << becenev << std::endl;
    return "";
} 




std::string mail(std::string cim, std::string body) { 
    std::string smtpServer = "smtp.gmail.com"; // SMTP szerver
    std::string smtpPort = "587";               // Port (Gmail: 587)
    std::string username = "szilvi.egyetemi@gmail.com"; // Saját email címed
    std::string password = "ecps ivbm gnum mhrq";     // App Password, nem sima jelszó

    srand(time(0));
    std::string key = std::to_string(rand());

    std::string recipient = cim;
    std::string subject = "CATchA email verification";
    body += key;
    body += " If you did not registered there, you can ignore this email.";

    // PowerShell parancs összeállítása
    std::string command = "powershell -Command \"";
    command += "$securePassword = ConvertTo-SecureString \\\"" + password + "\\\" -AsPlainText -Force; ";
    command += "$credentials = New-Object System.Management.Automation.PSCredential (\\\"" + username + "\\\", $securePassword); ";
    command += "Send-MailMessage -From \\\"" + username + "\\\" -To \\\"" + recipient + "\\\" -Subject \\\"" + subject + "\\\" ";
    command += "-Body \\\"" + body + "\\\" -SmtpServer \\\"" + smtpServer + "\\\" -Port " + smtpPort + " -UseSsl -Credential $credentials\"";

    // Debug kiírás
    //std::cout << "Futtatott parancs: " << command << std::endl;

    int result = system(command.c_str());

    if (result != 0) {
        key = "abc";
    }
    else {
        std::cout << "E-mail sikeresen elküldve!" << std::endl;
    }

    return key;
}



bool vanuser(const std::string keresett) {

    std::ifstream file("jatekos.txt");
    std::string sor;
    while (std::getline(file, sor)) {
        if (sor.rfind("Becenév:", 0) == 0) { // ha a sor "Becenév:"-vel kezdõdik
            std::string becenev = sor.substr(9); // 8 karaktert kihagy ("Becenév: ")
            std::cout << "Az aktualisan nezett becenev " << becenev << "mig a keresett " << keresett << "!\n";
            if (becenev == keresett) {
                return true;
            }
        }
    }
    return false;
}



bool ervenyes_felhasznalo(const std::string& fajlnev, const std::string& becenev, const std::string& jelszo) {
    std::ifstream fajl(fajlnev);

    std::string sor;
    std::string akt_becenev;
    std::string akt_jelszo;

    while (std::getline(fajl, sor)) {
        if (sor.rfind("Becenév:", 0) == 0) {
            akt_becenev = sor.substr(9); // "Becenév: " után
        }
        else if (sor.rfind("Jelszo:", 0) == 0) {
            akt_jelszo = sor.substr(8); // "Jelszo: " után

            // Ekkor már van egy párunk — ellenõrzés
            if (akt_becenev == becenev && akt_jelszo == jelszo) {
                return true;
            }

            // Ellenkezõ esetben tovább megyünk a következõ blokkra
            akt_becenev.clear();
            akt_jelszo.clear();
        }
    }

    return false;
}


std::string szovegbekeres(std::string fajlnev) {

    std::string szoveg;
    std::fstream fajl(fajlnev);
    std::string fajlsor;
    while (std::getline(fajl, fajlsor)) std::cout << "\n" << fajlsor;
    fajl.close();
    std::getline(std::cin, szoveg);
    std::cout << "              |_________________________________________________| \n \n";
    return szoveg;

}



int verifymail(std::string email, int counter, std::string body) {   

        std::cout << "\n \n \n \n \n Verifying your e-mail account.. Please wait..";
        std::string key = mail(email, body); 
        std::string userkey;

        if (key == "abc") {

            std::cout << "Ooops.. wrong email.. Try again!";
            counter = 0;

        }

        else {

            std::fstream fajl("verifytop.txt");
            std::string fajlsor;
            while (std::getline(fajl, fajlsor)) std::cout << "\n" << fajlsor;
            fajl.close();
            std::cout << email << ". Please follow the steps there! ";

            userkey = szovegbekeres("verifybottom.txt");
        }

        if (userkey == key) counter = 5;
        else {

            counter--;

        }
        return counter;

}


bool jelszomodositas(User user) {

    int counter = 3;
    while (counter != 5)
    {
        counter = verifymail(keresEmailCim("jatekos.txt", user.getname()), counter, "If you requested the chnge of password, the verification number is ");
    }

    std::string password = szovegbekeres("password.txt");
    std::string repass;
    while (repass != password) repass = szovegbekeres("repass.txt");

    return modositFelhasznalo("jatekos.txt", user.getname(), 1, password);  

}     





User regisztracio() {

    bool vanilyen = true;
    std::string user;
    while (vanilyen) {
        for (int i = 0; i < 50; i++) std::cout << "\n";
        user = szovegbekeres("username.txt");
        vanilyen = vanuser(user);
    }
    for (int i = 0; i < 5; i++) std::cout << "\n";
    std::string email = szovegbekeres("email.txt");

    int counter = 3;
    while (counter != 5) {

        counter = verifymail(email, counter, "If you registered to CATcha your verification code is ");
        if (counter == 0) { email = szovegbekeres("email.txt"); counter = 3; }

    }
    
    std::string password = szovegbekeres("password.txt");
    std::string repass;
    while (repass != password) repass = szovegbekeres("repass.txt");

    std::fstream file_example("jatekos.txt", std::ofstream::out | std::ofstream::app);
    file_example << "e-mail cím: " << email << "\nBecenév: " << user << "\nJelszo: " << password << "\nJatszott: 0\n\n";
    return User(email, user, password);
}




User bejelentkezes() {

    std::string user;
    std::string pass;
    bool helyes = false;
    while (not helyes) {

        for (int i = 0; i < 50; i++) std::cout << "\n";
        user = szovegbekeres("nickname.txt");
        pass = szovegbekeres("pass.txt");
        helyes = ervenyes_felhasznalo("jatekos.txt", user, pass);
        if (not helyes) { 
            
            std::cout << "\n \n \n \n Uhh something went wrong.. Maybe you did a typeo? \n \n \n"; 
            bool nextstep = bipolar("loginparos.txt", "loginparatlan.txt");
            if (nextstep) jelszomodositas(User(keresEmailCim("jatekos.txt", user), user, "..."));
        
        }

    }
    return User("", user, pass);
}


bool usermodosit() {

    User user = bejelentkezes();

    int funkcio = arrowfind(4, 3, "nextstep.txt", 6);
    if (funkcio == 1) return jelszomodositas(user);  
    if (funkcio == 0) {

        std::string email = szovegbekeres("email.txt");

        int counter = 3;
        while (counter != 5) {

            counter = verifymail(email, counter, "If you registered to CATcha your verification code is ");
            if (counter == 0) { email = szovegbekeres("email.txt"); counter = 3; }

        }
        return modositFelhasznalo("jatekos.txt", user.getname(), 2, email);


    }
    return false; 
}


double leftright(double start, double diff, std::function<void(double)> muvelet, double min, double max) {

    muvelet(start);
    econio_rawmode();

    while (true) {

        int key = econio_getch();
        if (key == KEY_RIGHT) {

            if (start < max) start += diff; 
            muvelet(start);

        }
        if (key == KEY_LEFT) {

            if (start > min) start -= diff;  
            muvelet(start);

        }
        if (key == KEY_ENTER) break;

    }
    econio_normalmode();
    return start;  

}





void ertekel() {

    User user = bejelentkezes();
    double star = leftright(0.1, 0.1, csillag, 0.1, 5);

    for (int i = 0; i < 50; i++) std::cout << "\n";
    fajlkiolvas("specify.txt");
    for (int i = 0; i < 5; i++) std::cout << "\n";
    std::string specizett;
    std::getline(std::cin, specizett);

    std::fstream file_example("velemenyek.txt", std::ofstream::out | std::ofstream::app);
    file_example << user.getname() << "\n" << star << " csillag\n" << specizett << "\n\n";

    std::ifstream osszesites("osszesito.txt");
    int ertekelok; double csillag;
    osszesites >> ertekelok >> csillag;
    double newnum = (ertekelok * csillag + star) / (ertekelok + 1);
    ertekelok += 1;

    std::ofstream osszesitett("osszesito.txt");
    osszesitett << ertekelok << "\n" << newnum << "\n";

}








void sizew(double sized) {   

    for (int i = 0; i < 50; i++) std::cout << "\n";
    fajlkiolvas("sizetop.txt");
    std::cout << sized;
    fajlkiolvas("sizebottom.txt");

}


void sizel(double sized) {

    for (int i = 0; i < 50; i++) std::cout << "\n";
    fajlkiolvas("sizelength.txt");
    std::cout << sized;
    fajlkiolvas("sizebottom.txt");

}




User szemelyek(std::string paratlan, std::string paros, std::string kit, std::string info) {   

    User szemely;
    bool signreg = bipolar(paratlan, paros);
    if (signreg) szemely = regisztracio(); 
    else szemely = bejelentkezes(); 
    for (int i = 0; i < 50; i++) std::cout << "\n";
    fajlkiolvas(kit); 
    fajlkiolvas(info); 
    system("pause >nul");
    return szemely; 

}



void tablarajzol(Mezo* tabla, int width, int length) {

    for (int i = 0; i < width; i++) {

        for (int z = 0; z < 2; z++) {

            for (int j = 0; j < length; j++) { 

                if (z == 0) std::cout << tabla[i * length + j].drawline1(); 
                else std::cout << tabla[i * length + j].drawline2();  

            }
            std::cout << "| \n";

        }

    }

}



/// <summary>
/// Search for a neighbour of a piece in the board and returns it.
/// </summary>
/// <param name="tabla">
/// The whole board
/// </param>
/// <param name="mezo">
/// The reference piece 
/// </param>
/// <param name="xdiff">
/// the index-differentation in the horizontal line
/// -1, 0, 1
/// </param>
/// <param name="ydiff">
/// the index-differentation in the vertical line
/// -1, 0, 1
/// </param>
/// <returns>
/// The piece moved away by the corresponding params rom the original piece, or an unexisting piece if cant find any
/// </returns>
Mezo keresszomszed(Mezo* tabla, Mezo mezo, int xdiff, int ydiff, int length) {  

    Mezo invalid; 
    int keresettx = mezo.getx() + xdiff;
    int keresetty = mezo.gety() + ydiff;
    for (int i = 0; i < length; i++) {

        if (tabla[i].getx() == keresettx && tabla[i].gety() == keresetty) return tabla[i];

    }
    return invalid;
}



Mezo* tablagyarto(Mezo* mezok, int length, int width, int height) {    

    for (int i = 0; i < length; i++) {

        int x = mezok[i].getx(); 
        int y = mezok[i].gety();

        if (x == 0) {

            if (y == 0) mezok[i] = TopLeft(mezok[i], keresszomszed(mezok, mezok[i], 1, 1, length), keresszomszed(mezok, mezok[i], 0, 1, length), keresszomszed(mezok, mezok[i], 1, 0, length));
            if (y == width - 1) mezok[i] = TopRight(mezok[i], keresszomszed(mezok, mezok[i], -1, 1, length), keresszomszed(mezok, mezok[i], 0, 1, length), keresszomszed(mezok, mezok[i], -1, 0, length));

        }

    }
    return mezok;
}



Mezo* ujjatek() { 

    Man man;
    Cat cat; 

    cat = szemelyek("catplaersinin.txt", "catplaerregist.txt", "cica line-art.txt", "oswald.txt"); 
    man = szemelyek("manplayersignin.txt", "manplayerregist.txt", "gazda line-art.txt", "spencer.txt");

    bool shape = bipolar("shapesquare.txt", "shapepolygon.txt");

    double length = leftright(5, 1, sizew, 5, 43);
    double width = leftright(5, 1, sizel, 5, 18);

    std::cout << width << ", " << length;

    Mezo* pontok = new Mezo[width*length]; 

    std::string szamok = "0123456789";

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++) {

            std::string id;
            id += szamok[i]; 
            id += szamok[j];
            std::cout << "\n i = " << i << "\n j = " << j;
            int idx = i * length + j; 
            std::cout << "\n A kovetkezo az index: " << idx << "\n";
            pontok[idx] = Mezo(i, j, id, false, true, false, true);  
            //pontok[idx].get();  

        }
    }
    std::cout << "\n \n \n \n \n \n \ \n";
    tablarajzol(pontok, width, length); 

   


    return pontok; 
}



void palya() {}