/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int NAME_WIDTH = 18;
const int SCORE_WIDTH = 8;
const int AVG_WIDTH = 10;
const int GRADE_WIDTH = 8;
const int TOTAL_WIDTH = NAME_WIDTH + 4 * SCORE_WIDTH + AVG_WIDTH + GRADE_WIDTH + 7;

class Student {
    private:
        string name;
        int mt1;
        int mt2;
        int finals;
        double average;
        char grade;

        void calculateAverage (){
            average = static_cast<double>(mt1 + mt2 + finals) / 3.0;
        }

        void calculateGrade() {
            if (average >= 90.0) {
                grade = 'A';
            } else if ( average >+ 80.00) {
                grade = 'B';
            } else if ( average >= 70.0 ) {
                grade = 'C';
            } else if ( average >= 60.0) {
                grade = 'D';
            } else {
                grade = 'F';
            }
        }

        public:

            Student() : name(""), mt1(0), mt2(0), finals(), grade('F') {}

            void readData() {
                cin >> name;
                cin >> mt1;
                cin >> mt2;
                cin >> finals; 

                calculateAverage();
                calculateGrade();
            }

            void displayData() const {
                cout << "| " << left << setw(NAME_WIDTH) << name << " |"
                  << right << setw(SCORE_WIDTH) << mt1 << " |"
                  << right << setw(SCORE_WIDTH) << mt2 << " |"
                  << right << setw(SCORE_WIDTH) << finals << " |"
                  << right << setw(AVG_WIDTH) << fixed << setprecision(2) << average << " |"
                  << right << setw(GRADE_WIDTH) << grade << " |" << endl;
            }

            static void printHeader() {
                cout << string(TOTAL_WIDTH, '=') << std::endl; 
                cout << "| " << left <<setw(NAME_WIDTH) << "Name" << " |"
                    << right << setw(SCORE_WIDTH) << "MT-1" << " |"
                    << right << setw(SCORE_WIDTH) << "MT-2" << " |"
                    << right << setw(SCORE_WIDTH) << "Finals" << " |"
                    << right << setw(AVG_WIDTH) << "Average" << " |"
                    << right << setw(GRADE_WIDTH) << "Grade" << " |" << endl;
                cout << string(TOTAL_WIDTH, '=') << endl; 
            }

            static void printSeparator() {
                cout << string(TOTAL_WIDTH, '-') << endl;
            }

            static void printFooter() {
                cout << string(TOTAL_WIDTH, '=') << endl;
            }

};


int main () {
    vector<Student> students(5); 

    for (int i = 0; i < 5; i++) {
        cout << "Enter info for student " << (i + 1) << ": " << endl;
        students[i].readData();
    }

    Student::printHeader();

    for (int i = 0; i < 5; i++) {
        students[i].displayData();
        if (i <  4) {
            Student::printSeparator();
        }
    }

    Student::printFooter();

    return 0;
}