// TODO: Implement this header file
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#ifndef MYSTRING_H
#define MYSTRING_H
class MyString {
	private:
		int siz;
		int cap;
		int len;
		char* array;
	public:
		MyString();
		MyString(const MyString &str);
		MyString(const char* s);
		~MyString();
		void resize (size_t n);
		size_t capacity() const noexcept;
		size_t size() const noexcept;
		size_t length() const noexcept;
		const char* data() const noexcept;
		bool empty() const noexcept;
		const char& front() const;
		const char& at (size_t pos) const;
		void clear() noexcept;
		friend std::ostream &operator<<(std::ostream &os, const MyString& str);
		MyString& operator= (const MyString& str);
		MyString& operator+= (const MyString& str);
		size_t find (const MyString& str, size_t pos = 0) const noexcept;
		/*
		bool operator== (const MyString& lhs, const MyString& rhs) noexcept;
		bool operator== (const char* lhs, const MyString& rhs);
		bool operator== (const MyString& lhs, const char* rhs);
		MyString operator+ (const MyString& lhs, const MyString& rhs);
		MyString operator+ (MyString&& lhs, MyString&& rhs);
		MyString operator+ (MyString&& lhs, const MyString& rhs);
		MyString operator+ (const MyString& lhs, MyString&& rhs);
		*/
};
#endif
