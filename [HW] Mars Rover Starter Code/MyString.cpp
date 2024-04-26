// TODO: Implement this source file
#include "MyString.h"
#include <iostream>
MyString::MyString() : siz(0), cap(0), len(0), array(new char[1] {'\0'}) {}

MyString::MyString(const MyString &str) : siz(str.siz), cap(str.cap), len(str.len), array(str.array) {
	for (int i = 0; i < siz; i++) {
		array[i] = str.array[i];
	}
}
MyString::MyString(const char* s) : siz(0), cap(0), len(0), array(0) {
	for (int i = 0; s[i] != '\0'; i++) {
		cap++;
		len++;

			
	}
}
MyString::~MyString() {

}
void MyString::resize (size_t n) {}
size_t MyString::capacity() const noexcept {
	return 0;
}
size_t MyString::size() const noexcept {
	return 0;
}
size_t MyString::length() const noexcept {
	return 0;
}
const char* MyString::data() const noexcept {
	return 0;
}
bool MyString::empty() const noexcept {
	return 0;
}
const char& MyString::front() const {
	const char x = '0';
	return x;
}
const char& MyString::at (size_t pos) const {
	const char x = pos;
	return x;
}
void MyString::clear() noexcept {}
std::ostream &operator<<(std::ostream &os, const MyString& str) {
	return os;
}
MyString& MyString::operator= (const MyString& str) {
	return *this;
}
MyString& MyString::operator+= (const MyString& str) {
	return *this;
}
size_t MyString::find (const MyString& str, size_t pos) const noexcept {
	return pos;
}
/*
bool MyString::operator== (const MyString& lhs, const MyString& rhs) noexcept {
	return 0;
}
bool MyString::operator== (const char* lhs, const MyString& rhs) {
	return 0;
}
bool MyString::operator== (const MyString& lhs, const char* rhs) {
	return 0;
}
MyString MyString::operator+ (const MyString& lhs, const MyString& rhs) {
	return 0;
}
MyString MyString::operator+ (MyString&& lhs, MyString&& rhs) {
	return 0;
}
MyString MyString::operator+ (MyString&& lhs, const MyString& rhs) {
	return 0;
}
MyString MyString::operator+ (const MyString& lhs, MyString&& rhs) {
	return 0;
}
*/
