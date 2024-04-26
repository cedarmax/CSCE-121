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
#include "Post.h"
#include <sstream>

Post::Post(unsigned int postId, std::string userName, std::string postText) : postId(postId), userName(userName), postText(postText) {
	if (postId == 0 || userName == "" || postText == "") {
		throw std::invalid_argument("post constructor: invalid parameter values");
	}
}

unsigned int Post::getPostId() {
	return postId;
}

std::string Post::getPostUser() {
	return userName;
}

std::string Post::getPostText() {
	return postText;
}

std::vector<std::string> Post::findTags() {
	// TODO(student): extracts candidate tags based on occurrences of # in the post
	std::string lineString = Post::getPostText();
	std::istringstream inSS;
	inSS.str(lineString);
	std::vector<std::string> tags;
	std::string post;
	while (!inSS.eof()) {
	inSS >> post;
		if (post.at(0) == '#') {
			while (post.at(post.length() - 1) == '!' or post.at(post.length() - 1) == ',' or post.at(post.length() - 1) == '.' or post.at(post.length() - 1) == '?') {
				post.erase(post.length() - 1);
			}
			for (unsigned int i = 0; i < post.length(); i++) {
				if (isalpha(post.at(i))) {
					post.at(i) = tolower(post.at(i));
				}
			}
			tags.push_back(post);
		}
	}
	return tags;
}
