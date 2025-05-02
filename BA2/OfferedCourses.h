/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/
#ifndef OFFERED_COURSESH
#define OFFERED_COURSESH

#include "Course.h"
#include <string>

using namespace std;

class OfferedCourses : public Course {
	private:
		string instructorName;
		string location;
		string classTime;

	public:
		void SetInstructorName(string name);
		void SetLocation(string loc);
		void SetClassTime(string time);

		string GetInstructorName() const;
		string GetLocation() const;
		string GetClassTime() const;
};

#endif