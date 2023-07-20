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

// Function to insert a node at the end of the queue (enqueue operation)
void insert_q(struct Node** head, struct Node* element) {
    if (*head == NULL) {
        *head = element;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = element;
    }
}

// Function to delete a node from the front of the queue (dequeue operation)
struct Node* delete_q(struct Node** head) {
    if (*head == NULL) {
        return NULL; // Queue is empty
    }

    struct Node* frontNode = *head;
    *head = (*head)->next;
    frontNode->next = NULL; // Disconnect the dequeued node from the list

    return frontNode;
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

    // Enqueue elements into the queue
    insert_q(&head, createNode(7));
    insert_q(&head, createNode(6));
    insert_q(&head, createNode(5));

    printf("Queue: ");
    printList(head);

    // Dequeue elements from the queue
    struct Node* deletedNode1 = delete_q(&head);
    struct Node* deletedNode2 = delete_q(&head);

    printf("Dequeued elements: %d, %d\n", deletedNode1->data, deletedNode2->data);

    // Free memory allocated for the list and the dequeued nodes
    freeList(head);
    free(deletedNode1);
    free(deletedNode2);

    return 0;
}