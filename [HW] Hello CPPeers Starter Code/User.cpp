/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

User::User(std::string userName) : userName(userName) {
	// TODO(student): implement constructor checks
	if (userName == "" or !isalpha(userName.at(0))) {
		throw std::invalid_argument("Black 1");
	}
	for (unsigned int i = 0; i < userName.length(); i++) {
		if (userName.at(i) <= 'Z' and userName.at(i) >= 'A') {
			throw std::invalid_argument("Black");
		}
	}
}

std::string User::getUserName() {
	// TODO(student): implement getter
	return userName;
}

std::vector<Post*>& User::getUserPosts() {
	// TODO(student): implement getter
	return userPosts;
}

void User::addUserPost(Post* post) {
	// TODO(student): add post to user posts
	if (post == nullptr) {
		throw std::invalid_argument("");
	}
	userPosts.push_back(post);
}
