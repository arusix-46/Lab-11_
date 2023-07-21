/*  Data structures for Students similar to slides (create, traverse, insert, delete). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int age;
    char branch[50];
    struct Student* next;
};

struct Student* head = NULL;
int numStudents = 0;

void createStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("\nEnter student name :- ");
    scanf("%s", newStudent->name);

    printf("Enter student roll number :- ");
    scanf("%d", &newStudent->roll);

    printf("Enter student age :- ");
    scanf("%d", &newStudent->age);

    printf("Enter student branch :- ");
    scanf("%s", newStudent->branch);

    newStudent->next = head;
    head = newStudent;
    numStudents++;

    printf("Student details added successfully.\n");
}

void traverseStudents() {
    if (numStudents == 0) {
        printf("\n------------------------------------------------------\n");
        printf("No entry found.\n");
        printf("------------------------------------------------------\n");
        return;
    }

    printf("\nTraversing student details:\n");
    printf("------------------------------------------------------\n");
    printf("Name\t| Roll\t| Age\t| Branch\n");
    printf("------------------------------------------------------\n");

    struct Student* current = head;
    while (current != NULL) {
        printf("%s\t| %d\t| %d\t| %s\n", current->name, current->roll, current->age, current->branch);
        current = current->next;
    }

    printf("------------------------------------------------------\n");
}

void insertStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter student name :- ");
    scanf("%s", newStudent->name);

    printf("Enter roll number :- ");
    scanf("%d", &newStudent->roll);

    printf("Enter age :- ");
    scanf("%d", &newStudent->age);

    printf("Enter branch :- ");
    scanf("%s", newStudent->branch);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    numStudents++;

    printf("Student details inserted successfully.\n");
}

void deleteStudent() {
    if (numStudents == 0) {
        printf("No entry found. Cannot delete.\n");
        return;
    }

    int rollNumber;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    struct Student* prev = NULL;
    struct Student* current = head;

    while (current != NULL) {
        if (current->roll == rollNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            numStudents--;

            printf("Student details deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Student with roll number %d not found. Cannot delete.\n", rollNumber);
}

void freeLinkedList() {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    numStudents = 0;
}

int main() {
    int choice;
    printf("Create a student details :-");
    createStudent();

    do {
        printf("\n------------------------------------------------------\n");
        printf("\t\t\tMenu:\n");
        printf("------------------------------------------------------\n");
        printf("1. Insert new student details\n");
        printf("2. Display All Students Details (Traverse)\n");
        printf("3. Delete student details\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                traverseStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                freeLinkedList(); // Free the dynamically allocated memory
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
