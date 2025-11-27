#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUBJECTS 10

extern char studentName[50];
extern char rollNumber[20];
extern int marks[MAX_SUBJECTS];
extern int totalSubjects;
extern float percentage;
extern int dataEntered;

void enterStudentDetails();
void calculatePercentage();
void displayStudentRecord();

#endif
