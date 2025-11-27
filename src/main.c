#include <stdio.h>
#include <string.h>

void enterStudentDetails();
void calculatePercentage();
void displayStudentRecord();
void clearScreen();
char studentName[50];
char rollNumber[20];
int marks[10];
int totalSubjects = 0;
float percentage = 0;
int dataEntered = 0;

int main() {
    int choice;

    while (1) {
        printf("\n===========================================\n");
        printf("     STUDENT MARKS MANAGEMENT SYSTEM\n");
        printf("===========================================\n");
        printf("1. Enter Student Details\n");
        printf("2. Calculate Percentage\n");
        printf("3. Display Student Record\n");
        printf("4. Clear Screen\n");
        printf("5. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterStudentDetails();
                break;

            case 2:
                calculatePercentage();
                break;

            case 3:
                displayStudentRecord();
                break;

            case 4:
                clearScreen();
                break;

            case 5:
                printf("\nExiting program. Thank you!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void enterStudentDetails() {
    int i;

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", studentName);

    printf("Enter Roll Number: ");
    scanf("%s", rollNumber);

    printf("Enter number of subjects: ");
    scanf("%d", &totalSubjects);

    if (totalSubjects <= 0 || totalSubjects > 10) {
        printf("\nInvalid subject count. Try again.\n");
        return;
    }

    for (i = 0; i < totalSubjects; i++) {
        printf("Enter marks for Subject %d (out of 100): ", i + 1);
        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Please enter between 0 and 100.\n");
            i--;
            continue;
        }
    }

    printf("\nDetails stored successfully.\n");
    dataEntered = 1;
}

void calculatePercentage() {
    if (!dataEntered) {
        printf("\nNo data available. Enter student details first.\n");
        return;
    }

    int sum = 0, i;

    for (i = 0; i < totalSubjects; i++) {
        sum += marks[i];
    }

    percentage = (sum / (float)(totalSubjects * 100)) * 100.0;

    printf("\nPercentage calculated successfully.\n");
}

void displayStudentRecord() {
    if (!dataEntered) {
        printf("\nNo record available. Please enter student details.\n");
        return;
    }

    printf("\n===========================================\n");
    printf("              STUDENT RECORD\n");
    printf("===========================================\n");
    printf("Name           : %s\n", studentName);
    printf("Roll Number    : %s\n", rollNumber);
    printf("-------------------------------------------\n");

    int i;
    for (i = 0; i < totalSubjects; i++) {
        printf("Subject %d Marks : %d\n", i + 1, marks[i]);
    }

    printf("-------------------------------------------\n");
    printf("Percentage     : %.2f%%\n", percentage);
    printf("===========================================\n");
}

void clearScreen() {
    printf("\033[2J\033[1;1H");
    printf("Screen Cleared.\n");
