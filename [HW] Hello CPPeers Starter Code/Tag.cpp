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
#include "Tag.h"

Tag::Tag(std::string tagName) : tagName(tagName) {
	// TODO(student): implement constructor checks
	if (tagName.length() < 2 or tagName.at(0) != '#' or !(tagName.at(1) <= 'z' and tagName.at(1) >= 'a') or (tagName.at(1) <= 'Z' and tagName.at(1) >= 'A')) {
		throw std::invalid_argument("");
	} else if ((tagName.at(tagName.length() - 1) == '!' or tagName.at(tagName.length() - 1) == ',' or tagName.at(tagName.length() - 1) == '.' or tagName.at(tagName.length() - 1) == '?') and (tagName.at(tagName.length() - 2) == '!' or tagName.at(tagName.length() - 2) == ',' or tagName.at(tagName.length() - 2) == '.' or tagName.at(tagName.length() - 2) == '?')) {
		throw std::invalid_argument("");
	}
}

std::string Tag::getTagName() {
	// TODO(student): implement getter
	return tagName;
}

std::vector<Post*>& Tag::getTagPosts() {
	// TODO(student): implement getter
	return tagPosts;
}

void Tag::addTagPost(Post* post) {
	// TODO(student): add post to tag posts
	if (post == nullptr) {
		throw std::invalid_argument("");
	}
	tagPosts.push_back(post);
}
