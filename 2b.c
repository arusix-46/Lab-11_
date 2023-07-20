/*  Insert an element in a linked list in sorted order. 
    The function will be called for every element to be inserted. 
    void insert_sorted (node **head, node *element);
*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list in sorted order
void insert_sorted(struct Node** head, struct Node* element) {
    if (*head == NULL || element->data < (*head)->data) {
        element->next = *head;
        *head = element;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < element->data) {
            current = current->next;
        }
        element->next = current->next;
        current->next = element;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list in sorted order
    insert_sorted(&head, createNode(3));
    insert_sorted(&head, createNode(1));
    insert_sorted(&head, createNode(5));
    insert_sorted(&head, createNode(2));
    insert_sorted(&head, createNode(4));

    printf("Sorted Linked List: ");
    printList(head);

    // Free memory allocated for the list
    freeList(head);

    return 0;
}