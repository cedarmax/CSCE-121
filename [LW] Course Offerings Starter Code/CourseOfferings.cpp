#include <iostream>
#include <string>
#include "Course.h"
#include "Section.h"
#include "CourseOfferings.h"

using std::cout, std::endl, std::string, std::ostream;

/* TODO: Define copy constructor here. */
CourseOfferings::CourseOfferings(const CourseOfferings& origObject) : course(origObject.course), year(origObject.year), semester(origObject.semester), nbSections(origObject.nbSections), capacity(origObject.capacity), sectionList(new Section[capacity]) {
	for (size_t i = 0; i < nbSections; ++i) {
		sectionList[i] = Section(origObject.sectionList[i]);
	}
}

/* TODO: Define copy assignment operator function here. */
CourseOfferings& CourseOfferings::operator= (const CourseOfferings& objToCopy) {
	if (this != &objToCopy) {
		course = objToCopy.course;
		year = objToCopy.year;
		semester = objToCopy.semester;
		nbSections = objToCopy.nbSections;
		capacity = objToCopy.capacity;
		delete [] this->sectionList;
		sectionList = new Section[capacity];
		for (size_t i = 0; i < nbSections; ++i) {
			sectionList[i] = Section(objToCopy.sectionList[i]);
		}
	}
	return *this;
}

/* TODO: Define destructor here. */
CourseOfferings::~CourseOfferings() {
	delete[] sectionList;
}

/* TODO: Declare CourseOfferings extraction overload operator function here. */
ostream &operator<<(ostream &os, const CourseOfferings &str) {
	os << "Year: " << str.getYear() << " Semester: " << str.getSemester() << " Course ID: " << (str.getCourse()).getId() << endl;
	os << "Course title: " << (str.getCourse()).getTitle() << endl;
	int size = str.getNumberSections();
	for (int i = 0; i < size; i++) {
		os << (str.getSectionList())[i].getId() << (str.getSectionList())[i].getTime() << (str.getSectionList())[i].getLocation() << (str.getSectionList())[i].getInstructor() << endl;
	}
	return os;
}

CourseOfferings::CourseOfferings(Course course, unsigned int year, char semester) 
	: course(course), year(year), semester(semester), nbSections(0), capacity(0), sectionList(nullptr) { }

CourseOfferings::CourseOfferings(unsigned int year, char semester, const CourseOfferings& other)
	: CourseOfferings(other) {
	this->year = year;
	this->semester = semester;
}

void CourseOfferings::addSection(const Section& section) {
	if (nbSections == capacity) {
		increaseSectionListCapacity();
	}
	sectionList[nbSections++] = section;
}

void CourseOfferings::increaseSectionListCapacity() {
	// increase capacity
	capacity = capacity == 0 ? 1 : capacity * 2;
	if (capacity == 0) {
		capacity = 1;
		sectionList = new Section[1] {}; // initialize section list
	}

	// copy old contents to new contents
	Section* newSectionList = new Section[capacity];
	for (size_t i = 0; i < nbSections; ++i) {
		newSectionList[i] = sectionList[i];
	}

	// deallocate old contents
	delete[] sectionList;

	// set old contents to new contents
	sectionList = newSectionList;
}

bool operator==(const CourseOfferings& lhs, const CourseOfferings& rhs) {
	// checking year
	if (! (lhs.getYear() == rhs.getYear()
		&& lhs.getSemester() == rhs.getSemester()
		&& lhs.getCourse().getId() == rhs.getCourse().getId()
		&& lhs.getCourse().getTitle() == rhs.getCourse().getTitle()
		&& lhs.getNumberSections() == rhs.getNumberSections()
		&& lhs.getSectionListCapacity() == rhs.getSectionListCapacity())) {
		return false;
	}

	// checking sections
	for (size_t i = 0; i < lhs.getNumberSections(); i++) {
		Section ls = lhs.getSectionList()[i];
		Section rs = rhs.getSectionList()[i];
		if (!(ls.getId() == rs.getId()
				&& ls.getTime() == rs.getTime()
				&& ls.getLocation() == rs.getLocation()
				&& ls.getInstructor() == rs.getInstructor())) {
			return false;
		}
	}
	return true;
}
