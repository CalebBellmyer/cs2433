/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/
#include "Course.h"
#include <iostream>

using namespace std;


	void Course::SetCourseNumber(string num) {
		courseNumber = num;
	}

	void Course::SetCourseTitle(string title) {
		courseTitle = title;
	}

	string Course::GetCourseNumber() const {
		return courseNumber;
	}

	string Course::GetCourseTitle() const {
		return courseTitle;
	}

	void Course::PrintInfo() const {
		cout << "Course Information:" << endl;
		cout << "   Course Number: " << GetCourseNumber() << endl;
		cout << "   Course Title: " << GetCourseTitle() << endl;
	}
