/*  Concatenate two given list into one big list. 
    node *concatenate (node *head1, node *head2)
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

// Function to append a node to the end of the list
void append(struct Node** head, struct Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;

    return head1;
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
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n, data;

    // Create the first linked list
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        append(&head1, createNode(data));
    }

    // Create the second linked list
    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        append(&head2, createNode(data));
    }

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    // Concatenate the two lists
    head1 = concatenate(head1, head2);

    printf("Concatenated List: ");
    printList(head1);

    // Free memory allocated for the lists
    freeList(head1);

    return 0;
}
