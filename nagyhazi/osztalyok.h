#pragma once

#include <string>  
#include <iostream>


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
    void stoned() { this->stone = true; this->free = false; }
    void catted() { this->free = false; }
    void setfree() { this->free = true; }
    void sides() { this->side = true; }
    std::string getid() { return id; } 
    bool getfree() { return free; }
    bool getside() { return side; }
    bool getstone() { return stone; }

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

    bool operator==(Mezo masik) { return masik.getid() == this->getid(); }

};







class User {

    std::string email;
    std::string nickname;
    std::string password;
    int games;

public:

    User(std::string email, std::string nickname, std::string password) : email(email), nickname(nickname), password(password), games(0) {}
    User() : email("JohnDoe@gmail.com"), nickname("JohnDoe"), password("JohnDoe123"), games(0) {}
    void setjatszott(int jatszottt) { games = jatszottt; }
    void setpass(std::string pass) { password = pass; }
    std::string getname() { return nickname; }
    std::string getmail() { return email; }
    virtual Mezo* lep(Mezo* tabla, int length, int width, User& masik, bool& gameover) { return tabla; }

};

class Man : public User {

public:

    Man(std::string email, std::string nickname, std::string password) : User(email, nickname, password) {}
    Man(User user) : User(user) {}
    Man() : User() {}
    Mezo* lep(Mezo* tabla, int length, int width, User& masik, bool& gameover);

};

class Cat : public User {

    Mezo where;

public:

    Cat(std::string email, std::string nickname, std::string password, Mezo where) : User(email, nickname, password), where(where) {}
    Cat(User user, Mezo where) : User(user), where(where) {}
    Cat(User user) : User(user), where(-1, -1, "NA", 0, 0, 0, 0) {}
    Cat() : User(), where(-1, -1, "NA", 0, 0, 0, 0) {}
    Mezo hol() { return where; }
    Mezo* lep(Mezo* tabla, int length, int width, User& masik, bool& gameover);
    void merre(Mezo wheres) { where = wheres; }
    void drawline() { std::cout << "|OO"; }

};


class Kiolvasando {

    int tag;

public:

    Kiolvasando() : tag(1) {}
    virtual void prnt() {}

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

    BeolvasottTabla(Mezo* tabla, User cica, User man, int width, int length) : tabla(tabla), cica(cica), man(man), width(width), length(length) {}
    void prnt();
    Cat getcica() { return cica; }
    Man getman() { return man; }

};



