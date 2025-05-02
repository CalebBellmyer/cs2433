/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/
#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course {
		private:
			string courseNumber;
			string courseTitle;

		public:
			void SetCourseNumber(string num);
			void SetCourseTitle(string title);

			string GetCourseNumber() const;
			string GetCourseTitle() const;

			void PrintInfo() const;
};

#endif
