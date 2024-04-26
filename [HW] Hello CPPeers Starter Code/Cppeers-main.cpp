/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Network.h"

void printMenu() {
	std::cout << "Welcome to CPPeers" << std::endl;
	std::cout << "The options are: " << std::endl;
	std::cout << "1. load data file and add information" << std::endl;
	std::cout << "2. show posts by user" << std::endl;
	std::cout << "3. show posts with hashtag" << std::endl;
	std::cout << "4. show most popular hashtag" << std::endl;
	std::cout << "9. quit" << std::endl;
	std::cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
	std::string fileName = "";
	std::cout << "Enter filename: ";
	std::cin >> fileName;
	cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
	// TODO(student): implement
}

void processPostsWithHashtags(Network& cppeers) {
	// TODO(student): implement
}

void processMostPopularHashtag(Network& cppeers) {
	// TODO(student): implement
}

int main() {

	try {
		Network cppeers;

		int choice = 0;

		// present menu
		do {
			printMenu();
			std::cin >> choice;
			switch(choice) {
				case 1: {
					processLoad(cppeers);
					break;
				}
				case 2: {
					processPostsByUser(cppeers);
					break;
				}
				case 3: {
					processPostsWithHashtags(cppeers);
					break;
				}
				case 4: {
					processMostPopularHashtag(cppeers);
					break;
				}
			}
		} while (choice != 9);
	} catch (std::exception& exc) {
		std::cout << exc.what() << std::endl;
	}

	return 0;
}
