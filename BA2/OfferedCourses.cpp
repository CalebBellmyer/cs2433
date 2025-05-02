/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/
#include "OfferedCourses.h"
#include <string>
#include <iostream>

using namespace std;

void OfferedCourses::SetInstructorName(string name) {
	instructorName = name;
}

void OfferedCourses::SetLocation(string loc) {
	location = loc;
}

void OfferedCourses::SetClassTime(string time) {
	classTime = time;
}

string OfferedCourses::GetInstructorName() const {
	return instructorName;
}

string OfferedCourses::GetLocation() const {
	return location;
}

string OfferedCourses::GetClassTime() const {
	return classTime;
}