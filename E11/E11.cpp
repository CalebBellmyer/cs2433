/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <iostream>
#include <string> 
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

class Student {
    private:
        int rollNumber;
        string name;

    protected: 
        void setDetails(int r, const string& n) {
            rollNumber = r;
            name = n;
        }

    public: 
        Student() : rollNumber(0), name("") {}

        int getRollNumber() const {
            return rollNumber;
        }

        string getName() const {
            return name;
        }
};

class Test : public Student {
    protected:
        int physMarks;
        int chemMarks;
        int mathMarks;

        void setMarks(int phys, int chem, int math) {
            physMarks = (phys >= 0 && phys <= 100) ? phys : 0;
            chemMarks = (chem >= 0 && chem <= 100) ? chem : 0;
            mathMarks = (math >= 0 && math <= 100) ? math : 0;
        }

    public:
        Test() : physMarks(0), chemMarks(0), mathMarks(0) {}

        int getPhysMarks() const {
            return physMarks;
        }

        int getChemMarks() const {
            return chemMarks;
        }

        int getMathMarks() const {
            return mathMarks;
        }
};

class Result : public Test {
    private:
        int totalMarks;
        char grade;

        void calcGrade() {
            totalMarks = physMarks + chemMarks + mathMarks;

            if (totalMarks >= 270) {
                grade = 'A';
            } else if (totalMarks >= 240) {
                grade = 'B';
            } else if (totalMarks >= 210) {
                grade = 'C';
            } else if (totalMarks >= 180) {
                grade = 'D';
            } else {
                grade = 'F';
            }
        }

    public:
        Result() : totalMarks(0), grade('F') {}

        void handleInput() {
            int roll, phys, chem, math;
            string fullName;

            while(!(cin >> roll)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, fullName);

            while (!(cin >> phys) || phys < 0 || phys > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            while (!(cin >> chem) || chem < 0 || chem > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            while (!(cin >> math) || math < 0 || math > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            setDetails(roll, fullName);
            setMarks(phys, chem, math);

            calcGrade();
        }

        void displayResult() const {
            cout << "Roll Number: " << getRollNumber() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Marks obtained in Physics: " << getPhysMarks() << endl;
            cout << "Marks obtained in Chemistry: " << getChemMarks() << endl;
            cout << "Marks obtained in Mathematics: " << getMathMarks() << endl;
            cout << "Total Marks: " << totalMarks << endl;
            cout << "Final Grade: " << grade << endl; 
    }
};

int main() {
    int numStudents;

    cout << "Enter the Number of Students: " << endl;

    
    while (!(cin >> numStudents) || numStudents <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of students: ";
        cin.clear();
    }
    vector<Result> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the Details of Student - " << (i + 1) << ": " << endl;
        students[i].handleInput();
    }


    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent - " << (i + 1) << " Details: " << endl;
        students[i].displayResult();
    }

    return 0;
}

