#pragma once

#include "memtrace.h"
#include <string>
#include "Mezo.h"




class User {

    std::string email;
    std::string nickname;
    std::string password;
    int games;

public:

    User(std::string email, std::string nickname, std::string password) : email(email), nickname(nickname), password(password), games(0) {}
    User() : email("JohnDoe@gmail.com"), nickname("JohnDoe"), password("JohnDoe123"), games(0) {}
    virtual ~User();
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
    virtual ~Man();
    Mezo* lep(Mezo* tabla, int length, int width, User& masik, bool& gameover);

};

class Cat : public User {

    Mezo where;

public:

    Cat(std::string email, std::string nickname, std::string password, Mezo where) : User(email, nickname, password), where(where) {}
    Cat(User user, Mezo where) : User(user), where(where) {}
    Cat(User user) : User(user), where(-1, -1, "NA", 0, 0, 0, 0) {}
    Cat() : User(), where(-1, -1, "NA", 0, 0, 0, 0) {}
    virtual ~Cat();
    Mezo hol() { return where; }
    Mezo* lep(Mezo* tabla, int length, int width, User& masik, bool& gameover);
    void merre(Mezo wheres) { where = wheres; }
    void drawline() { std::cout << "|OO"; }

};