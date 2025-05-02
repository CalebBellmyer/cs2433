#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char name[50];
    int roll;
    float marks[3];
    float total;
    float average;
    int id;
} Student;

Student getStudent(int studentNumber);
char getGrade(float average);
void printStudent(Student student);

#endif
