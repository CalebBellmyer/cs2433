/*
Name: Caleb Bellmyer
CWID: 11638131
Email-ID: caleb.bellmyer@okstate.edu
*/

#include <stdio.h>

typedef struct Student {
    char name[50];
    int roll;
    float marks[3];
    float total;
    float average;
} Student;

Student getStudent(int studentNumber) {
    Student student;
    printf("Enter the Details for student %d:\n", studentNumber);
    printf("Enter the name of the student: ");
    scanf("%s", student.name);
    printf("Enter the roll number of the student: ");
    scanf("%d", &student.roll);
    printf("Enter the marks for subject1: ");
    scanf("%f", &student.marks[0]);
    printf("Enter the marks for subject2: ");
    scanf("%f", &student.marks[1]);
    printf("Enter the marks for subject3: ");
    scanf("%f", &student.marks[2]);
    printf("\n");

    student.total = student.marks[0] + student.marks[1] + student.marks[2];
    student.average = student.total / 3;

    return student;
}

char getGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void printStudent(Student student) {
    printf("Student %d\n", student.roll);
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll);
    printf("Marks in Subject 1: %0.2f\n", student.marks[0]);
    printf("Marks in Subject 2: %0.2f\n", student.marks[1]);
    printf("Marks in Subject 3: %0.2f\n", student.marks[2]);
    printf("Total Marks: %0.2f\n", student.total);
    printf("Average Marks: %0.2f\n", student.average);
    printf("Grade: %c\n", getGrade(student.average));
}

int main() {
    printf("Enter the number of students: ");
    int numberOfStudents;
    scanf("%d", &numberOfStudents);
    printf("\n\n");

    Student students[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++) {
        students[i] = getStudent(i+1);
    }

    printf("Student Records:\n\n");
    for (int i = 0; i < numberOfStudents; i++) {
        printStudent(students[i]);
        printf("\n\n");

    }


    return 0;
}