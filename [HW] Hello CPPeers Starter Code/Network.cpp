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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

Network::Network() {
	// empty containers of vectors already created
	// no implementation is needed here
}

void Network::loadFromFile(std::string fileName) {
	// TODO(student): load user and post information from file
	std::ifstream inFS;
	std::string lineString;
	std::istringstream inSS;
	inFS.open(fileName);
	std::string userName;
	unsigned int postId;
	std::string postText;
	if (!inFS.is_open()) {
		throw std::invalid_argument("");
	}
	while(!inFS.eof()) {
		std::string firstWord;
		std::string test;
		std::getline(inFS, lineString);
		inSS.clear();
		inSS.str(lineString);
		inSS >> firstWord;
		if (firstWord != "Post" and firstWord != "User") {
			throw std::runtime_error("hello");
		} else if (firstWord == "Post") {
			inSS >> postId;
			inSS >> userName;
			std::getline(inSS, postText);
			if (inSS >> test) {
				throw std::runtime_error("");
			}
			try {
				addPost(postId, userName, postText);	
			} catch (std::exception &e) {
				throw std::runtime_error("hello2");
			}
		} else if (firstWord == "User") {
			inSS >> userName;
			if (inSS >> test) {
				throw std::runtime_error("");
			}
			try {
				addUser(userName);
			} catch (std::exception &e) {
				throw std::runtime_error("hello3");
			}
		}
		if (!inFS.peek()) {
			break;
		}
	}
	inFS.close();
}

void Network::addUser(std::string userName1) {
	// TODO(student): create user and add it to network
	for (unsigned int i = 0; i < userName1.length(); i++) {
		if (isalpha(userName1.at(i))) {
			userName1.at(i) = tolower(userName1.at(i));
		}
	}
	for (unsigned int i = 0; i < users.size(); i++) {
		if (userName1 == users.at(i)->getUserName()) {
			throw std::invalid_argument("");
		}
	}
	User *newUser = new User(userName1);
	users.push_back(newUser);
	std::cout << "Added User " << userName1 << std::endl;
}

void Network::addPost(unsigned int postId, std::string userName, std::string postText) {
	// TODO(student): create post and add it to network
	for (unsigned int i = 0; i < posts.size(); i++) {
		if (postId == posts.at(i)->getPostId()) {
			throw std::invalid_argument("");
		}
	}
	for (unsigned int i = 0; i < users.size(); i++) {
		if (userName == users.at(i)->getUserName()) {
			break;
		} else {
			if (i == users.size() - 1) {
				throw std::invalid_argument("");
			}
		}
	}
	Post *newPost = new Post(postId, userName, postText);
	posts.push_back(newPost);
	User(userName).addUserPost(newPost);
	std::vector<std::string> newPostTags = newPost->findTags();
	for (unsigned int i = 0; i < newPostTags.size(); i++) {
		if (tags.size() == 0) {
			Tag *newTag = new Tag(newPostTags.at(i));
			newTag->addTagPost(newPost);
			try {
				tags.push_back(newTag);
			} catch (std::exception &e) {
				std::cout << "poop" << std::endl;
				continue;
			}
			continue;
		}
		for (unsigned int j = 0; j < tags.size(); i++) {
			if (newPostTags.at(i) == tags.at(j)->getTagName()) {
				tags.at(j)->addTagPost(newPost);
			} else if (newPostTags.at(i) != tags.at(j)->getTagName() and j == tags.size() - 1) {
				Tag *newTag = new Tag(newPostTags.at(i));
				tags.at(j)->addTagPost(newPost);	
				try {
					tags.push_back(newTag);
				} catch (std::exception &e) {
					continue;
				}
			}
		}
	}
	std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

std::vector<Post*> Network::getPostsByUser(std::string userName) {
	// TODO(student): return posts created by the given user
	std::vector<Post*> postsByUser;
	if (userName == "") {
		throw std::invalid_argument("");
	}
	int foundCount = 0;
	for (unsigned int i = 0; i < posts.size(); i++) {
		if (userName == posts.at(i)->getPostUser()) {
			postsByUser.push_back(posts.at(i));
			foundCount++;
		} else {
			if (i == posts.size() - 1 and foundCount == 0) {
				throw std::invalid_argument("");
			}
		}
	}
	return postsByUser;
}

std::vector<Post*> Network::getPostsWithTag(std::string tagName) {
	// TODO(student): return posts containing the given tag
	std::vector<Post*> postsWithTag;
	std::cout << "tagName: " << tagName << std::endl;
	if (tagName == "") {
		throw std::invalid_argument("");
	}
	for (unsigned int i = 0; i < tags.size(); i++) {
		if (tagName == tags.at(i)->getTagName()) {
			postsWithTag = tags.at(i)->getTagPosts();
			for (unsigned int i = 0; i < postsWithTag.size(); i++) {
				std::cout << postsWithTag.at(i)->getPostText() << std::endl;
			}	
			return postsWithTag;
		} else {
			if (i == tags.size() - 1) {
				throw std::invalid_argument("");
			}
		}
	}
	return postsWithTag;
}

std::vector<std::string> Network::getMostPopularHashtag() {
	// TODO(student): return the tag occurring in most posts
	std::vector<std::string> mostPopularHashtag;
	
	return mostPopularHashtag;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
	for (unsigned int i = 0; i < users.size(); ++i) {
		delete users.at(i);
	}
	for (unsigned int i = 0; i < tags.size(); ++i) {
		delete tags.at(i);
	}
	for (unsigned int i = 0; i < posts.size(); ++i) {
		delete posts.at(i);
	}
}
