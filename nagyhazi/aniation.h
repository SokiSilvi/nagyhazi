//#pragma once
#ifndef ANIATION_H
#define ANIATION_H

#include "filekezeles.h"
//#include "winspecifikus.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
//#include <windows.h>
#include <iostream>

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


bool ertekel() {


	int star;
	std::cin >> star;
	std::cout << star;
	std::string szoveg;
	std::cout << "  Do you want to specify your choice?\n";
	std::cin >> szoveg;
	std::cout << szoveg;
	return false;
}


#endif // !ANIATION_H


