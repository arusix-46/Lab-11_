/*  Data structures for Students similar to slides (create, traverse, insert, delete). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    struct Student* next;
};

typedef struct Student Student;

struct StudentLinkedList {
    Student* head;
};

typedef struct StudentLinkedList StudentLinkedList;

void insert(StudentLinkedList* list, Student* student) {
    if (list->head == NULL) {
        list->head = student;
    } else {
        Student* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = student;
    }
}

void traverse(StudentLinkedList* list) {
    Student* temp = list->head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void delete(StudentLinkedList* list, int id) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->id == id) {
        Student* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    Student* temp = list->head;
    while (temp->next != NULL && temp->next->id != id) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Student* deletedNode = temp->next;
        temp->next = temp->next->next;
        free(deletedNode);
    }
}

void concatenate(StudentLinkedList* list1, Student* head2) {
    if (list1->head == NULL) {
        list1->head = head2;
    } else {
        Student* temp = list1->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

void insertSorted(StudentLinkedList* list, Student* element) {
    if (list->head == NULL || element->id < list->head->id) {
        element->next = list->head;
        list->head = element;
        return;
    }
    Student* temp = list->head;
    while (temp->next != NULL && element->id > temp->next->id) {
        temp = temp->next;
    }
    element->next = temp->next;
    temp->next = element;
}

void insertQueue(StudentLinkedList* list, Student* element) {
    if (list->head == NULL) {
        list->head = element;
    } else {
        Student* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = element;
    }
}

Student* deleteQueue(StudentLinkedList* list) {
    if (list->head == NULL) {
        return NULL;
    }
    Student* deletedNode = list->head;
    list->head = list->head->next;
    deletedNode->next = NULL;
    return deletedNode;
}

int main() {
    StudentLinkedList list;
    list.head = NULL;

    // Test inserting students
    insert(&list, (Student*)malloc(sizeof(Student)));
    list.head->id = 1;
    strcpy(list.head->name, "John");
    list.head->next = NULL;

    insert(&list, (Student*)malloc(sizeof(Student)));
    list.head->next->id = 2;
    strcpy(list.head->next->name, "Alice");
    list.head->next->next = NULL;

    insert(&list, (Student*)malloc(sizeof(Student)));
    list.head->next->next->id = 3;
    strcpy(list.head->next->next->name, "Bob");
    list.head->next->next->next = NULL;

    // Test traversing the list
    printf("Students in the list:\n");
    traverse(&list);

    // Test deleting a student
    delete(&list, 2);
    printf("After deleting student with ID 2:\n");
    traverse(&list);

    // Test concatenating two lists
    StudentLinkedList list2;
    list2.head = NULL;

    insert(&list2, (Student*)malloc(sizeof(Student)));
    list2.head->id = 4;
    strcpy(list2.head->name, "Eve");
    list2.head->next = NULL;

    insert(&list2, (Student*)malloc(sizeof(Student)));
    list2.head->next->id = 5;
    strcpy(list2.head->next->name, "Mike");
    list2.head->next->next = NULL;

    printf("Students in the second list:\n");
    traverse(&list2);

    concatenate(&list, list2.head);
    printf("Concatenated list:\n");
    traverse(&list);

    // Test inserting an element in sorted order
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = 6;
    strcpy(newStudent->name, "Sarah");
    newStudent->next = NULL;

    insertSorted(&list, newStudent);
    printf("After inserting new student in sorted order:\n");
    traverse(&list);

    // Test insertQueue and deleteQueue
    StudentLinkedList queueList;
    queueList.head = NULL;

    insertQueue(&queueList, (Student*)malloc(sizeof(Student)));
    queueList.head->id = 10;
    strcpy(queueList.head->name, "Amy");
    queueList.head->next = NULL;

    insertQueue(&queueList, (Student*)malloc(sizeof(Student)));
    queueList.head->next->id = 11;
    strcpy(queueList.head->next->name, "Mark");
    queueList.head->next->next = NULL;

    printf("Students in the queue list:\n");
    traverse(&queueList);

    Student* deletedNode = deleteQueue(&queueList);
    printf("Deleted node from the queue: ID: %d, Name: %s\n", deletedNode->id, deletedNode->name);
    printf("Updated queue list:\n");
    traverse(&queueList);

    // Free allocated memory
    while (list.head != NULL) {
        Student* temp = list.head;
        list.head = list.head->next;
        free(temp);
    }

    while (queueList.head != NULL) {
        Student* temp = queueList.head;
        queueList.head = queueList.head->next;
        free(temp);
    }

    return 0;
}