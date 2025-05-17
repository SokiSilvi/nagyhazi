//#pragma once
#ifndef CLASSES_H 
#define CLASSES_H  

#include <string>




class Pont {

	int x, y;

public:

	Pont(int x, int y) : x(x), y(y) {}

};

class Mezo : public Pont {

	std::string id;
	bool stone, real, side, free;

public:

	Mezo(int x, int y, std::string id, bool stone, bool real, bool side, bool free) : Pont(x, y), id(id), stone(stone), real(real), side(side), free(free) {}
	void stoned() { stone = true; free = false; }
	void catted() { free = false; }
	void setfree() { free = true; }
	std::string drawline1() { return "faszomkivan"; }
	std::string drawline2() { return "faszomkivan"; }

};

class Middle : public Mezo {

	Mezo& topleft, topright, top, bottomleft, bottomright, bottom, left, right;

public:

	Middle(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topleft, Mezo topright, Mezo top, Mezo bottomleft, Mezo bottomright, Mezo bottom, Mezo left, Mezo right) : Mezo(x, y, id, stone, real, side, free), topleft(topleft), topright(topright), top(top), bottomleft(bottomleft), bottomright(bottomright), bottom(bottom), left(left), right(right) {}

};



class TopLeft : public Mezo {

	Mezo& bottomright, bottom, right;

public:

	TopLeft(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo bottomright, Mezo bottom, Mezo right) : Mezo(x, y, id, stone, real, side, free), bottomright(bottomright), bottom(bottom), right(right) {}

};

class TopRight : public Mezo {

	Mezo& topleft, top, left;

public:

	TopRight(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topleft, Mezo top, Mezo left) : Mezo(x, y, id, stone, real, side, free), topleft(topleft), top(top), left(left) {}

};

class BottomLeft : public Mezo {

	Mezo& topright, top, right;

public:

	BottomLeft(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topright, Mezo top, Mezo right) : Mezo(x, y, id, stone, real, side, free), topright(topright), top(top), right(right) {}

};

class BottomRight : public Mezo {

	Mezo& topleft, top, left;

public:

	BottomRight(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topleft, Mezo top, Mezo left) : Mezo(x, y, id, stone, real, side, free), topleft(topleft), top(top), left(left) {}

};

class Top : public Mezo {

	Mezo& bottomleft, bottomright, bottom, left, right;

public:

	Top(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo bottomleft, Mezo bottomright, Mezo bottom, Mezo left, Mezo right) : Mezo(x, y, id, stone, real, side, free), bottomleft(bottomleft), bottom(bottom), bottomright(bottomright), left(left), right(right) {}

};

class Bottom : public Mezo {

	Mezo& topleft, topright, top, left, right;

public:

	Bottom(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topleft, Mezo topright, Mezo top, Mezo right, Mezo left) : Mezo(x, y, id, stone, real, side, free), topleft(topleft), topright(topright), top(top), left(left), right(right) {}

};

class Right : public Mezo {

	Mezo& topleft, top, bottomleft, bottom, left;

public:

	Right(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topleft, Mezo top, Mezo bottomleft, Mezo bottom, Mezo left) : Mezo(x, y, id, stone, real, side, free), topleft(topleft), top(top), bottomleft(bottomleft), bottom(bottom), left(left) {}

};

class Left : public Mezo {

	Mezo& topright, top, bottomright, bottom, right;

public:

	Left(int x, int y, std::string id, bool stone, bool real, bool side, bool free, Mezo topright, Mezo top, Mezo bottomright, Mezo bottom, Mezo right) : Mezo(x, y, id, stone, real, side, free), topright(topright), top(top), bottomright(bottomright), bottom(bottom), right(right) {}

};








class User {

	std::string email;
	std::string nickname;
	std::string password;
	int games;

public:

	User(std::string email, std::string nickname, std::string password, int games) : email(email), nickname(nickname), password(password), games(0) {} 
	void setjatszott(int jatszottt) { games = jatszottt; }
	void setpass(std::string pass) { password = pass; }
	virtual void lep() {}

};

class Man : public User {

public:

	Man(std::string email, std::string nickname, std::string password) : User(email, nickname, password) {}
	void lep() {}

};

class Cat : public User {

	Mezo where;

public:

	Cat(std::string email, std::string nickname, std::string password, Mezo where) : User(email, nickname, password), where(where) {}
	void lep() {}
	void drawline() {}

};






#endif // !CLASSES_H



