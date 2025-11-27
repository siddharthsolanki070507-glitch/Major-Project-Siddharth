#include <stdio.h>
#include <string.h>
#include "student.h"

char studentName[50];
char rollNumber[20];
int marks[MAX_SUBJECTS];
int totalSubjects = 0;
float percentage = 0;
int dataEntered = 0;

void enterStudentDetails() {
    int i;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", studentName);

    printf("Enter Roll Number: ");
    scanf("%s", rollNumber);

    printf("Enter number of subjects: ");
    scanf("%d", &totalSubjects);

    if (totalSubjects <= 0 || totalSubjects > MAX_SUBJECTS) {
        printf("\nInvalid subject count. Try again.\n");
        return;
    }

    for (i = 0; i < totalSubjects; i++) {
        printf("Enter marks for Subject %d (Out of 100): ", i + 1);
        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Enter between 0 and 100.\n");
            i--;
        }
    }

    dataEntered = 1;
    printf("\nDetails stored successfully.\n");
}

void calculatePercentage() {
    if (!dataEntered) {
        printf("\nNo data available. Enter student details first.\n");
        return;
    }

    int sum = 0;

    for (int i = 0; i < totalSubjects; i++) {
        sum += marks[i];
    }

    percentage = (sum / (float)(totalSubjects * 100)) * 100.0;

    printf("\nPercentage calculated successfully.\n");
}

void displayStudentRecord() {
    if (!dataEntered) {
        printf("\nNo record available. Enter student details first.\n");
        return;
    }

    printf("\n===========================================\n");
    printf("              STUDENT RECORD\n");
    printf("===========================================\n");
    printf("Name           : %s\n", studentName);
    printf("Roll Number    : %s\n", rollNumber);
    printf("-------------------------------------------\n");

    for (int i = 0; i < totalSubjects; i++) {
        printf("Subject %d Marks : %d\n", i + 1, marks[i]);
    }

    printf("-------------------------------------------\n");
    printf("Percentage     : %.2f%%\n", percentage);
    printf("===========================================\n");
}
