#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct {
    int id;
    char firstName[50];
    char lastName[50];
    float appliedMathGrade;
    float linuxGrade;
    float webTechGrade;
} Student;

// Function prototypes
void createStudent(Student students[], int *numStudents);
void readStudents(Student students[], int numStudents);
void updateStudent(Student students[], int numStudents);
void deleteStudent(Student students[], int *numStudents);
void generateReport(Student students[], int numStudents);

int main() {
    Student students[100];  // Array to store student records
    int numStudents = 0;    // Variable to track the number of students

    int choice;
    do {
        // Display menu options
        printf("\nStudent Management System\n");
        printf("1. Create Student\n");
        printf("2. Read Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createStudent(students, &numStudents);
                break;
            case 2:
                readStudents(students, numStudents);
                break;
            case 3:
                updateStudent(students, numStudents);
                break;
            case 4:
                deleteStudent(students, &numStudents);
                break;
            case 5:
                generateReport(students, numStudents);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void createStudent(Student students[], int *numStudents) {
    printf("Enter student details:\n");
    printf("ID: ");
    scanf("%d", &students[*numStudents].id);
    printf("First Name: ");
    scanf("%s", students[*numStudents].firstName);
    printf("Last Name: ");
    scanf("%s", students[*numStudents].lastName);
    printf("Enter grade for Applied Math: ");
    scanf("%f", &students[*numStudents].appliedMathGrade);
    printf("Enter grade for Linux: ");
    scanf("%f", &students[*numStudents].linuxGrade);
    printf("Enter grade for Web Tech: ");
    scanf("%f", &students[*numStudents].webTechGrade);
    (*numStudents)++;
    printf("Student added successfully!\n");
}

void readStudents(Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("Student records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("ID: %d, Name: %s %s\n",
                students[i].id, students[i].firstName, students[i].lastName);
    }
}

void updateStudent(Student students[], int numStudents) {
    int id;
    printf("Enter the ID of the student to update: ");
    scanf("%d", &id);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            printf("Enter new details for the student:\n");
            printf("First Name: ");
            scanf("%s", students[i].firstName);
            printf("Last Name: ");
            scanf("%s", students[i].lastName);
            printf("Enter grade for Applied Math: ");
            scanf("%f", &students[i].appliedMathGrade);
            printf("Enter grade for Linux: ");
            scanf("%f", &students[i].linuxGrade);
            printf("Enter grade for Web Tech: ");
            scanf("%f", &students[i].webTechGrade);
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent(Student students[], int *numStudents) {
    int id;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            printf("Student with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void generateReport(Student students[], int numStudents) {
    printf("Generating report...\n");
    printf("Student Report:\n");
    printf("ID\tName\tApplied Math Grade\tLinux Grade\tWeb Tech Grade\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s %s\t%.2f\t%.2f\t%.2f\n",
                students[i].id, students[i].firstName, students[i].lastName,
                students[i].appliedMathGrade, students[i].linuxGrade, students[i].webTechGrade);
    }
    printf("Report generated successfully!\n");
}
