/*  Always insert elements at one end, and delete elements from the other end (first-in first-out QUEUE). 
    void insert_q (node **head, node *element)
    node delete_q (node **head) / Return the deleted node
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

// Function to insert a node at the front of the queue (enqueue operation)
void insert_q(struct Node** head, struct Node* element) {
    if (*head == NULL) {
        *head = element;
    } else {
        element->next = *head;
        *head = element;
    }
}

// Function to delete a node from the end of the queue (dequeue operation)
struct Node* delete_q(struct Node** head) {
    if (*head == NULL) {
        return NULL; // Queue is empty
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL; // Disconnect the last node from the list
    } else {
        *head = NULL; // If there was only one node, the queue becomes empty after deletion
    }

    return current;
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

    int n, data;
    printf("Enter the number of elements to enqueue :- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d :- ", i + 1);
        scanf("%d", &data);
        insert_q(&head, createNode(data));
    }

    printf("Queue: ");
    printList(head);

    // Dequeue elements from the queue
    struct Node* deletedNode1 = delete_q(&head);
    struct Node* deletedNode2 = delete_q(&head);

    if (deletedNode1 != NULL && deletedNode2 != NULL) {
        printf("Dequeued elements :- %d, %d\n", deletedNode1->data, deletedNode2->data);
        free(deletedNode1);
        free(deletedNode2);
    } else {
        printf("Queue is empty. No elements dequeued.\n");
    }

    // Free memory allocated for the list
    freeList(head);

    return 0;
}
